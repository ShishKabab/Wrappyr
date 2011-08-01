//===- ExportHeader.cpp ---------------------------------------------===//
//
//										 The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Example clang plugin which simply prints the names of all the top-level decls
// in the input file.
//
//===----------------------------------------------------------------------===//

#include <set>
#include <stack>

#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/AST.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/Support/raw_ostream.h"
using namespace clang;

namespace {

std::string accessAsString(AccessSpecifier as){
	if(as == AS_public)
		return "public";
	else if(as == AS_protected)
		return "protected";
	else if(as == AS_private)
		return "private";
	else
		return "unknown";
}

// std::string getFullName(Decl* D){
// 	const DeclContext* DC = D->getDeclContext();
// 	while(DC){
// 		llvm::errs() << DC << "\n";
// 		DC = DC->getParent();
// 	}
// 	return "";
// }

class ExportHeaderConsumer : public ASTConsumer {
public:
	ExportHeaderConsumer(){
		llvm::outs() << "<HeaderExport>\n";
	}

	~ExportHeaderConsumer(){
		llvm::outs() << "</HeaderExport>\n";
	}

	virtual void Initialize (ASTContext &Context){
		m_context = &Context;

// 		SourceManager& smgr = m_context->getSourceManager();
// 		for(SourceManager::fileinfo_iterator i = smgr.fileinfo_begin(), e = smgr.fileinfo_end(); i != e; ++i){
// 			const FileEntry* f = i->first;
//
// 			llvm::outs() << "<File id=\"" << f->getUID() << "\" path=\"" << f->getName() << "\">\n";
// 		}
	}

	virtual void HandleTopLevelDecl(DeclGroupRef DG) {
		for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; ++i) {
			const Decl *D = *i;

			HandleDecl(D);

// 			D->dumpXML(llvm::errs());

// 			if (const NamedDecl *ND = dyn_cast<NamedDecl>(D)){
// 				llvm::errs() << "top-level-decl: \"" << ND->getNameAsString() << "\"\n";
//
// 				if (const TagDecl *TD = dyn_cast<TagDecl>(ND)){
// 					llvm::errs() << "tag-decl: \"" << ND->getNameAsString() << "\"\n";
// 					if (TD->isClass()){
// 						llvm::errs() << TD->getNameAsString() << " is a class \n";
// 					} else {
// 						llvm::errs() << TD->getNameAsString() << " is not a class \n";
// 					}
// 				} else if(const TypeDecl *TpD = dyn_cast<TypeDecl>(ND)){
// 					llvm::errs() << "type-decl: \"" << ND->getNameAsString() << "\"\n";
// 				}
// 			}
		}
	}

	void HandleDecl(const Decl* D){
		if(const RecordDecl* RD = dyn_cast<RecordDecl>(D)){
			if(const CXXRecordDecl* cls = dyn_cast<CXXRecordDecl>(RD)){
				if(cls->isDependentType() || cls->getTemplateSpecializationKind() > 0 ||
					!cls->getDefinition() || (!cls->isClass() && !cls->isStruct()))
					return;
			}

			HandleRecord(RD);
		} else if(const FunctionDecl* FD = dyn_cast<FunctionDecl>(D))
			HandleFunction(FD);
		else if(const EnumDecl* ED = dyn_cast<EnumDecl>(D))
			HandleEnum(ED);
		else if(const NamespaceDecl* NsD = dyn_cast<NamespaceDecl>(D))
			HandleContextChildren(NsD);
	}

// 	virtual void HandleTagDeclDefinition(TagDecl* D){
// 		if(const CXXRecordDecl* cls = dyn_cast<CXXRecordDecl>(D)){
// 			if(cls->isDependentType() || cls->getTemplateSpecializationKind() > 0 || (!D->isClass() && !D->isStruct()))
// 				return;
//
// 			HandleClass(cls);
// 		} else if(const FunctionDecl* FD = dyn_cast<FunctionDecl>(D)){
// 			HandleFunction(FD);
// 		} else {
// 			llvm::outs() << D->getNameAsString() << " is not a class \n";
// 			llvm::errs() << "tag-decl: \"" << D->getNameAsString() << "\"\n";
// 		}
// 	}

	void HandleFunction(const FunctionDecl* FD){
		llvm::outs() << "<Function name=\"" << FD->getNameAsString() << "\">\n";

		HandleContext(FD);

		for(FunctionDecl::param_const_iterator pi = FD->param_begin(), pe = FD->param_end(); pi != pe; ++pi){
			const ParmVarDecl* PVD = *pi;

			HandleParmVar(PVD);
		}
		llvm::outs() << "<Returns>\n";
		HandleType(FD->getResultType());
		llvm::outs() << "</Returns>\n";

		llvm::outs() << "</Function> \n";
	}

