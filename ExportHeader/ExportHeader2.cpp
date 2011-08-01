//===- ExportHeader.cpp ---------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
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

#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/AST.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/Support/raw_ostream.h"
using namespace clang;

namespace {

class ExportHeaderConsumer : public ASTConsumer {
public:
//   virtual void HandleTopLevelDecl(DeclGroupRef DG) {
//     for (DeclGroupRef::iterator i = DG.begin(), e = DG.end(); i != e; ++i) {
//       const Decl *D = *i;
//       if (const NamedDecl *ND = dyn_cast<NamedDecl>(D))
//         llvm::errs() << "top-level-decl: \"" << ND->getNameAsString() << "\"\n";
//     }
//   }
  virtual void HandleTagDeclDefinition(TagDecl* D){
	  if (D->isClass()){
		  if(const RecordDecl* RD = dyn_cast<RecordDecl>(D)){
			  for(RecordDecl::field_iterator i = RD->field_begin(), e = RD->field_end(); i != e; ++i){
				  llvm::errs() << "field-decl: \"" << (*i)->getNameAsString() << "\"\n";
			  }
		  }
	  } else
		llvm::errs() << "tag-decl: \"" << D->getNameAsString() << "\"\n";
  }
};

class ExportHeaderAction : public PluginASTAction {
protected:
  ASTConsumer *CreateASTConsumer(CompilerInstance &CI, llvm::StringRef) {
    return new ExportHeaderConsumer();
  }

  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string>& args) {
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