	void HandleRecord(const RecordDecl* RD){
		const CXXRecordDecl* cls = dyn_cast<CXXRecordDecl>(RD);

		llvm::outs() << "<" << (cls ? "Class" : "Struct") << " "
			<< "id=\"" << (void*)RD << "\" "
			<< "name=\"" << RD->getNameAsString() << "\"";
		if(cls)
			llvm::outs() << " dynamic=\"" << cls->isDynamicClass() << "\"";
		llvm::outs() << ">\n";

		HandleContext(RD);

		if(cls){
			for(CXXRecordDecl::base_class_const_iterator i = cls->bases_begin(), e = cls->bases_end(); i != e; ++i){
				const CXXBaseSpecifier* baseSpec = i;
// 				llvm::outs() << "<Base id=\"" << i->getType().getTypePtr()->isStructureOrClassType() << "\n";
				if(const RecordType* baseType = dyn_cast<RecordType>(baseSpec->getType().getTypePtr())){
					if(const NamedDecl* base = dyn_cast<NamedDecl>(baseType->getDecl())){
						llvm::outs() << "<Base id=\"" << (void*)base
							<< "\" name=\"" << base->getNameAsString()
							<< "\" access=\"" << accessAsString(baseSpec->getAccessSpecifier())
							<< "\" />\n";
					}
				}
			}

			HandleMethods(cls);
		}

		for(RecordDecl::field_iterator i = RD->field_begin(), e = RD->field_end(); i != e; ++i){
			const FieldDecl* FD = (*i);

			HandleField(FD);
		}

		llvm::outs() << "</" << (cls ? "Class" : "Struct") << ">\n";

		HandleContextChildren(RD);
	}

	void HandleMethods(const CXXRecordDecl* cls){
		std::set<const CXXMethodDecl*> ctors;
		for(CXXRecordDecl::ctor_iterator i = cls->ctor_begin(), e = cls->ctor_end(); i != e; ++i)
			ctors.insert((*i));
		CXXMethodDecl* dtor = cls->getDestructor();

		for(CXXRecordDecl::method_iterator i = cls->method_begin(), e = cls->method_end(); i != e; ++i){
			const CXXMethodDecl* MD = *i;
			if(MD->getTemplatedKind() != FunctionDecl::TK_NonTemplate)
				continue;

			llvm::outs() << "<Method name=\"" << MD->getNameAsString() << "\" "
				<< "access=\"" << accessAsString(MD->getAccess()) << "\" "
				<< "virtual=\"" << MD->isVirtual() << "\" "
				<< "static=\"" << MD->isStatic() << "\" "
				<< "pure=\"" << MD->isPure() << "\" "
				<< "constructor=\"" << (ctors.find(MD) != ctors.end()) << "\" "
				<< "destructor=\"" << (MD == dtor) << "\">\n";

			for(FunctionDecl::param_const_iterator pi = MD->param_begin(), pe = MD->param_end(); pi != pe; ++pi){
				const ParmVarDecl* PVD = *pi;

				HandleParmVar(PVD);
			}
			llvm::outs() << "<Returns>\n";
			HandleType(MD->getResultType());
			llvm::outs() << "</Returns>\n";

			llvm::outs() << "</Method>\n";
		}
	}

	void HandleEnum(const EnumDecl* ED){
		llvm::outs() << "<Enum id=\"" << (void*)ED << "\" name=\"" << ED->getNameAsString() << "\">\n";

		HandleContext(ED);
		for(EnumDecl::enumerator_iterator i = ED->enumerator_begin(), e = ED->enumerator_end(); i != e; ++i){
			const EnumConstantDecl* ECD = *i;

			llvm::outs() << "<Constant name=\"" << ECD->getNameAsString() << "\" value=\"" << ECD->getInitVal().toString(10) << "\" />\n";
		}

		llvm::outs() << "</Enum>\n";
	}

	void HandleParmVar(const ParmVarDecl* parm){
		llvm::outs() << "<Argument name=\"" << parm->getNameAsString() << "\" "
			<< "optional=\"" << parm->hasDefaultArg()
			<< "\">\n";
		HandleType(parm->getOriginalType());
		llvm::outs() << "</Argument>\n";
	}

	void HandleType(const QualType oqtp){
		QualType qtp(oqtp.getDesugaredType(*m_context));

		const Type* tp = qtp.getTypePtr();
		llvm::outs() << "<Type const=\"" << qtp.isConstQualified() << "\" ";

		if(const PointerType* PT = dyn_cast<PointerType>(tp)){
			llvm::outs() << "type=\"pointer\">\n";
			HandleType(PT->getPointeeType());
		} else if(const ReferenceType* RT = dyn_cast<ReferenceType>(tp)){
			llvm::outs() << "type=\"reference\">\n";
			HandleType(RT->getPointeeType());
		} else if(const BuiltinType* BT = dyn_cast<BuiltinType>(tp)){
			llvm::outs() << "type=\"builtin\" name=\"" << BT->getName(m_langOpts) << "\">";
		} else if(const RecordType* RT = dyn_cast<RecordType>(tp)){
			llvm::outs() << "type=\"record\" id=\"" << ((void*)RT->getDecl()) << "\" name=\"" << RT->getDecl()->getNameAsString() << "\">";
		} else if(const EnumType* ET = dyn_cast<EnumType>(tp)){
			llvm::outs() << "type=\"enum\" id=\"" << ((void*)ET->getDecl()) << "\" name=\"" << ET->getDecl()->getNameAsString() << "\">";
		} else if(const FunctionType* FT = dyn_cast<FunctionType>(tp)){
			llvm::outs() << "type=\"function\">\n";

			if(const FunctionProtoType* FPT = dyn_cast<FunctionProtoType>(FT)){
				for(FunctionProtoType::arg_type_iterator i = FPT->arg_type_begin(), e = FPT->arg_type_end();
					i != e; ++i){
					llvm::outs() << "<Argument>\n";
					HandleType(*i);
					llvm::outs() << "</Argument>\n";
				}
			}

			llvm::outs() << "<Returns>\n";
			HandleType(FT->getResultType());
			llvm::outs() << "</Returns>\n";
		} else
			llvm::outs() << "type=\"unknown\">";

		llvm::outs() << "</Type>\n";
	}

	void HandleField(const FieldDecl* field){
		llvm::outs() << "<Field name=\"" << field->getNameAsString() << "\" "
			<< "access=\"" << accessAsString(field->getAccess()) << "\">\n";
		HandleType(field->getType());
		llvm::outs() << "</Field>\n";
	}

	void HandleContext(const Decl* D){
		PresumedLoc PLoc = m_context->getSourceManager().getPresumedLoc(D->getLocation());

		const NamedDecl* firstNS = 0;
		const NamedDecl* firstClass = 0;
		std::stack<const NamedDecl*> namespaces;
		std::stack<const NamedDecl*> classes;
		const DeclContext* DC = D->getDeclContext();
		while(DC){
			if(const NamespaceDecl* NsD = dyn_cast<NamespaceDecl>(DC)){
				if(!firstNS)
					firstNS = NsD;
				namespaces.push(NsD);
			}
			else if(const CXXRecordDecl* cls = dyn_cast<CXXRecordDecl>(DC)){
				if(!firstClass)
					firstClass = cls;
				classes.push(cls);
			}
			DC = DC->getParent();
		}

		llvm::outs() << "<Context>\n";
		llvm::outs() << "<Physical file=\"" << PLoc.getFilename() << "\" "
			<< "line=\"" << PLoc.getLine() << "\" "
			<< "column=\"" << PLoc.getColumn() << "\" />\n";

		if(!namespaces.empty()){
			llvm::outs() << "<Namespace id=\"" << (void*)firstNS << "\">";
			while(!namespaces.empty()){
				llvm::outs() << namespaces.top()->getNameAsString();
				if(namespaces.size() > 1)
					llvm::outs() << "::";
				namespaces.pop();
			}
			llvm::outs() << "</Namespace>\n";
		}

		if(!classes.empty()){
			llvm::outs() << "<Class id=\"" << (void*)firstClass << "\">";
			while(!classes.empty()){
				llvm::outs() << classes.top()->getNameAsString();
				if(classes.size() > 1)
					llvm::outs() << "::";
				classes.pop();
			}
			llvm::outs() << "</Class>\n";
		}

		llvm::outs() << "</Context>\n";
	}

	void HandleContextChildren(const DeclContext* DC){
		bool isClass = dyn_cast<CXXRecordDecl>(DC);
		for(DeclContext::decl_iterator i = DC->decls_begin(), e = DC->decls_end(); i != e; ++i){
			const Decl* D = *i;

			if(isClass && !dyn_cast<CXXRecordDecl>(D))
				continue;

			HandleDecl(*i);
		}
	}
private:
	LangOptions m_langOpts;
	ASTContext* m_context;
};

class ExportHeaderAction : public PluginASTAction {
protected:
	ASTConsumer *CreateASTConsumer(CompilerInstance &CI, llvm::StringRef) {
		return new ExportHeaderConsumer();
	}

	bool ParseArgs(const CompilerInstance &CI, const std::vector<std::string>& args) {
		for (unsigned i = 0, e = args.size(); i != e; ++i) {
			llvm::errs() << "ExportHeader arg = " << args[i] << "\n";

			// Example error handling.
			if (args[i] == "-an-error") {
				Diagnostic &D = CI.getDiagnostics();
				unsigned DiagID = D.getCustomDiagID(
					Diagnostic::Error, "invalid argument '" + args[i] + "'");
				D.Report(DiagID);
				return false;
			}
		}
		if (args.size() && args[0] == "help")
			PrintHelp(llvm::errs());

		return true;
	}
	void PrintHelp(llvm::raw_ostream& ros) {
		ros << "Help for ExportHeader plugin goes here\n";
	}

};

}

static FrontendPluginRegistry::Add<ExportHeaderAction>
X("export-hdr", "export classes and functions to XML");

// C: ../../bin/clang -cc1 -load ../../lib/ExportHeader.so -plugin export-hdr -I/usr/include/i386-linux-gnu/ /usr/include/mysql/mysql.h
// C++: ../../bin/clang++ -cc1 -load ../../lib/ExportHeader.so -plugin export-hdr -x c++ /usr/local/include/Box2D/Box2D.h