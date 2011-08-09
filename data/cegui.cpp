#include <CEGUI.h>
#include "cegui.h"


//
// Begin class 'CEGUI::RenderedStringImageComponent'
//
void CEGUI__RenderedStringImageComponent__Destroy(void* cls){
	delete (CEGUI::RenderedStringImageComponent*)cls;
}
void CEGUI__RenderedStringImageComponent_draw(void* cls, void* a, void* b, void* c, void* d, float e, float f){
	((CEGUI::RenderedStringImageComponent*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((float)e), ((float)f));
}
void CEGUI__RenderedStringImageComponent_setImage0(void* cls, void* a, void* b){
	((CEGUI::RenderedStringImageComponent*)cls)->setImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__RenderedStringImageComponent_setImage1(void* cls, void* a){
	((CEGUI::RenderedStringImageComponent*)cls)->setImage(((CEGUI::Image*)a));
}
void* CEGUI__RenderedStringImageComponent_clone(void* cls){
	return ((CEGUI::RenderedStringImageComponent*)cls)->clone();
}
void* CEGUI__RenderedStringImageComponent_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::RenderedStringImageComponent*)cls)->getPixelSize());
}
bool CEGUI__RenderedStringImageComponent_canSplit(void* cls){
	return ((CEGUI::RenderedStringImageComponent*)cls)->canSplit();
}
void* CEGUI__RenderedStringImageComponent_getSize(void* cls){
	return const_cast<CEGUI::Size*>(&((CEGUI::RenderedStringImageComponent*)cls)->getSize());
}
void* CEGUI__RenderedStringImageComponent_split(void* cls, float a, bool b){
	return ((CEGUI::RenderedStringImageComponent*)cls)->split(((float)a), ((bool)b));
}
void* CEGUI__RenderedStringImageComponent_getColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::RenderedStringImageComponent*)cls)->getColours());
}
unsigned int CEGUI__RenderedStringImageComponent_getSpaceCount(void* cls){
	return ((CEGUI::RenderedStringImageComponent*)cls)->getSpaceCount();
}
void* CEGUI__RenderedStringImageComponent_getImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::RenderedStringImageComponent*)cls)->getImage());
}
void CEGUI__RenderedStringImageComponent_setSize(void* cls, void* a){
	((CEGUI::RenderedStringImageComponent*)cls)->setSize(*((CEGUI::Size*)a));
}
void CEGUI__RenderedStringImageComponent_setColours0(void* cls, void* a){
	((CEGUI::RenderedStringImageComponent*)cls)->setColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__RenderedStringImageComponent_setColours1(void* cls, void* a){
	((CEGUI::RenderedStringImageComponent*)cls)->setColours(*((CEGUI::colour*)a));
}

//
// Begin class 'CEGUI::BoolInterpolator'
//
void CEGUI__BoolInterpolator__Destroy(void* cls){
	delete (CEGUI::BoolInterpolator*)cls;
}
void* CEGUI__BoolInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::BoolInterpolator*)cls)->getType());
}
void* CEGUI__BoolInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::BoolInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__BoolInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::BoolInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__BoolInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::BoolInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::FontDim'
//
void CEGUI__FontDim__Destroy(void* cls){
	delete (CEGUI::FontDim*)cls;
}

//
// Begin class 'CEGUI::MouseCursor'
//
void* CEGUI__MouseCursor__Create(){
	return new CEGUI::MouseCursor();
}
void CEGUI__MouseCursor__Destroy(void* cls){
	delete (CEGUI::MouseCursor*)cls;
}
void CEGUI__MouseCursor_invalidate(void* cls){
	((CEGUI::MouseCursor*)cls)->invalidate();
}
void CEGUI__MouseCursor_show(void* cls){
	((CEGUI::MouseCursor*)cls)->show();
}
void CEGUI__MouseCursor_setInitialMousePosition(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setInitialMousePosition(*((CEGUI::Vector2*)a));
}
void CEGUI__MouseCursor_offsetPosition(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->offsetPosition(*((CEGUI::Vector2*)a));
}
void CEGUI__MouseCursor_setExplicitRenderSize(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setExplicitRenderSize(*((CEGUI::Size*)a));
}
void CEGUI__MouseCursor_hide(void* cls){
	((CEGUI::MouseCursor*)cls)->hide();
}
void CEGUI__MouseCursor_draw(void* cls){
	((CEGUI::MouseCursor*)cls)->draw();
}
void* CEGUI__MouseCursor_getUnifiedConstraintArea(void* cls){
	return const_cast<CEGUI::URect*>(&((CEGUI::MouseCursor*)cls)->getUnifiedConstraintArea());
}
void CEGUI__MouseCursor_setUnifiedConstraintArea(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setUnifiedConstraintArea(((CEGUI::URect*)a));
}
void* CEGUI__MouseCursor_getDisplayIndependantPosition(void* cls){
	return new CEGUI::Vector2(((CEGUI::MouseCursor*)cls)->getDisplayIndependantPosition());
}
void CEGUI__MouseCursor_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
void CEGUI__MouseCursor_setPosition(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setPosition(*((CEGUI::Vector2*)a));
}
void* CEGUI__MouseCursor_getPosition(void* cls){
	return new CEGUI::Vector2(((CEGUI::MouseCursor*)cls)->getPosition());
}
void CEGUI__MouseCursor_setConstraintArea(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setConstraintArea(((CEGUI::Rect*)a));
}
void* CEGUI__MouseCursor_getConstraintArea(void* cls){
	return new CEGUI::Rect(((CEGUI::MouseCursor*)cls)->getConstraintArea());
}
void* CEGUI__MouseCursor_getSingletonPtr(void* cls){
	return ((CEGUI::MouseCursor*)cls)->getSingletonPtr();
}
void CEGUI__MouseCursor_setImage0(void* cls, void* a, void* b){
	((CEGUI::MouseCursor*)cls)->setImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__MouseCursor_setImage1(void* cls, void* a){
	((CEGUI::MouseCursor*)cls)->setImage(((CEGUI::Image*)a));
}
void* CEGUI__MouseCursor_getSingleton(void* cls){
	return &((CEGUI::MouseCursor*)cls)->getSingleton();
}
bool CEGUI__MouseCursor_isVisible(void* cls){
	return ((CEGUI::MouseCursor*)cls)->isVisible();
}
void* CEGUI__MouseCursor_getImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::MouseCursor*)cls)->getImage());
}
void CEGUI__MouseCursor_setVisible(void* cls, bool a){
	((CEGUI::MouseCursor*)cls)->setVisible(((bool)a));
}
void* CEGUI__MouseCursor_getExplicitRenderSize(void* cls){
	return const_cast<CEGUI::Size*>(&((CEGUI::MouseCursor*)cls)->getExplicitRenderSize());
}

//
// Begin class 'CEGUI::ImagesetManager'
//
void* CEGUI__ImagesetManager__Create(){
	return new CEGUI::ImagesetManager();
}
void CEGUI__ImagesetManager__Destroy(void* cls){
	delete (CEGUI::ImagesetManager*)cls;
}
void* CEGUI__ImagesetManager_create(void* cls, void* a, void* b, unsigned int c){
	return &((CEGUI::ImagesetManager*)cls)->create(*((CEGUI::String*)a), *((CEGUI::Texture*)b), ((CEGUI::XMLResourceExistsAction)c));
}
void CEGUI__ImagesetManager_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::ImagesetManager*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
void* CEGUI__ImagesetManager_createFromImageFile(void* cls, void* a, void* b, void* c, unsigned int d){
	return &((CEGUI::ImagesetManager*)cls)->createFromImageFile(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((CEGUI::XMLResourceExistsAction)d));
}

//
// Begin class 'CEGUI::Menubar'
//
void CEGUI__Menubar__Destroy(void* cls){
	delete (CEGUI::Menubar*)cls;
}

//
// Begin class 'CEGUI::NamedArea'
//
void* CEGUI__NamedArea__Create0(){
	return new CEGUI::NamedArea();
}
void* CEGUI__NamedArea__Create1(void* a){
	return new CEGUI::NamedArea(*((CEGUI::String*)a));
}
void CEGUI__NamedArea__Destroy(void* cls){
	delete (CEGUI::NamedArea*)cls;
}
void* CEGUI__NamedArea_getArea(void* cls){
	return const_cast<CEGUI::ComponentArea*>(&((CEGUI::NamedArea*)cls)->getArea());
}
void* CEGUI__NamedArea_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::NamedArea*)cls)->getName());
}
void CEGUI__NamedArea_setArea(void* cls, void* a){
	((CEGUI::NamedArea*)cls)->setArea(*((CEGUI::ComponentArea*)a));
}
void CEGUI__NamedArea_writeXMLToStream(void* cls, void* a){
	((CEGUI::NamedArea*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}

//
// Begin class 'CEGUI::PropertyDefinition'
//
void CEGUI__PropertyDefinition__Destroy(void* cls){
	delete (CEGUI::PropertyDefinition*)cls;
}
void CEGUI__PropertyDefinition_set(void* cls, void* a, void* b){
	((CEGUI::PropertyDefinition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__PropertyDefinition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyDefinition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::colour'
//
void* CEGUI__colour__Create0(){
	return new CEGUI::colour();
}
void* CEGUI__colour__Create1(void* a){
	return new CEGUI::colour(*((CEGUI::colour*)a));
}
void* CEGUI__colour__Create2(float a, float b, float c, float d){
	return new CEGUI::colour(((float)a), ((float)b), ((float)c), ((float)d));
}
void* CEGUI__colour__Create3(unsigned int a){
	return new CEGUI::colour(((unsigned int)a));
}
void CEGUI__colour__Destroy(void* cls){
	delete (CEGUI::colour*)cls;
}
void CEGUI__colour_invertColourWithAlpha(void* cls){
	((CEGUI::colour*)cls)->invertColourWithAlpha();
}
void CEGUI__colour_setBlue(void* cls, float a){
	((CEGUI::colour*)cls)->setBlue(((float)a));
}
float CEGUI__colour_getHue(void* cls){
	return ((CEGUI::colour*)cls)->getHue();
}
float CEGUI__colour_getLumination(void* cls){
	return ((CEGUI::colour*)cls)->getLumination();
}
void CEGUI__colour_setARGB(void* cls, unsigned int a){
	((CEGUI::colour*)cls)->setARGB(((unsigned int)a));
}
unsigned int CEGUI__colour_getARGB(void* cls){
	return ((CEGUI::colour*)cls)->getARGB();
}
void CEGUI__colour_setRGB0(void* cls, float a, float b, float c){
	((CEGUI::colour*)cls)->setRGB(((float)a), ((float)b), ((float)c));
}
void CEGUI__colour_setRGB1(void* cls, void* a){
	((CEGUI::colour*)cls)->setRGB(*((CEGUI::colour*)a));
}
void CEGUI__colour_setGreen(void* cls, float a){
	((CEGUI::colour*)cls)->setGreen(((float)a));
}
void CEGUI__colour_set(void* cls, float a, float b, float c, float d){
	((CEGUI::colour*)cls)->set(((float)a), ((float)b), ((float)c), ((float)d));
}
void CEGUI__colour_setAlpha(void* cls, float a){
	((CEGUI::colour*)cls)->setAlpha(((float)a));
}
float CEGUI__colour_getGreen(void* cls){
	return ((CEGUI::colour*)cls)->getGreen();
}
float CEGUI__colour_getBlue(void* cls){
	return ((CEGUI::colour*)cls)->getBlue();
}
float CEGUI__colour_getAlpha(void* cls){
	return ((CEGUI::colour*)cls)->getAlpha();
}
float CEGUI__colour_getSaturation(void* cls){
	return ((CEGUI::colour*)cls)->getSaturation();
}
void CEGUI__colour_setRed(void* cls, float a){
	((CEGUI::colour*)cls)->setRed(((float)a));
}
void CEGUI__colour_invertColour(void* cls){
	((CEGUI::colour*)cls)->invertColour();
}
void CEGUI__colour_setHSL(void* cls, float a, float b, float c, float d){
	((CEGUI::colour*)cls)->setHSL(((float)a), ((float)b), ((float)c), ((float)d));
}
float CEGUI__colour_getRed(void* cls){
	return ((CEGUI::colour*)cls)->getRed();
}

//
// Begin class 'CEGUI::DragContainer'
//
void* CEGUI__DragContainer__Create(void* a, void* b){
	return new CEGUI::DragContainer(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__DragContainer__Destroy(void* cls){
	delete (CEGUI::DragContainer*)cls;
}
void* CEGUI__DragContainer_getDragCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::DragContainer*)cls)->getDragCursorImage());
}
void* CEGUI__DragContainer_getFixedDragOffset(void* cls){
	return const_cast<CEGUI::UVector2*>(&((CEGUI::DragContainer*)cls)->getFixedDragOffset());
}
void CEGUI__DragContainer_setDraggingEnabled(void* cls, bool a){
	((CEGUI::DragContainer*)cls)->setDraggingEnabled(((bool)a));
}
bool CEGUI__DragContainer_pickUp(void* cls, bool a){
	return ((CEGUI::DragContainer*)cls)->pickUp(((bool)a));
}
bool CEGUI__DragContainer_isUsingFixedDragOffset(void* cls){
	return ((CEGUI::DragContainer*)cls)->isUsingFixedDragOffset();
}
void CEGUI__DragContainer_setDragCursorImage0(void* cls, void* a){
	((CEGUI::DragContainer*)cls)->setDragCursorImage(((CEGUI::Image*)a));
}
void CEGUI__DragContainer_setDragCursorImage1(void* cls, unsigned int a){
	((CEGUI::DragContainer*)cls)->setDragCursorImage(((CEGUI::MouseCursorImage)a));
}
void CEGUI__DragContainer_setDragCursorImage2(void* cls, void* a, void* b){
	((CEGUI::DragContainer*)cls)->setDragCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__DragContainer_setUsingFixedDragOffset(void* cls, bool a){
	((CEGUI::DragContainer*)cls)->setUsingFixedDragOffset(((bool)a));
}
bool CEGUI__DragContainer_isBeingDragged(void* cls){
	return ((CEGUI::DragContainer*)cls)->isBeingDragged();
}
bool CEGUI__DragContainer_isStickyModeEnabled(void* cls){
	return ((CEGUI::DragContainer*)cls)->isStickyModeEnabled();
}
float CEGUI__DragContainer_getDragAlpha(void* cls){
	return ((CEGUI::DragContainer*)cls)->getDragAlpha();
}
void CEGUI__DragContainer_setFixedDragOffset(void* cls, void* a){
	((CEGUI::DragContainer*)cls)->setFixedDragOffset(*((CEGUI::UVector2*)a));
}
void CEGUI__DragContainer_setPixelDragThreshold(void* cls, float a){
	((CEGUI::DragContainer*)cls)->setPixelDragThreshold(((float)a));
}
float CEGUI__DragContainer_getPixelDragThreshold(void* cls){
	return ((CEGUI::DragContainer*)cls)->getPixelDragThreshold();
}
void* CEGUI__DragContainer_getCurrentDropTarget(void* cls){
	return ((CEGUI::DragContainer*)cls)->getCurrentDropTarget();
}
bool CEGUI__DragContainer_isDraggingEnabled(void* cls){
	return ((CEGUI::DragContainer*)cls)->isDraggingEnabled();
}
void CEGUI__DragContainer_setStickyModeEnabled(void* cls, bool a){
	((CEGUI::DragContainer*)cls)->setStickyModeEnabled(((bool)a));
}
void CEGUI__DragContainer_setDragAlpha(void* cls, float a){
	((CEGUI::DragContainer*)cls)->setDragAlpha(((float)a));
}
void CEGUI__DragContainer_getRenderingContext_impl(void* cls, void* a){
	((CEGUI::DragContainer*)cls)->getRenderingContext_impl(*((CEGUI::RenderingContext*)a));
}

//
// Begin class 'CEGUI::DragDropEventArgs'
//
void* CEGUI__DragDropEventArgs__Create(void* a){
	return new CEGUI::DragDropEventArgs(((CEGUI::Window*)a));
}
void CEGUI__DragDropEventArgs__Destroy(void* cls){
	delete (CEGUI::DragDropEventArgs*)cls;
}

//
// Begin class 'CEGUI::TextComponent'
//
void CEGUI__TextComponent__Destroy(void* cls){
	delete (CEGUI::TextComponent*)cls;
}
void* CEGUI__TextComponent_getTextPropertySource(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TextComponent*)cls)->getTextPropertySource());
}
unsigned int CEGUI__TextComponent_getVerticalFormatting(void* cls){
	return ((CEGUI::TextComponent*)cls)->getVerticalFormatting();
}
void* CEGUI__TextComponent_getFont(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TextComponent*)cls)->getFont());
}
bool CEGUI__TextComponent_isFontFetchedFromProperty(void* cls){
	return ((CEGUI::TextComponent*)cls)->isFontFetchedFromProperty();
}
void CEGUI__TextComponent_setText(void* cls, void* a){
	((CEGUI::TextComponent*)cls)->setText(*((CEGUI::String*)a));
}
void CEGUI__TextComponent_setTextPropertySource(void* cls, void* a){
	((CEGUI::TextComponent*)cls)->setTextPropertySource(*((CEGUI::String*)a));
}
void* CEGUI__TextComponent_getText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TextComponent*)cls)->getText());
}
void* CEGUI__TextComponent_getTextVisual(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TextComponent*)cls)->getTextVisual());
}
void CEGUI__TextComponent_setFontPropertySource(void* cls, void* a){
	((CEGUI::TextComponent*)cls)->setFontPropertySource(*((CEGUI::String*)a));
}
void* CEGUI__TextComponent_getFontPropertySource(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TextComponent*)cls)->getFontPropertySource());
}
void CEGUI__TextComponent_setVerticalFormatting(void* cls, unsigned int a){
	((CEGUI::TextComponent*)cls)->setVerticalFormatting(((CEGUI::VerticalTextFormatting)a));
}
void CEGUI__TextComponent_writeXMLToStream(void* cls, void* a){
	((CEGUI::TextComponent*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__TextComponent_setFont(void* cls, void* a){
	((CEGUI::TextComponent*)cls)->setFont(*((CEGUI::String*)a));
}
bool CEGUI__TextComponent_isTextFetchedFromProperty(void* cls){
	return ((CEGUI::TextComponent*)cls)->isTextFetchedFromProperty();
}
unsigned int CEGUI__TextComponent_getHorizontalFormatting(void* cls){
	return ((CEGUI::TextComponent*)cls)->getHorizontalFormatting();
}
void CEGUI__TextComponent_setHorizontalFormatting(void* cls, unsigned int a){
	((CEGUI::TextComponent*)cls)->setHorizontalFormatting(((CEGUI::HorizontalTextFormatting)a));
}

//
// Begin class 'CEGUI::LayerSpecification'
//
void* CEGUI__LayerSpecification__Create(unsigned int a){
	return new CEGUI::LayerSpecification(((unsigned int)a));
}
void CEGUI__LayerSpecification__Destroy(void* cls){
	delete (CEGUI::LayerSpecification*)cls;
}
void CEGUI__LayerSpecification_clearSectionSpecifications(void* cls){
	((CEGUI::LayerSpecification*)cls)->clearSectionSpecifications();
}
void CEGUI__LayerSpecification_addSectionSpecification(void* cls, void* a){
	((CEGUI::LayerSpecification*)cls)->addSectionSpecification(*((CEGUI::SectionSpecification*)a));
}
void CEGUI__LayerSpecification_writeXMLToStream(void* cls, void* a){
	((CEGUI::LayerSpecification*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__LayerSpecification_render0(void* cls, void* a, void* b, void* c, bool d){
	((CEGUI::LayerSpecification*)cls)->render(*((CEGUI::Window*)a), ((CEGUI::ColourRect*)b), ((CEGUI::Rect*)c), ((bool)d));
}
void CEGUI__LayerSpecification_render1(void* cls, void* a, void* b, void* c, void* d, bool e){
	((CEGUI::LayerSpecification*)cls)->render(*((CEGUI::Window*)a), *((CEGUI::Rect*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((bool)e));
}
unsigned int CEGUI__LayerSpecification_getLayerPriority(void* cls){
	return ((CEGUI::LayerSpecification*)cls)->getLayerPriority();
}

//
// Begin class 'CEGUI::GroupBox'
//
void* CEGUI__GroupBox__Create(void* a, void* b){
	return new CEGUI::GroupBox(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__GroupBox__Destroy(void* cls){
	delete (CEGUI::GroupBox*)cls;
}
bool CEGUI__GroupBox_drawAroundWidget0(void* cls, void* a){
	return ((CEGUI::GroupBox*)cls)->drawAroundWidget(((CEGUI::Window*)a));
}
bool CEGUI__GroupBox_drawAroundWidget1(void* cls, void* a){
	return ((CEGUI::GroupBox*)cls)->drawAroundWidget(*((CEGUI::String*)a));
}
void* CEGUI__GroupBox_getContentPane(void* cls){
	return ((CEGUI::GroupBox*)cls)->getContentPane();
}
bool CEGUI__GroupBox_testClassName_impl(void* cls, void* a){
	return ((CEGUI::GroupBox*)cls)->testClassName_impl(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::PropertySet'
//
void* CEGUI__PropertySet__Create(){
	return new CEGUI::PropertySet();
}
void CEGUI__PropertySet__Destroy(void* cls){
	delete (CEGUI::PropertySet*)cls;
}
bool CEGUI__PropertySet_isPropertyPresent(void* cls, void* a){
	return ((CEGUI::PropertySet*)cls)->isPropertyPresent(*((CEGUI::String*)a));
}
void CEGUI__PropertySet_clearProperties(void* cls){
	((CEGUI::PropertySet*)cls)->clearProperties();
}
void* CEGUI__PropertySet_getProperty(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertySet*)cls)->getProperty(*((CEGUI::String*)a)));
}
void CEGUI__PropertySet_addProperty(void* cls, void* a){
	((CEGUI::PropertySet*)cls)->addProperty(((CEGUI::Property*)a));
}
bool CEGUI__PropertySet_isPropertyDefault(void* cls, void* a){
	return ((CEGUI::PropertySet*)cls)->isPropertyDefault(*((CEGUI::String*)a));
}
void* CEGUI__PropertySet_getPropertyHelp(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::PropertySet*)cls)->getPropertyHelp(*((CEGUI::String*)a)));
}
void* CEGUI__PropertySet_getPropertyDefault(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertySet*)cls)->getPropertyDefault(*((CEGUI::String*)a)));
}
void CEGUI__PropertySet_removeProperty(void* cls, void* a){
	((CEGUI::PropertySet*)cls)->removeProperty(*((CEGUI::String*)a));
}
void CEGUI__PropertySet_setProperty(void* cls, void* a, void* b){
	((CEGUI::PropertySet*)cls)->setProperty(*((CEGUI::String*)a), *((CEGUI::String*)b));
}

//
// Begin class 'CEGUI::PropertyDefinitionBase'
//
void CEGUI__PropertyDefinitionBase__Destroy(void* cls){
	delete (CEGUI::PropertyDefinitionBase*)cls;
}
void CEGUI__PropertyDefinitionBase_set(void* cls, void* a, void* b){
	((CEGUI::PropertyDefinitionBase*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void CEGUI__PropertyDefinitionBase_writeXMLToStream(void* cls, void* a){
	((CEGUI::PropertyDefinitionBase*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}

//
// Begin class 'CEGUI::UVector2Interpolator'
//
void CEGUI__UVector2Interpolator__Destroy(void* cls){
	delete (CEGUI::UVector2Interpolator*)cls;
}
void* CEGUI__UVector2Interpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::UVector2Interpolator*)cls)->getType());
}
void* CEGUI__UVector2Interpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::UVector2Interpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__UVector2Interpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UVector2Interpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__UVector2Interpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UVector2Interpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::ImageDim'
//
void CEGUI__ImageDim__Destroy(void* cls){
	delete (CEGUI::ImageDim*)cls;
}
void CEGUI__ImageDim_setSourceDimension(void* cls, unsigned int a){
	((CEGUI::ImageDim*)cls)->setSourceDimension(((CEGUI::DimensionType)a));
}
void CEGUI__ImageDim_setSourceImage(void* cls, void* a, void* b){
	((CEGUI::ImageDim*)cls)->setSourceImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}

//
// Begin class 'CEGUI::WindowManager'
//
void* CEGUI__WindowManager__Create(){
	return new CEGUI::WindowManager();
}
void CEGUI__WindowManager__Destroy(void* cls){
	delete (CEGUI::WindowManager*)cls;
}
bool CEGUI__WindowManager_isWindowPresent(void* cls, void* a){
	return ((CEGUI::WindowManager*)cls)->isWindowPresent(*((CEGUI::String*)a));
}
void* CEGUI__WindowManager_createWindow(void* cls, void* a, void* b){
	return ((CEGUI::WindowManager*)cls)->createWindow(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__WindowManager_saveWindowLayout0(void* cls, void* a, void* b, bool c){
	((CEGUI::WindowManager*)cls)->saveWindowLayout(*((CEGUI::String*)a), *((CEGUI::String*)b), ((bool)c));
}
void CEGUI__WindowManager_saveWindowLayout1(void* cls, void* a, void* b, bool c){
	((CEGUI::WindowManager*)cls)->saveWindowLayout(*((CEGUI::Window*)a), *((CEGUI::String*)b), ((bool)c));
}
void CEGUI__WindowManager_cleanDeadPool(void* cls){
	((CEGUI::WindowManager*)cls)->cleanDeadPool();
}
bool CEGUI__WindowManager_isLocked(void* cls){
	return ((CEGUI::WindowManager*)cls)->isLocked();
}
void CEGUI__WindowManager_lock(void* cls){
	((CEGUI::WindowManager*)cls)->lock();
}
void CEGUI__WindowManager_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::WindowManager*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
void CEGUI__WindowManager_renameWindow0(void* cls, void* a, void* b){
	((CEGUI::WindowManager*)cls)->renameWindow(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__WindowManager_renameWindow1(void* cls, void* a, void* b){
	((CEGUI::WindowManager*)cls)->renameWindow(((CEGUI::Window*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowManager_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowManager*)cls)->getDefaultResourceGroup());
}
bool CEGUI__WindowManager_isDeadPoolEmpty(void* cls){
	return ((CEGUI::WindowManager*)cls)->isDeadPoolEmpty();
}
void CEGUI__WindowManager_unlock(void* cls){
	((CEGUI::WindowManager*)cls)->unlock();
}
void CEGUI__WindowManager_destroyAllWindows(void* cls){
	((CEGUI::WindowManager*)cls)->destroyAllWindows();
}
void* CEGUI__WindowManager_getWindow(void* cls, void* a){
	return ((CEGUI::WindowManager*)cls)->getWindow(*((CEGUI::String*)a));
}
void CEGUI__WindowManager_DEBUG_dumpWindowNames(void* cls, void* a){
	((CEGUI::WindowManager*)cls)->DEBUG_dumpWindowNames(*((CEGUI::String*)a));
}
void CEGUI__WindowManager_destroyWindow0(void* cls, void* a){
	((CEGUI::WindowManager*)cls)->destroyWindow(((CEGUI::Window*)a));
}
void CEGUI__WindowManager_destroyWindow1(void* cls, void* a){
	((CEGUI::WindowManager*)cls)->destroyWindow(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::XMLHandler'
//
void* CEGUI__XMLHandler__Create(){
	return new CEGUI::XMLHandler();
}
void CEGUI__XMLHandler__Destroy(void* cls){
	delete (CEGUI::XMLHandler*)cls;
}
void CEGUI__XMLHandler_elementStart(void* cls, void* a, void* b){
	((CEGUI::XMLHandler*)cls)->elementStart(*((CEGUI::String*)a), *((CEGUI::XMLAttributes*)b));
}
void CEGUI__XMLHandler_text(void* cls, void* a){
	((CEGUI::XMLHandler*)cls)->text(*((CEGUI::String*)a));
}
void CEGUI__XMLHandler_elementEnd(void* cls, void* a){
	((CEGUI::XMLHandler*)cls)->elementEnd(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::String::const_iterator'
//
void* CEGUI__String__const_iterator__Create0(){
	return new CEGUI::String::const_iterator();
}
void* CEGUI__String__const_iterator__Create1(unsigned int* a){
	return new CEGUI::String::const_iterator(((unsigned int*)a));
}
void* CEGUI__String__const_iterator__Create2(void* a){
	return new CEGUI::String::const_iterator(*((CEGUI::String::iterator*)a));
}
void* CEGUI__String__const_iterator__Create3(void* a){
	return new CEGUI::String::const_iterator(*((CEGUI::String::const_iterator*)a));
}
void CEGUI__String__const_iterator__Destroy(void* cls){
	delete (CEGUI::String::const_iterator*)cls;
}

//
// Begin class 'CEGUI::String::iterator'
//
void* CEGUI__String__iterator__Create0(){
	return new CEGUI::String::iterator();
}
void* CEGUI__String__iterator__Create1(unsigned int* a){
	return new CEGUI::String::iterator(((unsigned int*)a));
}
void* CEGUI__String__iterator__Create2(void* a){
	return new CEGUI::String::iterator(*((CEGUI::String::iterator*)a));
}
void CEGUI__String__iterator__Destroy(void* cls){
	delete (CEGUI::String::iterator*)cls;
}

//
// Begin class 'CEGUI::ListHeaderSegment'
//
void* CEGUI__ListHeaderSegment__Create(void* a, void* b){
	return new CEGUI::ListHeaderSegment(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ListHeaderSegment__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegment*)cls;
}
unsigned int CEGUI__ListHeaderSegment_getSortDirection(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->getSortDirection();
}
void* CEGUI__ListHeaderSegment_getMovingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::ListHeaderSegment*)cls)->getMovingCursorImage());
}
bool CEGUI__ListHeaderSegment_isSegmentHovering(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isSegmentHovering();
}
void* CEGUI__ListHeaderSegment_getSizingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::ListHeaderSegment*)cls)->getSizingCursorImage());
}
void CEGUI__ListHeaderSegment_setSortDirection(void* cls, unsigned int a){
	((CEGUI::ListHeaderSegment*)cls)->setSortDirection(((CEGUI::ListHeaderSegment::SortDirection)a));
}
void CEGUI__ListHeaderSegment_setDragMovingEnabled(void* cls, bool a){
	((CEGUI::ListHeaderSegment*)cls)->setDragMovingEnabled(((bool)a));
}
void CEGUI__ListHeaderSegment_setClickable(void* cls, bool a){
	((CEGUI::ListHeaderSegment*)cls)->setClickable(((bool)a));
}
void CEGUI__ListHeaderSegment_setMovingCursorImage0(void* cls, void* a){
	((CEGUI::ListHeaderSegment*)cls)->setMovingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__ListHeaderSegment_setMovingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegment*)cls)->setMovingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__ListHeaderSegment_isSegmentPushed(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isSegmentPushed();
}
bool CEGUI__ListHeaderSegment_isClickable(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isClickable();
}
bool CEGUI__ListHeaderSegment_isSizingEnabled(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isSizingEnabled();
}
void CEGUI__ListHeaderSegment_setSizingEnabled(void* cls, bool a){
	((CEGUI::ListHeaderSegment*)cls)->setSizingEnabled(((bool)a));
}
bool CEGUI__ListHeaderSegment_isDragMovingEnabled(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isDragMovingEnabled();
}
void* CEGUI__ListHeaderSegment_getDragMoveOffset(void* cls){
	return const_cast<CEGUI::Vector2*>(&((CEGUI::ListHeaderSegment*)cls)->getDragMoveOffset());
}
void CEGUI__ListHeaderSegment_setSizingCursorImage0(void* cls, void* a){
	((CEGUI::ListHeaderSegment*)cls)->setSizingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__ListHeaderSegment_setSizingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegment*)cls)->setSizingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__ListHeaderSegment_isBeingDragSized(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isBeingDragSized();
}
bool CEGUI__ListHeaderSegment_isBeingDragMoved(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isBeingDragMoved();
}
bool CEGUI__ListHeaderSegment_isSplitterHovering(void* cls){
	return ((CEGUI::ListHeaderSegment*)cls)->isSplitterHovering();
}

//
// Begin class 'CEGUI::XMLSerializer'
//
void CEGUI__XMLSerializer__Destroy(void* cls){
	delete (CEGUI::XMLSerializer*)cls;
}
void* CEGUI__XMLSerializer_attribute(void* cls, void* a, void* b){
	return &((CEGUI::XMLSerializer*)cls)->attribute(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__XMLSerializer_closeTag(void* cls){
	return &((CEGUI::XMLSerializer*)cls)->closeTag();
}
unsigned int CEGUI__XMLSerializer_getTagCount(void* cls){
	return ((CEGUI::XMLSerializer*)cls)->getTagCount();
}
void* CEGUI__XMLSerializer_text(void* cls, void* a){
	return &((CEGUI::XMLSerializer*)cls)->text(*((CEGUI::String*)a));
}
void* CEGUI__XMLSerializer_openTag(void* cls, void* a){
	return &((CEGUI::XMLSerializer*)cls)->openTag(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::BaseDim'
//
void CEGUI__BaseDim__Destroy(void* cls){
	delete (CEGUI::BaseDim*)cls;
}
void* CEGUI__BaseDim_clone(void* cls){
	return ((CEGUI::BaseDim*)cls)->clone();
}
float CEGUI__BaseDim_getValue0(void* cls, void* a){
	return ((CEGUI::BaseDim*)cls)->getValue(*((CEGUI::Window*)a));
}
float CEGUI__BaseDim_getValue1(void* cls, void* a, void* b){
	return ((CEGUI::BaseDim*)cls)->getValue(*((CEGUI::Window*)a), *((CEGUI::Rect*)b));
}
void CEGUI__BaseDim_setDimensionOperator(void* cls, unsigned int a){
	((CEGUI::BaseDim*)cls)->setDimensionOperator(((CEGUI::DimensionOperator)a));
}
void* CEGUI__BaseDim_getOperand(void* cls){
	return const_cast<CEGUI::BaseDim*>(((CEGUI::BaseDim*)cls)->getOperand());
}
unsigned int CEGUI__BaseDim_getDimensionOperator(void* cls){
	return ((CEGUI::BaseDim*)cls)->getDimensionOperator();
}
void CEGUI__BaseDim_setOperand(void* cls, void* a){
	((CEGUI::BaseDim*)cls)->setOperand(*((CEGUI::BaseDim*)a));
}
void CEGUI__BaseDim_writeXMLToStream(void* cls, void* a){
	((CEGUI::BaseDim*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}

//
// Begin class 'CEGUI::UDimInterpolator'
//
void CEGUI__UDimInterpolator__Destroy(void* cls){
	delete (CEGUI::UDimInterpolator*)cls;
}
void* CEGUI__UDimInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::UDimInterpolator*)cls)->getType());
}
void* CEGUI__UDimInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::UDimInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__UDimInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UDimInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__UDimInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UDimInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::TabControlWindowRenderer'
//
void CEGUI__TabControlWindowRenderer__Destroy(void* cls){
	delete (CEGUI::TabControlWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::TabControl'
//
void* CEGUI__TabControl__Create(void* a, void* b){
	return new CEGUI::TabControl(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__TabControl__Destroy(void* cls){
	delete (CEGUI::TabControl*)cls;
}
void* CEGUI__TabControl_getTabContents0(void* cls, void* a){
	return ((CEGUI::TabControl*)cls)->getTabContents(*((CEGUI::String*)a));
}
void* CEGUI__TabControl_getTabContents1(void* cls, unsigned int a){
	return ((CEGUI::TabControl*)cls)->getTabContents(((unsigned int)a));
}
void CEGUI__TabControl_setSelectedTab0(void* cls, void* a){
	((CEGUI::TabControl*)cls)->setSelectedTab(*((CEGUI::String*)a));
}
void CEGUI__TabControl_setSelectedTab1(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->setSelectedTab(((unsigned int)a));
}
void CEGUI__TabControl_initialiseComponents(void* cls){
	((CEGUI::TabControl*)cls)->initialiseComponents();
}
void* CEGUI__TabControl_getTabHeight(void* cls){
	return const_cast<CEGUI::UDim*>(&((CEGUI::TabControl*)cls)->getTabHeight());
}
unsigned int CEGUI__TabControl_getTabCount(void* cls){
	return ((CEGUI::TabControl*)cls)->getTabCount();
}
void CEGUI__TabControl_makeTabVisible0(void* cls, void* a){
	((CEGUI::TabControl*)cls)->makeTabVisible(*((CEGUI::String*)a));
}
void CEGUI__TabControl_makeTabVisible1(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->makeTabVisible(((unsigned int)a));
}
void CEGUI__TabControl_setSelectedTabAtIndex(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->setSelectedTabAtIndex(((unsigned int)a));
}
void CEGUI__TabControl_makeTabVisibleAtIndex(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->makeTabVisibleAtIndex(((unsigned int)a));
}
void CEGUI__TabControl_setTabTextPadding(void* cls, void* a){
	((CEGUI::TabControl*)cls)->setTabTextPadding(*((CEGUI::UDim*)a));
}
void CEGUI__TabControl_removeTab0(void* cls, void* a){
	((CEGUI::TabControl*)cls)->removeTab(*((CEGUI::String*)a));
}
void CEGUI__TabControl_removeTab1(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->removeTab(((unsigned int)a));
}
bool CEGUI__TabControl_isTabContentsSelected(void* cls, void* a){
	return ((CEGUI::TabControl*)cls)->isTabContentsSelected(((CEGUI::Window*)a));
}
void* CEGUI__TabControl_getTabContentsAtIndex(void* cls, unsigned int a){
	return ((CEGUI::TabControl*)cls)->getTabContentsAtIndex(((unsigned int)a));
}
unsigned int CEGUI__TabControl_getTabPanePosition(void* cls){
	return ((CEGUI::TabControl*)cls)->getTabPanePosition();
}
unsigned int CEGUI__TabControl_getSelectedTabIndex(void* cls){
	return ((CEGUI::TabControl*)cls)->getSelectedTabIndex();
}
void CEGUI__TabControl_setTabHeight(void* cls, void* a){
	((CEGUI::TabControl*)cls)->setTabHeight(*((CEGUI::UDim*)a));
}
void CEGUI__TabControl_setTabPanePosition(void* cls, unsigned int a){
	((CEGUI::TabControl*)cls)->setTabPanePosition(((CEGUI::TabControl::TabPanePosition)a));
}
void* CEGUI__TabControl_getTabTextPadding(void* cls){
	return const_cast<CEGUI::UDim*>(&((CEGUI::TabControl*)cls)->getTabTextPadding());
}
void CEGUI__TabControl_addTab(void* cls, void* a){
	((CEGUI::TabControl*)cls)->addTab(((CEGUI::Window*)a));
}

//
// Begin class 'CEGUI::MultiColumnListWindowRenderer'
//
void CEGUI__MultiColumnListWindowRenderer__Destroy(void* cls){
	delete (CEGUI::MultiColumnListWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::SizeInterpolator'
//
void CEGUI__SizeInterpolator__Destroy(void* cls){
	delete (CEGUI::SizeInterpolator*)cls;
}
void* CEGUI__SizeInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::SizeInterpolator*)cls)->getType());
}
void* CEGUI__SizeInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::SizeInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__SizeInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::SizeInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__SizeInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::SizeInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::PointInterpolator'
//
void CEGUI__PointInterpolator__Destroy(void* cls){
	delete (CEGUI::PointInterpolator*)cls;
}
void* CEGUI__PointInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::PointInterpolator*)cls)->getType());
}
void* CEGUI__PointInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::PointInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__PointInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::PointInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__PointInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::PointInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::Image'
//
void* CEGUI__Image__Create0(){
	return new CEGUI::Image();
}
void* CEGUI__Image__Create1(void* a, void* b, void* c, void* d, float e, float f){
	return new CEGUI::Image(((CEGUI::Imageset*)a), *((CEGUI::String*)b), *((CEGUI::Rect*)c), *((CEGUI::Vector2*)d), ((float)e), ((float)f));
}
void* CEGUI__Image__Create2(void* a){
	return new CEGUI::Image(*((CEGUI::Image*)a));
}
void CEGUI__Image__Destroy(void* cls){
	delete (CEGUI::Image*)cls;
}
float CEGUI__Image_getWidth(void* cls){
	return ((CEGUI::Image*)cls)->getWidth();
}
void CEGUI__Image_draw0(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, unsigned int i){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), *((CEGUI::Size*)c), ((CEGUI::Rect*)d), *((CEGUI::colour*)e), *((CEGUI::colour*)f), *((CEGUI::colour*)g), *((CEGUI::colour*)h), ((CEGUI::QuadSplitMode)i));
}
void CEGUI__Image_draw1(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, void* g, unsigned int h){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), ((CEGUI::Rect*)c), *((CEGUI::colour*)d), *((CEGUI::colour*)e), *((CEGUI::colour*)f), *((CEGUI::colour*)g), ((CEGUI::QuadSplitMode)h));
}
void CEGUI__Image_draw2(void* cls, void* a, void* b, void* c, void* d, void* e, unsigned int f){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), *((CEGUI::Size*)c), ((CEGUI::Rect*)d), *((CEGUI::ColourRect*)e), ((CEGUI::QuadSplitMode)f));
}
void CEGUI__Image_draw3(void* cls, void* a, void* b, void* c, void* d, unsigned int e){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::Rect*)c), *((CEGUI::ColourRect*)d), ((CEGUI::QuadSplitMode)e));
}
void CEGUI__Image_draw4(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, void* g, unsigned int h){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::Rect*)c), *((CEGUI::colour*)d), *((CEGUI::colour*)e), *((CEGUI::colour*)f), *((CEGUI::colour*)g), ((CEGUI::QuadSplitMode)h));
}
void CEGUI__Image_draw5(void* cls, void* a, void* b, void* c, void* d, unsigned int e){
	((CEGUI::Image*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), ((CEGUI::Rect*)c), *((CEGUI::ColourRect*)d), ((CEGUI::QuadSplitMode)e));
}
void* CEGUI__Image_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Image*)cls)->getName());
}
void* CEGUI__Image_getImagesetName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Image*)cls)->getImagesetName());
}
float CEGUI__Image_getHeight(void* cls){
	return ((CEGUI::Image*)cls)->getHeight();
}
void* CEGUI__Image_getImageset(void* cls){
	return const_cast<CEGUI::Imageset*>(((CEGUI::Image*)cls)->getImageset());
}
void* CEGUI__Image_getSize(void* cls){
	return new CEGUI::Size(((CEGUI::Image*)cls)->getSize());
}
float CEGUI__Image_getOffsetY(void* cls){
	return ((CEGUI::Image*)cls)->getOffsetY();
}
float CEGUI__Image_getOffsetX(void* cls){
	return ((CEGUI::Image*)cls)->getOffsetX();
}
void CEGUI__Image_writeXMLToStream(void* cls, void* a){
	((CEGUI::Image*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void* CEGUI__Image_getOffsets(void* cls){
	return new CEGUI::Vector2(((CEGUI::Image*)cls)->getOffsets());
}
void* CEGUI__Image_getSourceTextureArea(void* cls){
	return const_cast<CEGUI::Rect*>(&((CEGUI::Image*)cls)->getSourceTextureArea());
}

//
// Begin class 'CEGUI::JustifiedRenderedString'
//
void CEGUI__JustifiedRenderedString__Destroy(void* cls){
	delete (CEGUI::JustifiedRenderedString*)cls;
}
void CEGUI__JustifiedRenderedString_draw(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::JustifiedRenderedString*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d));
}
float CEGUI__JustifiedRenderedString_getHorizontalExtent(void* cls){
	return ((CEGUI::JustifiedRenderedString*)cls)->getHorizontalExtent();
}
float CEGUI__JustifiedRenderedString_getVerticalExtent(void* cls){
	return ((CEGUI::JustifiedRenderedString*)cls)->getVerticalExtent();
}
unsigned int CEGUI__JustifiedRenderedString_getFormattedLineCount(void* cls){
	return ((CEGUI::JustifiedRenderedString*)cls)->getFormattedLineCount();
}
void CEGUI__JustifiedRenderedString_format(void* cls, void* a){
	((CEGUI::JustifiedRenderedString*)cls)->format(*((CEGUI::Size*)a));
}

//
// Begin class 'CEGUI::SubscriberSlot'
//
void* CEGUI__SubscriberSlot__Create0(){
	return new CEGUI::SubscriberSlot();
}
void CEGUI__SubscriberSlot__Destroy(void* cls){
	delete (CEGUI::SubscriberSlot*)cls;
}
void CEGUI__SubscriberSlot_cleanup(void* cls){
	((CEGUI::SubscriberSlot*)cls)->cleanup();
}
bool CEGUI__SubscriberSlot_connected(void* cls){
	return ((CEGUI::SubscriberSlot*)cls)->connected();
}

//
// Begin class 'CEGUI::FormattedRenderedString'
//
void CEGUI__FormattedRenderedString__Destroy(void* cls){
	delete (CEGUI::FormattedRenderedString*)cls;
}
void* CEGUI__FormattedRenderedString_getRenderedString(void* cls){
	return const_cast<CEGUI::RenderedString*>(&((CEGUI::FormattedRenderedString*)cls)->getRenderedString());
}
void CEGUI__FormattedRenderedString_setRenderedString(void* cls, void* a){
	((CEGUI::FormattedRenderedString*)cls)->setRenderedString(*((CEGUI::RenderedString*)a));
}

//
// Begin class 'CEGUI::Logger'
//
void CEGUI__Logger__Destroy(void* cls){
	delete (CEGUI::Logger*)cls;
}
unsigned int CEGUI__Logger_getLoggingLevel(void* cls){
	return ((CEGUI::Logger*)cls)->getLoggingLevel();
}
void CEGUI__Logger_setLoggingLevel(void* cls, unsigned int a){
	((CEGUI::Logger*)cls)->setLoggingLevel(((CEGUI::LoggingLevel)a));
}

//
// Begin class 'CEGUI::SectionSpecification'
//
void* CEGUI__SectionSpecification__Create0(void* a, void* b, void* c, void* d, void* e){
	return new CEGUI::SectionSpecification(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), *((CEGUI::String*)d), *((CEGUI::String*)e));
}
void* CEGUI__SectionSpecification__Create1(void* a, void* b, void* c, void* d, void* e, void* f){
	return new CEGUI::SectionSpecification(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), *((CEGUI::String*)d), *((CEGUI::String*)e), *((CEGUI::ColourRect*)f));
}
void CEGUI__SectionSpecification__Destroy(void* cls){
	delete (CEGUI::SectionSpecification*)cls;
}
void CEGUI__SectionSpecification_setOverrideColoursPropertyIsColourRect(void* cls, bool a){
	((CEGUI::SectionSpecification*)cls)->setOverrideColoursPropertyIsColourRect(((bool)a));
}
void CEGUI__SectionSpecification_setRenderControlPropertySource(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->setRenderControlPropertySource(*((CEGUI::String*)a));
}
void* CEGUI__SectionSpecification_getOwnerWidgetLookFeel(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::SectionSpecification*)cls)->getOwnerWidgetLookFeel());
}
void CEGUI__SectionSpecification_render0(void* cls, void* a, void* b, void* c, bool d){
	((CEGUI::SectionSpecification*)cls)->render(*((CEGUI::Window*)a), ((CEGUI::ColourRect*)b), ((CEGUI::Rect*)c), ((bool)d));
}
void CEGUI__SectionSpecification_render1(void* cls, void* a, void* b, void* c, void* d, bool e){
	((CEGUI::SectionSpecification*)cls)->render(*((CEGUI::Window*)a), *((CEGUI::Rect*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((bool)e));
}
void CEGUI__SectionSpecification_setRenderControlValue(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->setRenderControlValue(*((CEGUI::String*)a));
}
bool CEGUI__SectionSpecification_isUsingOverrideColours(void* cls){
	return ((CEGUI::SectionSpecification*)cls)->isUsingOverrideColours();
}
void* CEGUI__SectionSpecification_getSectionName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::SectionSpecification*)cls)->getSectionName());
}
void CEGUI__SectionSpecification_setRenderControlWidget(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->setRenderControlWidget(*((CEGUI::String*)a));
}
void CEGUI__SectionSpecification_setUsingOverrideColours(void* cls, bool a){
	((CEGUI::SectionSpecification*)cls)->setUsingOverrideColours(((bool)a));
}
void CEGUI__SectionSpecification_setOverrideColours(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->setOverrideColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__SectionSpecification_writeXMLToStream(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void* CEGUI__SectionSpecification_getOverrideColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::SectionSpecification*)cls)->getOverrideColours());
}
void CEGUI__SectionSpecification_setOverrideColoursPropertySource(void* cls, void* a){
	((CEGUI::SectionSpecification*)cls)->setOverrideColoursPropertySource(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::PropertyInitialiser'
//
void* CEGUI__PropertyInitialiser__Create(void* a, void* b){
	return new CEGUI::PropertyInitialiser(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__PropertyInitialiser__Destroy(void* cls){
	delete (CEGUI::PropertyInitialiser*)cls;
}
void CEGUI__PropertyInitialiser_apply(void* cls, void* a){
	((CEGUI::PropertyInitialiser*)cls)->apply(*((CEGUI::PropertySet*)a));
}
void CEGUI__PropertyInitialiser_writeXMLToStream(void* cls, void* a){
	((CEGUI::PropertyInitialiser*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void* CEGUI__PropertyInitialiser_getTargetPropertyName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::PropertyInitialiser*)cls)->getTargetPropertyName());
}
void* CEGUI__PropertyInitialiser_getInitialiserValue(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::PropertyInitialiser*)cls)->getInitialiserValue());
}

//
// Begin class 'CEGUI::PushButton'
//
void* CEGUI__PushButton__Create(void* a, void* b){
	return new CEGUI::PushButton(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__PushButton__Destroy(void* cls){
	delete (CEGUI::PushButton*)cls;
}

//
// Begin class 'CEGUI::ScrollablePaneWindowRenderer'
//
void CEGUI__ScrollablePaneWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::Checkbox'
//
void* CEGUI__Checkbox__Create(void* a, void* b){
	return new CEGUI::Checkbox(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Checkbox__Destroy(void* cls){
	delete (CEGUI::Checkbox*)cls;
}
void CEGUI__Checkbox_setSelected(void* cls, bool a){
	((CEGUI::Checkbox*)cls)->setSelected(((bool)a));
}
bool CEGUI__Checkbox_isSelected(void* cls){
	return ((CEGUI::Checkbox*)cls)->isSelected();
}

//
// Begin class 'CEGUI::WindowFactoryManager::FalagardWindowMapping'
//
void CEGUI__WindowFactoryManager__FalagardWindowMapping__Destroy(void* cls){
	delete (CEGUI::WindowFactoryManager::FalagardWindowMapping*)cls;
}

//
// Begin class 'CEGUI::ClippedContainer'
//
void* CEGUI__ClippedContainer__Create(void* a, void* b){
	return new CEGUI::ClippedContainer(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ClippedContainer__Destroy(void* cls){
	delete (CEGUI::ClippedContainer*)cls;
}
void* CEGUI__ClippedContainer_getClipperWindow(void* cls){
	return ((CEGUI::ClippedContainer*)cls)->getClipperWindow();
}
void* CEGUI__ClippedContainer_getUnclippedInnerRect_impl(void* cls){
	return new CEGUI::Rect(((CEGUI::ClippedContainer*)cls)->getUnclippedInnerRect_impl());
}
void CEGUI__ClippedContainer_setClipArea(void* cls, void* a){
	((CEGUI::ClippedContainer*)cls)->setClipArea(*((CEGUI::Rect*)a));
}
void* CEGUI__ClippedContainer_getClipArea(void* cls){
	return const_cast<CEGUI::Rect*>(&((CEGUI::ClippedContainer*)cls)->getClipArea());
}
void CEGUI__ClippedContainer_setClipperWindow(void* cls, void* a){
	((CEGUI::ClippedContainer*)cls)->setClipperWindow(((CEGUI::Window*)a));
}

//
// Begin class 'CEGUI::ScriptModule'
//
void CEGUI__ScriptModule__Destroy(void* cls){
	delete (CEGUI::ScriptModule*)cls;
}
void CEGUI__ScriptModule_createBindings(void* cls){
	((CEGUI::ScriptModule*)cls)->createBindings();
}
void CEGUI__ScriptModule_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::ScriptModule*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
void* CEGUI__ScriptModule_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ScriptModule*)cls)->getDefaultResourceGroup());
}
void CEGUI__ScriptModule_destroyBindings(void* cls){
	((CEGUI::ScriptModule*)cls)->destroyBindings();
}
void* CEGUI__ScriptModule_getIdentifierString(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ScriptModule*)cls)->getIdentifierString());
}

//
// Begin class 'CEGUI::URectInterpolator'
//
void CEGUI__URectInterpolator__Destroy(void* cls){
	delete (CEGUI::URectInterpolator*)cls;
}
void* CEGUI__URectInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::URectInterpolator*)cls)->getType());
}
void* CEGUI__URectInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::URectInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__URectInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::URectInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__URectInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::URectInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::ScrollbarWindowRenderer'
//
void CEGUI__ScrollbarWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ScrollbarWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::RightAlignedRenderedString'
//
void CEGUI__RightAlignedRenderedString__Destroy(void* cls){
	delete (CEGUI::RightAlignedRenderedString*)cls;
}
void CEGUI__RightAlignedRenderedString_draw(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::RightAlignedRenderedString*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d));
}
float CEGUI__RightAlignedRenderedString_getHorizontalExtent(void* cls){
	return ((CEGUI::RightAlignedRenderedString*)cls)->getHorizontalExtent();
}
float CEGUI__RightAlignedRenderedString_getVerticalExtent(void* cls){
	return ((CEGUI::RightAlignedRenderedString*)cls)->getVerticalExtent();
}
unsigned int CEGUI__RightAlignedRenderedString_getFormattedLineCount(void* cls){
	return ((CEGUI::RightAlignedRenderedString*)cls)->getFormattedLineCount();
}
void CEGUI__RightAlignedRenderedString_format(void* cls, void* a){
	((CEGUI::RightAlignedRenderedString*)cls)->format(*((CEGUI::Size*)a));
}

//
// Begin class 'CEGUI::DefaultLogger'
//
void CEGUI__DefaultLogger__Destroy(void* cls){
	delete (CEGUI::DefaultLogger*)cls;
}
void CEGUI__DefaultLogger_logEvent(void* cls, void* a, unsigned int b){
	((CEGUI::DefaultLogger*)cls)->logEvent(*((CEGUI::String*)a), ((CEGUI::LoggingLevel)b));
}
void CEGUI__DefaultLogger_setLogFilename(void* cls, void* a, bool b){
	((CEGUI::DefaultLogger*)cls)->setLogFilename(*((CEGUI::String*)a), ((bool)b));
}

//
// Begin class 'CEGUI::WRFactoryRegisterer'
//
void CEGUI__WRFactoryRegisterer__Destroy(void* cls){
	delete (CEGUI::WRFactoryRegisterer*)cls;
}
void CEGUI__WRFactoryRegisterer_unregisterFactory(void* cls){
	((CEGUI::WRFactoryRegisterer*)cls)->unregisterFactory();
}
void CEGUI__WRFactoryRegisterer_registerFactory(void* cls){
	((CEGUI::WRFactoryRegisterer*)cls)->registerFactory();
}

//
// Begin class 'CEGUI::Imageset'
//
void* CEGUI__Imageset__Create0(void* a, void* b){
	return new CEGUI::Imageset(*((CEGUI::String*)a), *((CEGUI::Texture*)b));
}
void* CEGUI__Imageset__Create1(void* a, void* b, void* c){
	return new CEGUI::Imageset(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c));
}
void CEGUI__Imageset__Destroy(void* cls){
	delete (CEGUI::Imageset*)cls;
}
void* CEGUI__Imageset_getTexture(void* cls){
	return ((CEGUI::Imageset*)cls)->getTexture();
}
void CEGUI__Imageset_undefineImage(void* cls, void* a){
	((CEGUI::Imageset*)cls)->undefineImage(*((CEGUI::String*)a));
}
void CEGUI__Imageset_defineImage0(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::Imageset*)cls)->defineImage(*((CEGUI::String*)a), *((CEGUI::Vector2*)b), *((CEGUI::Size*)c), *((CEGUI::Vector2*)d));
}
void CEGUI__Imageset_defineImage1(void* cls, void* a, void* b, void* c){
	((CEGUI::Imageset*)cls)->defineImage(*((CEGUI::String*)a), *((CEGUI::Rect*)b), *((CEGUI::Vector2*)c));
}
void* CEGUI__Imageset_getImageOffset(void* cls, void* a){
	return new CEGUI::Vector2(((CEGUI::Imageset*)cls)->getImageOffset(*((CEGUI::String*)a)));
}
void* CEGUI__Imageset_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Imageset*)cls)->getName());
}
void* CEGUI__Imageset_getNativeResolution(void* cls){
	return new CEGUI::Size(((CEGUI::Imageset*)cls)->getNativeResolution());
}
void CEGUI__Imageset_writeXMLToStream(void* cls, void* a){
	((CEGUI::Imageset*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
float CEGUI__Imageset_getImageHeight(void* cls, void* a){
	return ((CEGUI::Imageset*)cls)->getImageHeight(*((CEGUI::String*)a));
}
float CEGUI__Imageset_getImageWidth(void* cls, void* a){
	return ((CEGUI::Imageset*)cls)->getImageWidth(*((CEGUI::String*)a));
}
void CEGUI__Imageset_draw0(void* cls, void* a, void* b, void* c, void* d, void* e, unsigned int f){
	((CEGUI::Imageset*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), *((CEGUI::Rect*)c), ((CEGUI::Rect*)d), *((CEGUI::ColourRect*)e), ((CEGUI::QuadSplitMode)f));
}
void CEGUI__Imageset_draw1(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h, unsigned int i){
	((CEGUI::Imageset*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), *((CEGUI::Rect*)c), ((CEGUI::Rect*)d), *((CEGUI::colour*)e), *((CEGUI::colour*)f), *((CEGUI::colour*)g), *((CEGUI::colour*)h), ((CEGUI::QuadSplitMode)i));
}
void* CEGUI__Imageset_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Imageset*)cls)->getDefaultResourceGroup());
}
bool CEGUI__Imageset_isImageDefined(void* cls, void* a){
	return ((CEGUI::Imageset*)cls)->isImageDefined(*((CEGUI::String*)a));
}
void CEGUI__Imageset_setAutoScalingEnabled(void* cls, bool a){
	((CEGUI::Imageset*)cls)->setAutoScalingEnabled(((bool)a));
}
float CEGUI__Imageset_getImageOffsetY(void* cls, void* a){
	return ((CEGUI::Imageset*)cls)->getImageOffsetY(*((CEGUI::String*)a));
}
float CEGUI__Imageset_getImageOffsetX(void* cls, void* a){
	return ((CEGUI::Imageset*)cls)->getImageOffsetX(*((CEGUI::String*)a));
}
void CEGUI__Imageset_undefineAllImages(void* cls){
	((CEGUI::Imageset*)cls)->undefineAllImages();
}
void CEGUI__Imageset_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::Imageset*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
bool CEGUI__Imageset_isAutoScaled(void* cls){
	return ((CEGUI::Imageset*)cls)->isAutoScaled();
}
void CEGUI__Imageset_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::Imageset*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
void* CEGUI__Imageset_getImageSize(void* cls, void* a){
	return new CEGUI::Size(((CEGUI::Imageset*)cls)->getImageSize(*((CEGUI::String*)a)));
}
void CEGUI__Imageset_setNativeResolution(void* cls, void* a){
	((CEGUI::Imageset*)cls)->setNativeResolution(*((CEGUI::Size*)a));
}
void* CEGUI__Imageset_getImage(void* cls, void* a){
	return const_cast<CEGUI::Image*>(&((CEGUI::Imageset*)cls)->getImage(*((CEGUI::String*)a)));
}
unsigned int CEGUI__Imageset_getImageCount(void* cls){
	return ((CEGUI::Imageset*)cls)->getImageCount();
}

//
// Begin class 'CEGUI::Vector3'
//
void* CEGUI__Vector3__Create0(){
	return new CEGUI::Vector3();
}
void* CEGUI__Vector3__Create1(float a, float b, float c){
	return new CEGUI::Vector3(((float)a), ((float)b), ((float)c));
}
void* CEGUI__Vector3__Create2(void* a){
	return new CEGUI::Vector3(*((CEGUI::Vector3*)a));
}
void CEGUI__Vector3__Destroy(void* cls){
	delete (CEGUI::Vector3*)cls;
}

//
// Begin class 'CEGUI::ColourRectInterpolator'
//
void CEGUI__ColourRectInterpolator__Destroy(void* cls){
	delete (CEGUI::ColourRectInterpolator*)cls;
}
void* CEGUI__ColourRectInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ColourRectInterpolator*)cls)->getType());
}
void* CEGUI__ColourRectInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::ColourRectInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__ColourRectInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::ColourRectInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__ColourRectInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::ColourRectInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::RenderingContext'
//
void CEGUI__RenderingContext__Destroy(void* cls){
	delete (CEGUI::RenderingContext*)cls;
}

//
// Begin class 'CEGUI::ImageCodec'
//
void CEGUI__ImageCodec__Destroy(void* cls){
	delete (CEGUI::ImageCodec*)cls;
}
void* CEGUI__ImageCodec_getSupportedFormat(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ImageCodec*)cls)->getSupportedFormat());
}
void* CEGUI__ImageCodec_getIdentifierString(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ImageCodec*)cls)->getIdentifierString());
}

//
// Begin class 'CEGUI::Combobox'
//
void* CEGUI__Combobox__Create(void* a, void* b){
	return new CEGUI::Combobox(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Combobox__Destroy(void* cls){
	delete (CEGUI::Combobox*)cls;
}
void CEGUI__Combobox_initialiseComponents(void* cls){
	((CEGUI::Combobox*)cls)->initialiseComponents();
}
void CEGUI__Combobox_setItemSelectState0(void* cls, void* a, bool b){
	((CEGUI::Combobox*)cls)->setItemSelectState(((CEGUI::ListboxItem*)a), ((bool)b));
}
void CEGUI__Combobox_setItemSelectState1(void* cls, unsigned int a, bool b){
	((CEGUI::Combobox*)cls)->setItemSelectState(((unsigned int)a), ((bool)b));
}
void* CEGUI__Combobox_getSelectedItem(void* cls){
	return ((CEGUI::Combobox*)cls)->getSelectedItem();
}
void CEGUI__Combobox_hideDropList(void* cls){
	((CEGUI::Combobox*)cls)->hideDropList();
}
void CEGUI__Combobox_clearAllSelections(void* cls){
	((CEGUI::Combobox*)cls)->clearAllSelections();
}
bool CEGUI__Combobox_isItemSelected(void* cls, unsigned int a){
	return ((CEGUI::Combobox*)cls)->isItemSelected(((unsigned int)a));
}
void CEGUI__Combobox_insertItem(void* cls, void* a, void* b){
	((CEGUI::Combobox*)cls)->insertItem(((CEGUI::ListboxItem*)a), ((CEGUI::ListboxItem*)b));
}
unsigned int CEGUI__Combobox_getSelectionStartIndex(void* cls){
	return ((CEGUI::Combobox*)cls)->getSelectionStartIndex();
}
bool CEGUI__Combobox_isHorzScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Combobox*)cls)->isHorzScrollbarAlwaysShown();
}
void CEGUI__Combobox_removeItem(void* cls, void* a){
	((CEGUI::Combobox*)cls)->removeItem(((CEGUI::ListboxItem*)a));
}
void* CEGUI__Combobox_getListboxItemFromIndex(void* cls, unsigned int a){
	return ((CEGUI::Combobox*)cls)->getListboxItemFromIndex(((unsigned int)a));
}
unsigned int CEGUI__Combobox_getSelectionEndIndex(void* cls){
	return ((CEGUI::Combobox*)cls)->getSelectionEndIndex();
}
void CEGUI__Combobox_setValidationString(void* cls, void* a){
	((CEGUI::Combobox*)cls)->setValidationString(*((CEGUI::String*)a));
}
void CEGUI__Combobox_setSingleClickEnabled(void* cls, bool a){
	((CEGUI::Combobox*)cls)->setSingleClickEnabled(((bool)a));
}
void CEGUI__Combobox_resetList(void* cls){
	((CEGUI::Combobox*)cls)->resetList();
}
bool CEGUI__Combobox_hasInputFocus(void* cls){
	return ((CEGUI::Combobox*)cls)->hasInputFocus();
}
bool CEGUI__Combobox_isSortEnabled(void* cls){
	return ((CEGUI::Combobox*)cls)->isSortEnabled();
}
void CEGUI__Combobox_addItem(void* cls, void* a){
	((CEGUI::Combobox*)cls)->addItem(((CEGUI::ListboxItem*)a));
}
unsigned int CEGUI__Combobox_getCaratIndex(void* cls){
	return ((CEGUI::Combobox*)cls)->getCaratIndex();
}
void CEGUI__Combobox_setMaxTextLength(void* cls, unsigned int a){
	((CEGUI::Combobox*)cls)->setMaxTextLength(((unsigned int)a));
}
void CEGUI__Combobox_setShowVertScrollbar(void* cls, bool a){
	((CEGUI::Combobox*)cls)->setShowVertScrollbar(((bool)a));
}
bool CEGUI__Combobox_isHit(void* cls, void* a, bool b){
	return ((CEGUI::Combobox*)cls)->isHit(*((CEGUI::Vector2*)a), ((bool)b));
}
unsigned int CEGUI__Combobox_getItemCount(void* cls){
	return ((CEGUI::Combobox*)cls)->getItemCount();
}
void CEGUI__Combobox_setShowHorzScrollbar(void* cls, bool a){
	((CEGUI::Combobox*)cls)->setShowHorzScrollbar(((bool)a));
}
bool CEGUI__Combobox_isReadOnly(void* cls){
	return ((CEGUI::Combobox*)cls)->isReadOnly();
}
void* CEGUI__Combobox_getPushButton(void* cls){
	return ((CEGUI::Combobox*)cls)->getPushButton();
}
void CEGUI__Combobox_handleUpdatedListItemData(void* cls){
	((CEGUI::Combobox*)cls)->handleUpdatedListItemData();
}
bool CEGUI__Combobox_isDropDownListVisible(void* cls){
	return ((CEGUI::Combobox*)cls)->isDropDownListVisible();
}
void CEGUI__Combobox_setCaratIndex(void* cls, unsigned int a){
	((CEGUI::Combobox*)cls)->setCaratIndex(((unsigned int)a));
}
void CEGUI__Combobox_setSortingEnabled(void* cls, bool a){
	((CEGUI::Combobox*)cls)->setSortingEnabled(((bool)a));
}
unsigned int CEGUI__Combobox_getItemIndex(void* cls, void* a){
	return ((CEGUI::Combobox*)cls)->getItemIndex(((CEGUI::ListboxItem*)a));
}
unsigned int CEGUI__Combobox_getSelectionLength(void* cls){
	return ((CEGUI::Combobox*)cls)->getSelectionLength();
}
void* CEGUI__Combobox_getEditbox(void* cls){
	return ((CEGUI::Combobox*)cls)->getEditbox();
}
bool CEGUI__Combobox_isTextValid(void* cls){
	return ((CEGUI::Combobox*)cls)->isTextValid();
}
void* CEGUI__Combobox_getDropList(void* cls){
	return ((CEGUI::Combobox*)cls)->getDropList();
}
void CEGUI__Combobox_showDropList(void* cls){
	((CEGUI::Combobox*)cls)->showDropList();
}
bool CEGUI__Combobox_getSingleClickEnabled(void* cls){
	return ((CEGUI::Combobox*)cls)->getSingleClickEnabled();
}
void* CEGUI__Combobox_getValidationString(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Combobox*)cls)->getValidationString());
}
unsigned int CEGUI__Combobox_getMaxTextLength(void* cls){
	return ((CEGUI::Combobox*)cls)->getMaxTextLength();
}
void* CEGUI__Combobox_findItemWithText(void* cls, void* a, void* b){
	return ((CEGUI::Combobox*)cls)->findItemWithText(*((CEGUI::String*)a), ((CEGUI::ListboxItem*)b));
}
bool CEGUI__Combobox_isVertScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Combobox*)cls)->isVertScrollbarAlwaysShown();
}
void CEGUI__Combobox_activateEditbox(void* cls){
	((CEGUI::Combobox*)cls)->activateEditbox();
}
bool CEGUI__Combobox_isListboxItemInList(void* cls, void* a){
	return ((CEGUI::Combobox*)cls)->isListboxItemInList(((CEGUI::ListboxItem*)a));
}
void CEGUI__Combobox_setSelection(void* cls, unsigned int a, unsigned int b){
	((CEGUI::Combobox*)cls)->setSelection(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__Combobox_setReadOnly(void* cls, bool a){
	((CEGUI::Combobox*)cls)->setReadOnly(((bool)a));
}

//
// Begin class 'CEGUI::ListboxTextItem'
//
void CEGUI__ListboxTextItem__Destroy(void* cls){
	delete (CEGUI::ListboxTextItem*)cls;
}
void CEGUI__ListboxTextItem_draw(void* cls, void* a, void* b, float c, void* d){
	((CEGUI::ListboxTextItem*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), ((float)c), ((CEGUI::Rect*)d));
}
void* CEGUI__ListboxTextItem_getFont(void* cls){
	return ((CEGUI::ListboxTextItem*)cls)->getFont();
}
void CEGUI__ListboxTextItem_setText(void* cls, void* a){
	((CEGUI::ListboxTextItem*)cls)->setText(*((CEGUI::String*)a));
}
void* CEGUI__ListboxTextItem_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::ListboxTextItem*)cls)->getPixelSize());
}
bool CEGUI__ListboxTextItem_isTextParsingEnabled(void* cls){
	return ((CEGUI::ListboxTextItem*)cls)->isTextParsingEnabled();
}
void* CEGUI__ListboxTextItem_getTextColours(void* cls){
	return new CEGUI::ColourRect(((CEGUI::ListboxTextItem*)cls)->getTextColours());
}
void CEGUI__ListboxTextItem_setTextParsingEnabled(void* cls, bool a){
	((CEGUI::ListboxTextItem*)cls)->setTextParsingEnabled(((bool)a));
}
void CEGUI__ListboxTextItem_setFont0(void* cls, void* a){
	((CEGUI::ListboxTextItem*)cls)->setFont(((CEGUI::Font*)a));
}
void CEGUI__ListboxTextItem_setFont1(void* cls, void* a){
	((CEGUI::ListboxTextItem*)cls)->setFont(*((CEGUI::String*)a));
}
void CEGUI__ListboxTextItem_setTextColours0(void* cls, void* a){
	((CEGUI::ListboxTextItem*)cls)->setTextColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__ListboxTextItem_setTextColours1(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::ListboxTextItem*)cls)->setTextColours(*((CEGUI::colour*)a), *((CEGUI::colour*)b), *((CEGUI::colour*)c), *((CEGUI::colour*)d));
}
void CEGUI__ListboxTextItem_setTextColours2(void* cls, void* a){
	((CEGUI::ListboxTextItem*)cls)->setTextColours(*((CEGUI::colour*)a));
}

//
// Begin class 'CEGUI::StateImagery'
//
void* CEGUI__StateImagery__Create0(){
	return new CEGUI::StateImagery();
}
void* CEGUI__StateImagery__Create1(void* a){
	return new CEGUI::StateImagery(*((CEGUI::String*)a));
}
void CEGUI__StateImagery__Destroy(void* cls){
	delete (CEGUI::StateImagery*)cls;
}
void CEGUI__StateImagery_render0(void* cls, void* a, void* b, void* c){
	((CEGUI::StateImagery*)cls)->render(*((CEGUI::Window*)a), ((CEGUI::ColourRect*)b), ((CEGUI::Rect*)c));
}
void CEGUI__StateImagery_render1(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::StateImagery*)cls)->render(*((CEGUI::Window*)a), *((CEGUI::Rect*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d));
}
void CEGUI__StateImagery_setClippedToDisplay(void* cls, bool a){
	((CEGUI::StateImagery*)cls)->setClippedToDisplay(((bool)a));
}
void* CEGUI__StateImagery_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::StateImagery*)cls)->getName());
}
bool CEGUI__StateImagery_isClippedToDisplay(void* cls){
	return ((CEGUI::StateImagery*)cls)->isClippedToDisplay();
}
void CEGUI__StateImagery_clearLayers(void* cls){
	((CEGUI::StateImagery*)cls)->clearLayers();
}
void CEGUI__StateImagery_writeXMLToStream(void* cls, void* a){
	((CEGUI::StateImagery*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__StateImagery_addLayer(void* cls, void* a){
	((CEGUI::StateImagery*)cls)->addLayer(*((CEGUI::LayerSpecification*)a));
}

//
// Begin class 'CEGUI::KeyEventArgs'
//
void* CEGUI__KeyEventArgs__Create(void* a){
	return new CEGUI::KeyEventArgs(((CEGUI::Window*)a));
}
void CEGUI__KeyEventArgs__Destroy(void* cls){
	delete (CEGUI::KeyEventArgs*)cls;
}

//
// Begin class 'CEGUI::RenderingRoot'
//
void* CEGUI__RenderingRoot__Create(void* a){
	return new CEGUI::RenderingRoot(*((CEGUI::RenderTarget*)a));
}
void CEGUI__RenderingRoot__Destroy(void* cls){
	delete (CEGUI::RenderingRoot*)cls;
}

//
// Begin class 'CEGUI::UBox'
//
void* CEGUI__UBox__Create0(){
	return new CEGUI::UBox();
}
void* CEGUI__UBox__Create1(void* a){
	return new CEGUI::UBox(*((CEGUI::UDim*)a));
}
void* CEGUI__UBox__Create2(void* a, void* b, void* c, void* d){
	return new CEGUI::UBox(*((CEGUI::UDim*)a), *((CEGUI::UDim*)b), *((CEGUI::UDim*)c), *((CEGUI::UDim*)d));
}
void* CEGUI__UBox__Create3(void* a){
	return new CEGUI::UBox(*((CEGUI::UBox*)a));
}
void CEGUI__UBox__Destroy(void* cls){
	delete (CEGUI::UBox*)cls;
}

//
// Begin class 'CEGUI::HeaderSequenceEventArgs'
//
void* CEGUI__HeaderSequenceEventArgs__Create(void* a, unsigned int b, unsigned int c){
	return new CEGUI::HeaderSequenceEventArgs(((CEGUI::Window*)a), ((unsigned int)b), ((unsigned int)c));
}
void CEGUI__HeaderSequenceEventArgs__Destroy(void* cls){
	delete (CEGUI::HeaderSequenceEventArgs*)cls;
}

//
// Begin class 'CEGUI::SequentialLayoutContainer'
//
void CEGUI__SequentialLayoutContainer__Destroy(void* cls){
	delete (CEGUI::SequentialLayoutContainer*)cls;
}
void CEGUI__SequentialLayoutContainer_swapChildWindows0(void* cls, void* a, void* b){
	((CEGUI::SequentialLayoutContainer*)cls)->swapChildWindows(((CEGUI::Window*)a), ((CEGUI::Window*)b));
}
void CEGUI__SequentialLayoutContainer_swapChildWindows1(void* cls, void* a, void* b){
	((CEGUI::SequentialLayoutContainer*)cls)->swapChildWindows(*((CEGUI::String*)a), ((CEGUI::Window*)b));
}
void CEGUI__SequentialLayoutContainer_swapChildWindows2(void* cls, void* a, void* b){
	((CEGUI::SequentialLayoutContainer*)cls)->swapChildWindows(((CEGUI::Window*)a), *((CEGUI::String*)b));
}
void CEGUI__SequentialLayoutContainer_swapChildWindows3(void* cls, void* a, void* b){
	((CEGUI::SequentialLayoutContainer*)cls)->swapChildWindows(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__SequentialLayoutContainer_moveChildWindow(void* cls, void* a, int b){
	((CEGUI::SequentialLayoutContainer*)cls)->moveChildWindow(((CEGUI::Window*)a), ((int)b));
}
unsigned int CEGUI__SequentialLayoutContainer_getPositionOfChildWindow0(void* cls, void* a){
	return ((CEGUI::SequentialLayoutContainer*)cls)->getPositionOfChildWindow(((CEGUI::Window*)a));
}
unsigned int CEGUI__SequentialLayoutContainer_getPositionOfChildWindow1(void* cls, void* a){
	return ((CEGUI::SequentialLayoutContainer*)cls)->getPositionOfChildWindow(*((CEGUI::String*)a));
}
void* CEGUI__SequentialLayoutContainer_getChildWindowAtPosition(void* cls, unsigned int a){
	return ((CEGUI::SequentialLayoutContainer*)cls)->getChildWindowAtPosition(((unsigned int)a));
}
void CEGUI__SequentialLayoutContainer_swapChildWindowPositions(void* cls, unsigned int a, unsigned int b){
	((CEGUI::SequentialLayoutContainer*)cls)->swapChildWindowPositions(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__SequentialLayoutContainer_moveChildWindowToPosition0(void* cls, void* a, unsigned int b){
	((CEGUI::SequentialLayoutContainer*)cls)->moveChildWindowToPosition(((CEGUI::Window*)a), ((unsigned int)b));
}
void CEGUI__SequentialLayoutContainer_moveChildWindowToPosition1(void* cls, void* a, unsigned int b){
	((CEGUI::SequentialLayoutContainer*)cls)->moveChildWindowToPosition(*((CEGUI::String*)a), ((unsigned int)b));
}
void CEGUI__SequentialLayoutContainer_removeChildWindowFromPosition(void* cls, unsigned int a){
	((CEGUI::SequentialLayoutContainer*)cls)->removeChildWindowFromPosition(((unsigned int)a));
}
void CEGUI__SequentialLayoutContainer_addChildWindowToPosition0(void* cls, void* a, unsigned int b){
	((CEGUI::SequentialLayoutContainer*)cls)->addChildWindowToPosition(((CEGUI::Window*)a), ((unsigned int)b));
}
void CEGUI__SequentialLayoutContainer_addChildWindowToPosition1(void* cls, void* a, unsigned int b){
	((CEGUI::SequentialLayoutContainer*)cls)->addChildWindowToPosition(*((CEGUI::String*)a), ((unsigned int)b));
}

//
// Begin class 'CEGUI::RawDataContainer'
//
void* CEGUI__RawDataContainer__Create(){
	return new CEGUI::RawDataContainer();
}
void CEGUI__RawDataContainer__Destroy(void* cls){
	delete (CEGUI::RawDataContainer*)cls;
}
unsigned char* CEGUI__RawDataContainer_getDataPtr0(void* cls){
	return ((CEGUI::RawDataContainer*)cls)->getDataPtr();
}
unsigned char* CEGUI__RawDataContainer_getDataPtr1(void* cls){
	return const_cast<unsigned char*>(((CEGUI::RawDataContainer*)cls)->getDataPtr());
}
unsigned int CEGUI__RawDataContainer_getSize(void* cls){
	return ((CEGUI::RawDataContainer*)cls)->getSize();
}
void CEGUI__RawDataContainer_setSize(void* cls, unsigned int a){
	((CEGUI::RawDataContainer*)cls)->setSize(((unsigned int)a));
}
void CEGUI__RawDataContainer_release(void* cls){
	((CEGUI::RawDataContainer*)cls)->release();
}
void CEGUI__RawDataContainer_setData(void* cls, unsigned char* a){
	((CEGUI::RawDataContainer*)cls)->setData(((unsigned char*)a));
}

//
// Begin class 'CEGUI::ItemListBase'
//
void CEGUI__ItemListBase__Destroy(void* cls){
	delete (CEGUI::ItemListBase*)cls;
}
bool CEGUI__ItemListBase_isAutoResizeEnabled(void* cls){
	return ((CEGUI::ItemListBase*)cls)->isAutoResizeEnabled();
}
void CEGUI__ItemListBase_initialiseComponents(void* cls){
	((CEGUI::ItemListBase*)cls)->initialiseComponents();
}
void CEGUI__ItemListBase_setSortMode(void* cls, unsigned int a){
	((CEGUI::ItemListBase*)cls)->setSortMode(((CEGUI::ItemListBase::SortMode)a));
}
unsigned int CEGUI__ItemListBase_getItemCount(void* cls){
	return ((CEGUI::ItemListBase*)cls)->getItemCount();
}
bool CEGUI__ItemListBase_isItemInList(void* cls, void* a){
	return ((CEGUI::ItemListBase*)cls)->isItemInList(((CEGUI::ItemEntry*)a));
}
void CEGUI__ItemListBase_resetList(void* cls){
	((CEGUI::ItemListBase*)cls)->resetList();
}
bool CEGUI__ItemListBase_isSortEnabled(void* cls){
	return ((CEGUI::ItemListBase*)cls)->isSortEnabled();
}
void* CEGUI__ItemListBase_getContentPane(void* cls){
	return ((CEGUI::ItemListBase*)cls)->getContentPane();
}
void* CEGUI__ItemListBase_findItemWithText(void* cls, void* a, void* b){
	return ((CEGUI::ItemListBase*)cls)->findItemWithText(*((CEGUI::String*)a), ((CEGUI::ItemEntry*)b));
}
void CEGUI__ItemListBase_endInitialisation(void* cls){
	((CEGUI::ItemListBase*)cls)->endInitialisation();
}
void CEGUI__ItemListBase_setAutoResizeEnabled(void* cls, bool a){
	((CEGUI::ItemListBase*)cls)->setAutoResizeEnabled(((bool)a));
}
void CEGUI__ItemListBase_sizeToContent(void* cls){
	((CEGUI::ItemListBase*)cls)->sizeToContent();
}
void CEGUI__ItemListBase_performChildWindowLayout(void* cls){
	((CEGUI::ItemListBase*)cls)->performChildWindowLayout();
}
void* CEGUI__ItemListBase_getItemFromIndex(void* cls, unsigned int a){
	return ((CEGUI::ItemListBase*)cls)->getItemFromIndex(((unsigned int)a));
}
void CEGUI__ItemListBase_insertItem(void* cls, void* a, void* b){
	((CEGUI::ItemListBase*)cls)->insertItem(((CEGUI::ItemEntry*)a), ((CEGUI::ItemEntry*)b));
}
void CEGUI__ItemListBase_addItem(void* cls, void* a){
	((CEGUI::ItemListBase*)cls)->addItem(((CEGUI::ItemEntry*)a));
}
void CEGUI__ItemListBase_removeItem(void* cls, void* a){
	((CEGUI::ItemListBase*)cls)->removeItem(((CEGUI::ItemEntry*)a));
}
void* CEGUI__ItemListBase_getItemRenderArea(void* cls){
	return new CEGUI::Rect(((CEGUI::ItemListBase*)cls)->getItemRenderArea());
}
void CEGUI__ItemListBase_notifyItemSelectState(void* cls, void* a, bool b){
	((CEGUI::ItemListBase*)cls)->notifyItemSelectState(((CEGUI::ItemEntry*)a), ((bool)b));
}
unsigned int CEGUI__ItemListBase_getSortMode(void* cls){
	return ((CEGUI::ItemListBase*)cls)->getSortMode();
}
void CEGUI__ItemListBase_sortList(void* cls, bool a){
	((CEGUI::ItemListBase*)cls)->sortList(((bool)a));
}
void CEGUI__ItemListBase_setSortEnabled(void* cls, bool a){
	((CEGUI::ItemListBase*)cls)->setSortEnabled(((bool)a));
}
void CEGUI__ItemListBase_handleUpdatedItemData(void* cls, bool a){
	((CEGUI::ItemListBase*)cls)->handleUpdatedItemData(((bool)a));
}
unsigned int CEGUI__ItemListBase_getItemIndex(void* cls, void* a){
	return ((CEGUI::ItemListBase*)cls)->getItemIndex(((CEGUI::ItemEntry*)a));
}
void CEGUI__ItemListBase_notifyItemClicked(void* cls, void* a){
	((CEGUI::ItemListBase*)cls)->notifyItemClicked(((CEGUI::ItemEntry*)a));
}

//
// Begin class 'CEGUI::Scrollbar'
//
void* CEGUI__Scrollbar__Create(void* a, void* b){
	return new CEGUI::Scrollbar(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Scrollbar__Destroy(void* cls){
	delete (CEGUI::Scrollbar*)cls;
}
bool CEGUI__Scrollbar_isEndLockEnabled(void* cls){
	return ((CEGUI::Scrollbar*)cls)->isEndLockEnabled();
}
void CEGUI__Scrollbar_setOverlapSize(void* cls, float a){
	((CEGUI::Scrollbar*)cls)->setOverlapSize(((float)a));
}
void CEGUI__Scrollbar_initialiseComponents(void* cls){
	((CEGUI::Scrollbar*)cls)->initialiseComponents();
}
void CEGUI__Scrollbar_setScrollPosition(void* cls, float a){
	((CEGUI::Scrollbar*)cls)->setScrollPosition(((float)a));
}
void CEGUI__Scrollbar_setPageSize(void* cls, float a){
	((CEGUI::Scrollbar*)cls)->setPageSize(((float)a));
}
void* CEGUI__Scrollbar_getIncreaseButton(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getIncreaseButton();
}
float CEGUI__Scrollbar_getScrollPosition(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getScrollPosition();
}
float CEGUI__Scrollbar_getStepSize(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getStepSize();
}
float CEGUI__Scrollbar_getPageSize(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getPageSize();
}
float CEGUI__Scrollbar_getOverlapSize(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getOverlapSize();
}
void CEGUI__Scrollbar_setStepSize(void* cls, float a){
	((CEGUI::Scrollbar*)cls)->setStepSize(((float)a));
}
void CEGUI__Scrollbar_setDocumentSize(void* cls, float a){
	((CEGUI::Scrollbar*)cls)->setDocumentSize(((float)a));
}
void* CEGUI__Scrollbar_getThumb(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getThumb();
}
float CEGUI__Scrollbar_getDocumentSize(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getDocumentSize();
}
void CEGUI__Scrollbar_setEndLockEnabled(void* cls, bool a){
	((CEGUI::Scrollbar*)cls)->setEndLockEnabled(((bool)a));
}
void CEGUI__Scrollbar_setConfig(void* cls, float* a, float* b, float* c, float* d, float* e){
	((CEGUI::Scrollbar*)cls)->setConfig(((float*)a), ((float*)b), ((float*)c), ((float*)d), ((float*)e));
}
void* CEGUI__Scrollbar_getDecreaseButton(void* cls){
	return ((CEGUI::Scrollbar*)cls)->getDecreaseButton();
}

//
// Begin class 'CEGUI::Size'
//
void* CEGUI__Size__Create0(){
	return new CEGUI::Size();
}
void* CEGUI__Size__Create1(float a, float b){
	return new CEGUI::Size(((float)a), ((float)b));
}
void* CEGUI__Size__Create2(void* a){
	return new CEGUI::Size(*((CEGUI::Size*)a));
}
void CEGUI__Size__Destroy(void* cls){
	delete (CEGUI::Size*)cls;
}

//
// Begin class 'CEGUI::UBoxInterpolator'
//
void CEGUI__UBoxInterpolator__Destroy(void* cls){
	delete (CEGUI::UBoxInterpolator*)cls;
}
void* CEGUI__UBoxInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::UBoxInterpolator*)cls)->getType());
}
void* CEGUI__UBoxInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::UBoxInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__UBoxInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UBoxInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__UBoxInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UBoxInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::PropertyDim'
//
void CEGUI__PropertyDim__Destroy(void* cls){
	delete (CEGUI::PropertyDim*)cls;
}

//
// Begin class 'CEGUI::SlotFunctorBase'
//
void CEGUI__SlotFunctorBase__Destroy(void* cls){
	delete (CEGUI::SlotFunctorBase*)cls;
}

//
// Begin class 'CEGUI::ScrollablePane'
//
void* CEGUI__ScrollablePane__Create(void* a, void* b){
	return new CEGUI::ScrollablePane(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ScrollablePane__Destroy(void* cls){
	delete (CEGUI::ScrollablePane*)cls;
}
void* CEGUI__ScrollablePane_getHorzScrollbar(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getHorzScrollbar();
}
void CEGUI__ScrollablePane_setVerticalScrollPosition(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setVerticalScrollPosition(((float)a));
}
bool CEGUI__ScrollablePane_isContentPaneAutoSized(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->isContentPaneAutoSized();
}
void CEGUI__ScrollablePane_initialiseComponents(void* cls){
	((CEGUI::ScrollablePane*)cls)->initialiseComponents();
}
float CEGUI__ScrollablePane_getHorizontalOverlapSize(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getHorizontalOverlapSize();
}
void CEGUI__ScrollablePane_setHorizontalOverlapSize(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setHorizontalOverlapSize(((float)a));
}
float CEGUI__ScrollablePane_getVerticalStepSize(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getVerticalStepSize();
}
void CEGUI__ScrollablePane_setVerticalStepSize(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setVerticalStepSize(((float)a));
}
void CEGUI__ScrollablePane_setShowHorzScrollbar(void* cls, bool a){
	((CEGUI::ScrollablePane*)cls)->setShowHorzScrollbar(((bool)a));
}
void* CEGUI__ScrollablePane_getContentPane(void* cls){
	return const_cast<CEGUI::ScrolledContainer*>(((CEGUI::ScrollablePane*)cls)->getContentPane());
}
float CEGUI__ScrollablePane_getHorizontalScrollPosition(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getHorizontalScrollPosition();
}
void CEGUI__ScrollablePane_destroy(void* cls){
	((CEGUI::ScrollablePane*)cls)->destroy();
}
void CEGUI__ScrollablePane_setHorizontalStepSize(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setHorizontalStepSize(((float)a));
}
float CEGUI__ScrollablePane_getVerticalOverlapSize(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getVerticalOverlapSize();
}
void CEGUI__ScrollablePane_setVerticalOverlapSize(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setVerticalOverlapSize(((float)a));
}
bool CEGUI__ScrollablePane_isVertScrollbarAlwaysShown(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->isVertScrollbarAlwaysShown();
}
void CEGUI__ScrollablePane_setHorizontalScrollPosition(void* cls, float a){
	((CEGUI::ScrollablePane*)cls)->setHorizontalScrollPosition(((float)a));
}
void* CEGUI__ScrollablePane_getContentPaneArea(void* cls){
	return const_cast<CEGUI::Rect*>(&((CEGUI::ScrollablePane*)cls)->getContentPaneArea());
}
bool CEGUI__ScrollablePane_isHorzScrollbarAlwaysShown(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->isHorzScrollbarAlwaysShown();
}
float CEGUI__ScrollablePane_getHorizontalStepSize(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getHorizontalStepSize();
}
void* CEGUI__ScrollablePane_getViewableArea(void* cls){
	return new CEGUI::Rect(((CEGUI::ScrollablePane*)cls)->getViewableArea());
}
float CEGUI__ScrollablePane_getVerticalScrollPosition(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getVerticalScrollPosition();
}
void CEGUI__ScrollablePane_setContentPaneAutoSized(void* cls, bool a){
	((CEGUI::ScrollablePane*)cls)->setContentPaneAutoSized(((bool)a));
}
void CEGUI__ScrollablePane_setContentPaneArea(void* cls, void* a){
	((CEGUI::ScrollablePane*)cls)->setContentPaneArea(*((CEGUI::Rect*)a));
}
void CEGUI__ScrollablePane_setShowVertScrollbar(void* cls, bool a){
	((CEGUI::ScrollablePane*)cls)->setShowVertScrollbar(((bool)a));
}
void* CEGUI__ScrollablePane_getVertScrollbar(void* cls){
	return ((CEGUI::ScrollablePane*)cls)->getVertScrollbar();
}

//
// Begin class 'CEGUI::ItemListBaseWindowRenderer'
//
void CEGUI__ItemListBaseWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ItemListBaseWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::Scheme_xmlHandler'
//
void* CEGUI__Scheme_xmlHandler__Create(void* a, void* b){
	return new CEGUI::Scheme_xmlHandler(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Scheme_xmlHandler__Destroy(void* cls){
	delete (CEGUI::Scheme_xmlHandler*)cls;
}
void CEGUI__Scheme_xmlHandler_elementStart(void* cls, void* a, void* b){
	((CEGUI::Scheme_xmlHandler*)cls)->elementStart(*((CEGUI::String*)a), *((CEGUI::XMLAttributes*)b));
}
void CEGUI__Scheme_xmlHandler_elementEnd(void* cls, void* a){
	((CEGUI::Scheme_xmlHandler*)cls)->elementEnd(*((CEGUI::String*)a));
}
void* CEGUI__Scheme_xmlHandler_getObject(void* cls){
	return &((CEGUI::Scheme_xmlHandler*)cls)->getObject();
}
void* CEGUI__Scheme_xmlHandler_getObjectName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Scheme_xmlHandler*)cls)->getObjectName());
}

//
// Begin class 'CEGUI::ColourInterpolator'
//
void CEGUI__ColourInterpolator__Destroy(void* cls){
	delete (CEGUI::ColourInterpolator*)cls;
}
void* CEGUI__ColourInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ColourInterpolator*)cls)->getType());
}
void* CEGUI__ColourInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::ColourInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__ColourInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::ColourInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__ColourInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::ColourInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::FloatInterpolator'
//
void CEGUI__FloatInterpolator__Destroy(void* cls){
	delete (CEGUI::FloatInterpolator*)cls;
}
void* CEGUI__FloatInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::FloatInterpolator*)cls)->getType());
}
void* CEGUI__FloatInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::FloatInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__FloatInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::FloatInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__FloatInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::FloatInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::WindowEventArgs'
//
void* CEGUI__WindowEventArgs__Create0(void* a){
	return new CEGUI::WindowEventArgs(((CEGUI::Window*)a));
}
void* CEGUI__WindowEventArgs__Create1(void* a){
	return new CEGUI::WindowEventArgs(*((CEGUI::WindowEventArgs*)a));
}
void CEGUI__WindowEventArgs__Destroy(void* cls){
	delete (CEGUI::WindowEventArgs*)cls;
}

//
// Begin class 'CEGUI::ProgressBar'
//
void* CEGUI__ProgressBar__Create(void* a, void* b){
	return new CEGUI::ProgressBar(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ProgressBar__Destroy(void* cls){
	delete (CEGUI::ProgressBar*)cls;
}
void CEGUI__ProgressBar_setStepSize(void* cls, float a){
	((CEGUI::ProgressBar*)cls)->setStepSize(((float)a));
}
float CEGUI__ProgressBar_getStep(void* cls){
	return ((CEGUI::ProgressBar*)cls)->getStep();
}
void CEGUI__ProgressBar_step(void* cls){
	((CEGUI::ProgressBar*)cls)->step();
}
float CEGUI__ProgressBar_getProgress(void* cls){
	return ((CEGUI::ProgressBar*)cls)->getProgress();
}
void CEGUI__ProgressBar_setProgress(void* cls, float a){
	((CEGUI::ProgressBar*)cls)->setProgress(((float)a));
}
void CEGUI__ProgressBar_adjustProgress(void* cls, float a){
	((CEGUI::ProgressBar*)cls)->adjustProgress(((float)a));
}

//
// Begin class 'CEGUI::RenderingWindow'
//
void* CEGUI__RenderingWindow__Create(void* a, void* b){
	return new CEGUI::RenderingWindow(*((CEGUI::TextureTarget*)a), *((CEGUI::RenderingSurface*)b));
}
void CEGUI__RenderingWindow__Destroy(void* cls){
	delete (CEGUI::RenderingWindow*)cls;
}
void CEGUI__RenderingWindow_invalidate(void* cls){
	((CEGUI::RenderingWindow*)cls)->invalidate();
}
void CEGUI__RenderingWindow_unprojectPoint(void* cls, void* a, void* b){
	((CEGUI::RenderingWindow*)cls)->unprojectPoint(*((CEGUI::Vector2*)a), *((CEGUI::Vector2*)b));
}
void* CEGUI__RenderingWindow_getSize(void* cls){
	return const_cast<CEGUI::Size*>(&((CEGUI::RenderingWindow*)cls)->getSize());
}
void* CEGUI__RenderingWindow_getRotation(void* cls){
	return const_cast<CEGUI::Vector3*>(&((CEGUI::RenderingWindow*)cls)->getRotation());
}
void CEGUI__RenderingWindow_realiseGeometry(void* cls){
	((CEGUI::RenderingWindow*)cls)->realiseGeometry();
}
void CEGUI__RenderingWindow_invalidateGeometry(void* cls){
	((CEGUI::RenderingWindow*)cls)->invalidateGeometry();
}
void CEGUI__RenderingWindow_setRotation(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setRotation(*((CEGUI::Vector3*)a));
}
void* CEGUI__RenderingWindow_getTextureTarget0(void* cls){
	return const_cast<CEGUI::TextureTarget*>(&((CEGUI::RenderingWindow*)cls)->getTextureTarget());
}
void* CEGUI__RenderingWindow_getTextureTarget1(void* cls){
	return &((CEGUI::RenderingWindow*)cls)->getTextureTarget();
}
void CEGUI__RenderingWindow_setClippingRegion(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setClippingRegion(*((CEGUI::Rect*)a));
}
void CEGUI__RenderingWindow_draw(void* cls){
	((CEGUI::RenderingWindow*)cls)->draw();
}
void CEGUI__RenderingWindow_setRenderEffect(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setRenderEffect(((CEGUI::RenderEffect*)a));
}
bool CEGUI__RenderingWindow_isRenderingWindow(void* cls){
	return ((CEGUI::RenderingWindow*)cls)->isRenderingWindow();
}
void CEGUI__RenderingWindow_update(void* cls, float a){
	((CEGUI::RenderingWindow*)cls)->update(((float)a));
}
void* CEGUI__RenderingWindow_getPivot(void* cls){
	return const_cast<CEGUI::Vector3*>(&((CEGUI::RenderingWindow*)cls)->getPivot());
}
void CEGUI__RenderingWindow_setPosition(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setPosition(*((CEGUI::Vector2*)a));
}
void* CEGUI__RenderingWindow_getPosition(void* cls){
	return const_cast<CEGUI::Vector2*>(&((CEGUI::RenderingWindow*)cls)->getPosition());
}
void* CEGUI__RenderingWindow_getOwner0(void* cls){
	return const_cast<CEGUI::RenderingSurface*>(&((CEGUI::RenderingWindow*)cls)->getOwner());
}
void* CEGUI__RenderingWindow_getOwner1(void* cls){
	return &((CEGUI::RenderingWindow*)cls)->getOwner();
}
void CEGUI__RenderingWindow_setPivot(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setPivot(*((CEGUI::Vector3*)a));
}
void* CEGUI__RenderingWindow_getRenderEffect(void* cls){
	return ((CEGUI::RenderingWindow*)cls)->getRenderEffect();
}
void CEGUI__RenderingWindow_setSize(void* cls, void* a){
	((CEGUI::RenderingWindow*)cls)->setSize(*((CEGUI::Size*)a));
}

//
// Begin class 'CEGUI::WindowRendererModule'
//
void CEGUI__WindowRendererModule__Destroy(void* cls){
	delete (CEGUI::WindowRendererModule*)cls;
}
void CEGUI__WindowRendererModule_unregisterFactory(void* cls, void* a){
	((CEGUI::WindowRendererModule*)cls)->unregisterFactory(*((CEGUI::String*)a));
}
void CEGUI__WindowRendererModule_registerFactory(void* cls, void* a){
	((CEGUI::WindowRendererModule*)cls)->registerFactory(*((CEGUI::String*)a));
}
unsigned int CEGUI__WindowRendererModule_unregisterAllFactories(void* cls){
	return ((CEGUI::WindowRendererModule*)cls)->unregisterAllFactories();
}
unsigned int CEGUI__WindowRendererModule_registerAllFactories(void* cls){
	return ((CEGUI::WindowRendererModule*)cls)->registerAllFactories();
}

//
// Begin class 'CEGUI::GlobalEventSet'
//
void* CEGUI__GlobalEventSet__Create(){
	return new CEGUI::GlobalEventSet();
}
void CEGUI__GlobalEventSet__Destroy(void* cls){
	delete (CEGUI::GlobalEventSet*)cls;
}
void* CEGUI__GlobalEventSet_getSingleton(void* cls){
	return &((CEGUI::GlobalEventSet*)cls)->getSingleton();
}
void* CEGUI__GlobalEventSet_getSingletonPtr(void* cls){
	return ((CEGUI::GlobalEventSet*)cls)->getSingletonPtr();
}
void CEGUI__GlobalEventSet_fireEvent(void* cls, void* a, void* b, void* c){
	((CEGUI::GlobalEventSet*)cls)->fireEvent(*((CEGUI::String*)a), *((CEGUI::EventArgs*)b), *((CEGUI::String*)c));
}

//
// Begin class 'CEGUI::LeftAlignedRenderedString'
//
void CEGUI__LeftAlignedRenderedString__Destroy(void* cls){
	delete (CEGUI::LeftAlignedRenderedString*)cls;
}
void CEGUI__LeftAlignedRenderedString_draw(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::LeftAlignedRenderedString*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d));
}
float CEGUI__LeftAlignedRenderedString_getHorizontalExtent(void* cls){
	return ((CEGUI::LeftAlignedRenderedString*)cls)->getHorizontalExtent();
}
float CEGUI__LeftAlignedRenderedString_getVerticalExtent(void* cls){
	return ((CEGUI::LeftAlignedRenderedString*)cls)->getVerticalExtent();
}
unsigned int CEGUI__LeftAlignedRenderedString_getFormattedLineCount(void* cls){
	return ((CEGUI::LeftAlignedRenderedString*)cls)->getFormattedLineCount();
}
void CEGUI__LeftAlignedRenderedString_format(void* cls, void* a){
	((CEGUI::LeftAlignedRenderedString*)cls)->format(*((CEGUI::Size*)a));
}

//
// Begin class 'CEGUI::Key'
//
void CEGUI__Key__Destroy(void* cls){
	delete (CEGUI::Key*)cls;
}

//
// Begin class 'CEGUI::BoundSlot'
//
void* CEGUI__BoundSlot__Create0(unsigned int a, void* b, void* c){
	return new CEGUI::BoundSlot(((unsigned int)a), *((CEGUI::SubscriberSlot*)b), *((CEGUI::Event*)c));
}
void* CEGUI__BoundSlot__Create1(void* a){
	return new CEGUI::BoundSlot(*((CEGUI::BoundSlot*)a));
}
void CEGUI__BoundSlot__Destroy(void* cls){
	delete (CEGUI::BoundSlot*)cls;
}
void CEGUI__BoundSlot_disconnect(void* cls){
	((CEGUI::BoundSlot*)cls)->disconnect();
}
bool CEGUI__BoundSlot_connected(void* cls){
	return ((CEGUI::BoundSlot*)cls)->connected();
}

//
// Begin class 'CEGUI::XMLAttributes'
//
void* CEGUI__XMLAttributes__Create(){
	return new CEGUI::XMLAttributes();
}
void CEGUI__XMLAttributes__Destroy(void* cls){
	delete (CEGUI::XMLAttributes*)cls;
}
float CEGUI__XMLAttributes_getValueAsFloat(void* cls, void* a, float b){
	return ((CEGUI::XMLAttributes*)cls)->getValueAsFloat(*((CEGUI::String*)a), ((float)b));
}
bool CEGUI__XMLAttributes_exists(void* cls, void* a){
	return ((CEGUI::XMLAttributes*)cls)->exists(*((CEGUI::String*)a));
}
void* CEGUI__XMLAttributes_getName(void* cls, unsigned int a){
	return const_cast<CEGUI::String*>(&((CEGUI::XMLAttributes*)cls)->getName(((unsigned int)a)));
}
void CEGUI__XMLAttributes_remove(void* cls, void* a){
	((CEGUI::XMLAttributes*)cls)->remove(*((CEGUI::String*)a));
}
void* CEGUI__XMLAttributes_getValue0(void* cls, unsigned int a){
	return const_cast<CEGUI::String*>(&((CEGUI::XMLAttributes*)cls)->getValue(((unsigned int)a)));
}
void* CEGUI__XMLAttributes_getValue1(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::XMLAttributes*)cls)->getValue(*((CEGUI::String*)a)));
}
void* CEGUI__XMLAttributes_getValueAsString(void* cls, void* a, void* b){
	return const_cast<CEGUI::String*>(&((CEGUI::XMLAttributes*)cls)->getValueAsString(*((CEGUI::String*)a), *((CEGUI::String*)b)));
}
void CEGUI__XMLAttributes_add(void* cls, void* a, void* b){
	((CEGUI::XMLAttributes*)cls)->add(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__XMLAttributes_getValueAsBool(void* cls, void* a, bool b){
	return ((CEGUI::XMLAttributes*)cls)->getValueAsBool(*((CEGUI::String*)a), ((bool)b));
}
unsigned int CEGUI__XMLAttributes_getCount(void* cls){
	return ((CEGUI::XMLAttributes*)cls)->getCount();
}
int CEGUI__XMLAttributes_getValueAsInteger(void* cls, void* a, int b){
	return ((CEGUI::XMLAttributes*)cls)->getValueAsInteger(*((CEGUI::String*)a), ((int)b));
}

//
// Begin class 'CEGUI::WindowFactory'
//
void CEGUI__WindowFactory__Destroy(void* cls){
	delete (CEGUI::WindowFactory*)cls;
}
void* CEGUI__WindowFactory_getTypeName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowFactory*)cls)->getTypeName());
}

//
// Begin class 'CEGUI::TextureTarget'
//
void CEGUI__TextureTarget__Destroy(void* cls){
	delete (CEGUI::TextureTarget*)cls;
}

//
// Begin class 'CEGUI::RenderEffectManager'
//
void* CEGUI__RenderEffectManager__Create(){
	return new CEGUI::RenderEffectManager();
}
void CEGUI__RenderEffectManager__Destroy(void* cls){
	delete (CEGUI::RenderEffectManager*)cls;
}
void CEGUI__RenderEffectManager_destroy(void* cls, void* a){
	((CEGUI::RenderEffectManager*)cls)->destroy(*((CEGUI::RenderEffect*)a));
}
void* CEGUI__RenderEffectManager_create(void* cls, void* a){
	return &((CEGUI::RenderEffectManager*)cls)->create(*((CEGUI::String*)a));
}
bool CEGUI__RenderEffectManager_isEffectAvailable(void* cls, void* a){
	return ((CEGUI::RenderEffectManager*)cls)->isEffectAvailable(*((CEGUI::String*)a));
}
void CEGUI__RenderEffectManager_removeEffect(void* cls, void* a){
	((CEGUI::RenderEffectManager*)cls)->removeEffect(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::DisplayEventArgs'
//
void* CEGUI__DisplayEventArgs__Create(void* a){
	return new CEGUI::DisplayEventArgs(*((CEGUI::Size*)a));
}
void CEGUI__DisplayEventArgs__Destroy(void* cls){
	delete (CEGUI::DisplayEventArgs*)cls;
}

//
// Begin class 'CEGUI::RadioButton'
//
void* CEGUI__RadioButton__Create(void* a, void* b){
	return new CEGUI::RadioButton(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__RadioButton__Destroy(void* cls){
	delete (CEGUI::RadioButton*)cls;
}
void CEGUI__RadioButton_setSelected(void* cls, bool a){
	((CEGUI::RadioButton*)cls)->setSelected(((bool)a));
}
unsigned long CEGUI__RadioButton_getGroupID(void* cls){
	return ((CEGUI::RadioButton*)cls)->getGroupID();
}
void CEGUI__RadioButton_setGroupID(void* cls, unsigned long a){
	((CEGUI::RadioButton*)cls)->setGroupID(((unsigned long)a));
}
bool CEGUI__RadioButton_isSelected(void* cls){
	return ((CEGUI::RadioButton*)cls)->isSelected();
}
void* CEGUI__RadioButton_getSelectedButtonInGroup(void* cls){
	return ((CEGUI::RadioButton*)cls)->getSelectedButtonInGroup();
}

//
// Begin class 'CEGUI::RenderedString'
//
void* CEGUI__RenderedString__Create0(){
	return new CEGUI::RenderedString();
}
void* CEGUI__RenderedString__Create1(void* a){
	return new CEGUI::RenderedString(*((CEGUI::RenderedString*)a));
}
void CEGUI__RenderedString__Destroy(void* cls){
	delete (CEGUI::RenderedString*)cls;
}
void CEGUI__RenderedString_draw(void* cls, unsigned int a, void* b, void* c, void* d, void* e, float f){
	((CEGUI::RenderedString*)cls)->draw(((unsigned int)a), *((CEGUI::GeometryBuffer*)b), *((CEGUI::Vector2*)c), ((CEGUI::ColourRect*)d), ((CEGUI::Rect*)e), ((float)f));
}
unsigned int CEGUI__RenderedString_getLineCount(void* cls){
	return ((CEGUI::RenderedString*)cls)->getLineCount();
}
void CEGUI__RenderedString_clearComponents(void* cls){
	((CEGUI::RenderedString*)cls)->clearComponents();
}
void* CEGUI__RenderedString_getPixelSize(void* cls, unsigned int a){
	return new CEGUI::Size(((CEGUI::RenderedString*)cls)->getPixelSize(((unsigned int)a)));
}
unsigned int CEGUI__RenderedString_getSpaceCount(void* cls, unsigned int a){
	return ((CEGUI::RenderedString*)cls)->getSpaceCount(((unsigned int)a));
}
void CEGUI__RenderedString_appendComponent(void* cls, void* a){
	((CEGUI::RenderedString*)cls)->appendComponent(*((CEGUI::RenderedStringComponent*)a));
}
void CEGUI__RenderedString_split(void* cls, unsigned int a, float b, void* c){
	((CEGUI::RenderedString*)cls)->split(((unsigned int)a), ((float)b), *((CEGUI::RenderedString*)c));
}
void CEGUI__RenderedString_appendLineBreak(void* cls){
	((CEGUI::RenderedString*)cls)->appendLineBreak();
}
unsigned int CEGUI__RenderedString_getComponentCount(void* cls){
	return ((CEGUI::RenderedString*)cls)->getComponentCount();
}

//
// Begin class 'CEGUI::Vector3Interpolator'
//
void CEGUI__Vector3Interpolator__Destroy(void* cls){
	delete (CEGUI::Vector3Interpolator*)cls;
}
void* CEGUI__Vector3Interpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Vector3Interpolator*)cls)->getType());
}
void* CEGUI__Vector3Interpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::Vector3Interpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__Vector3Interpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::Vector3Interpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__Vector3Interpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::Vector3Interpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::PropertyReceiver'
//
void* CEGUI__PropertyReceiver__Create(){
	return new CEGUI::PropertyReceiver();
}
void CEGUI__PropertyReceiver__Destroy(void* cls){
	delete (CEGUI::PropertyReceiver*)cls;
}

//
// Begin class 'CEGUI::GridLayoutContainer'
//
void CEGUI__GridLayoutContainer__Destroy(void* cls){
	delete (CEGUI::GridLayoutContainer*)cls;
}
unsigned int CEGUI__GridLayoutContainer_getNextAutoPositioningIdx(void* cls){
	return ((CEGUI::GridLayoutContainer*)cls)->getNextAutoPositioningIdx();
}
unsigned int CEGUI__GridLayoutContainer_getGridWidth(void* cls){
	return ((CEGUI::GridLayoutContainer*)cls)->getGridWidth();
}
void CEGUI__GridLayoutContainer_swapChildWindowPositions0(void* cls, unsigned int a, unsigned int b){
	((CEGUI::GridLayoutContainer*)cls)->swapChildWindowPositions(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__GridLayoutContainer_swapChildWindowPositions1(void* cls, unsigned int a, unsigned int b, unsigned int c, unsigned int d){
	((CEGUI::GridLayoutContainer*)cls)->swapChildWindowPositions(((unsigned int)a), ((unsigned int)b), ((unsigned int)c), ((unsigned int)d));
}
void CEGUI__GridLayoutContainer_moveChildWindowToPosition0(void* cls, void* a, unsigned int b, unsigned int c){
	((CEGUI::GridLayoutContainer*)cls)->moveChildWindowToPosition(((CEGUI::Window*)a), ((unsigned int)b), ((unsigned int)c));
}
void CEGUI__GridLayoutContainer_moveChildWindowToPosition1(void* cls, void* a, unsigned int b, unsigned int c){
	((CEGUI::GridLayoutContainer*)cls)->moveChildWindowToPosition(*((CEGUI::String*)a), ((unsigned int)b), ((unsigned int)c));
}
unsigned int CEGUI__GridLayoutContainer_getAutoPositioning(void* cls){
	return ((CEGUI::GridLayoutContainer*)cls)->getAutoPositioning();
}
void CEGUI__GridLayoutContainer_swapChildWindows0(void* cls, void* a, void* b){
	((CEGUI::GridLayoutContainer*)cls)->swapChildWindows(((CEGUI::Window*)a), ((CEGUI::Window*)b));
}
void CEGUI__GridLayoutContainer_swapChildWindows1(void* cls, void* a, void* b){
	((CEGUI::GridLayoutContainer*)cls)->swapChildWindows(((CEGUI::Window*)a), *((CEGUI::String*)b));
}
void CEGUI__GridLayoutContainer_swapChildWindows2(void* cls, void* a, void* b){
	((CEGUI::GridLayoutContainer*)cls)->swapChildWindows(*((CEGUI::String*)a), ((CEGUI::Window*)b));
}
void CEGUI__GridLayoutContainer_layout(void* cls){
	((CEGUI::GridLayoutContainer*)cls)->layout();
}
void CEGUI__GridLayoutContainer_setNextAutoPositioningIdx(void* cls, unsigned int a){
	((CEGUI::GridLayoutContainer*)cls)->setNextAutoPositioningIdx(((unsigned int)a));
}
void CEGUI__GridLayoutContainer_setAutoPositioning(void* cls, unsigned int a){
	((CEGUI::GridLayoutContainer*)cls)->setAutoPositioning(((CEGUI::GridLayoutContainer::AutoPositioning)a));
}
void* CEGUI__GridLayoutContainer_getChildWindowAtPosition(void* cls, unsigned int a, unsigned int b){
	return ((CEGUI::GridLayoutContainer*)cls)->getChildWindowAtPosition(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__GridLayoutContainer_removeChildWindowFromPosition(void* cls, unsigned int a, unsigned int b){
	((CEGUI::GridLayoutContainer*)cls)->removeChildWindowFromPosition(((unsigned int)a), ((unsigned int)b));
}
unsigned int CEGUI__GridLayoutContainer_getGridHeight(void* cls){
	return ((CEGUI::GridLayoutContainer*)cls)->getGridHeight();
}
void CEGUI__GridLayoutContainer_addChildWindowToPosition0(void* cls, void* a, unsigned int b, unsigned int c){
	((CEGUI::GridLayoutContainer*)cls)->addChildWindowToPosition(((CEGUI::Window*)a), ((unsigned int)b), ((unsigned int)c));
}
void CEGUI__GridLayoutContainer_addChildWindowToPosition1(void* cls, void* a, unsigned int b, unsigned int c){
	((CEGUI::GridLayoutContainer*)cls)->addChildWindowToPosition(*((CEGUI::String*)a), ((unsigned int)b), ((unsigned int)c));
}
void CEGUI__GridLayoutContainer_autoPositioningSkipCells(void* cls, unsigned int a){
	((CEGUI::GridLayoutContainer*)cls)->autoPositioningSkipCells(((unsigned int)a));
}
void CEGUI__GridLayoutContainer_setGridDimensions(void* cls, unsigned int a, unsigned int b){
	((CEGUI::GridLayoutContainer*)cls)->setGridDimensions(((unsigned int)a), ((unsigned int)b));
}

//
// Begin class 'CEGUI::MenuItem'
//
void* CEGUI__MenuItem__Create(void* a, void* b){
	return new CEGUI::MenuItem(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__MenuItem__Destroy(void* cls){
	delete (CEGUI::MenuItem*)cls;
}
bool CEGUI__MenuItem_isOpened(void* cls){
	return ((CEGUI::MenuItem*)cls)->isOpened();
}
bool CEGUI__MenuItem_isPushed(void* cls){
	return ((CEGUI::MenuItem*)cls)->isPushed();
}
bool CEGUI__MenuItem_isHovering(void* cls){
	return ((CEGUI::MenuItem*)cls)->isHovering();
}
void CEGUI__MenuItem_setPopupMenu(void* cls, void* a){
	((CEGUI::MenuItem*)cls)->setPopupMenu(((CEGUI::PopupMenu*)a));
}
void* CEGUI__MenuItem_getPopupMenu(void* cls){
	return ((CEGUI::MenuItem*)cls)->getPopupMenu();
}
void CEGUI__MenuItem_openPopupMenu(void* cls, bool a){
	((CEGUI::MenuItem*)cls)->openPopupMenu(((bool)a));
}
void CEGUI__MenuItem_closePopupMenu(void* cls, bool a){
	((CEGUI::MenuItem*)cls)->closePopupMenu(((bool)a));
}
bool CEGUI__MenuItem_togglePopupMenu(void* cls){
	return ((CEGUI::MenuItem*)cls)->togglePopupMenu();
}

//
// Begin class 'CEGUI::UDim'
//
void* CEGUI__UDim__Create0(){
	return new CEGUI::UDim();
}
void* CEGUI__UDim__Create1(float a, float b){
	return new CEGUI::UDim(((float)a), ((float)b));
}
void* CEGUI__UDim__Create2(void* a){
	return new CEGUI::UDim(*((CEGUI::UDim*)a));
}
void CEGUI__UDim__Destroy(void* cls){
	delete (CEGUI::UDim*)cls;
}
float CEGUI__UDim_asRelative(void* cls, float a){
	return ((CEGUI::UDim*)cls)->asRelative(((float)a));
}
float CEGUI__UDim_asAbsolute(void* cls, float a){
	return ((CEGUI::UDim*)cls)->asAbsolute(((float)a));
}

//
// Begin class 'CEGUI::Renderer'
//
void CEGUI__Renderer__Destroy(void* cls){
	delete (CEGUI::Renderer*)cls;
}

//
// Begin class 'CEGUI::FalagardComponentBase'
//
void CEGUI__FalagardComponentBase__Destroy(void* cls){
	delete (CEGUI::FalagardComponentBase*)cls;
}
void CEGUI__FalagardComponentBase_render0(void* cls, void* a, void* b, void* c, bool d){
	((CEGUI::FalagardComponentBase*)cls)->render(*((CEGUI::Window*)a), ((CEGUI::ColourRect*)b), ((CEGUI::Rect*)c), ((bool)d));
}
void CEGUI__FalagardComponentBase_render1(void* cls, void* a, void* b, void* c, void* d, bool e){
	((CEGUI::FalagardComponentBase*)cls)->render(*((CEGUI::Window*)a), *((CEGUI::Rect*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((bool)e));
}
void CEGUI__FalagardComponentBase_setColoursPropertyIsColourRect(void* cls, bool a){
	((CEGUI::FalagardComponentBase*)cls)->setColoursPropertyIsColourRect(((bool)a));
}
void CEGUI__FalagardComponentBase_setHorzFormattingPropertySource(void* cls, void* a){
	((CEGUI::FalagardComponentBase*)cls)->setHorzFormattingPropertySource(*((CEGUI::String*)a));
}
void* CEGUI__FalagardComponentBase_getComponentArea(void* cls){
	return const_cast<CEGUI::ComponentArea*>(&((CEGUI::FalagardComponentBase*)cls)->getComponentArea());
}
void CEGUI__FalagardComponentBase_setVertFormattingPropertySource(void* cls, void* a){
	((CEGUI::FalagardComponentBase*)cls)->setVertFormattingPropertySource(*((CEGUI::String*)a));
}
void CEGUI__FalagardComponentBase_setComponentArea(void* cls, void* a){
	((CEGUI::FalagardComponentBase*)cls)->setComponentArea(*((CEGUI::ComponentArea*)a));
}
void CEGUI__FalagardComponentBase_setColoursPropertySource(void* cls, void* a){
	((CEGUI::FalagardComponentBase*)cls)->setColoursPropertySource(*((CEGUI::String*)a));
}
void* CEGUI__FalagardComponentBase_getColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::FalagardComponentBase*)cls)->getColours());
}
void CEGUI__FalagardComponentBase_setColours(void* cls, void* a){
	((CEGUI::FalagardComponentBase*)cls)->setColours(*((CEGUI::ColourRect*)a));
}

//
// Begin class 'CEGUI::WindowRenderer'
//
void CEGUI__WindowRenderer__Destroy(void* cls){
	delete (CEGUI::WindowRenderer*)cls;
}
void* CEGUI__WindowRenderer_getClass(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowRenderer*)cls)->getClass());
}
void CEGUI__WindowRenderer_performChildWindowLayout(void* cls){
	((CEGUI::WindowRenderer*)cls)->performChildWindowLayout();
}
void* CEGUI__WindowRenderer_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowRenderer*)cls)->getName());
}
void* CEGUI__WindowRenderer_getUnclippedInnerRect(void* cls){
	return new CEGUI::Rect(((CEGUI::WindowRenderer*)cls)->getUnclippedInnerRect());
}
void CEGUI__WindowRenderer_update(void* cls, float a){
	((CEGUI::WindowRenderer*)cls)->update(((float)a));
}
void CEGUI__WindowRenderer_getRenderingContext(void* cls, void* a){
	((CEGUI::WindowRenderer*)cls)->getRenderingContext(*((CEGUI::RenderingContext*)a));
}
void* CEGUI__WindowRenderer_getLookNFeel(void* cls){
	return const_cast<CEGUI::WidgetLookFeel*>(&((CEGUI::WindowRenderer*)cls)->getLookNFeel());
}
void* CEGUI__WindowRenderer_getWindow(void* cls){
	return ((CEGUI::WindowRenderer*)cls)->getWindow();
}

//
// Begin class 'CEGUI::Vertex'
//
void CEGUI__Vertex__Destroy(void* cls){
	delete (CEGUI::Vertex*)cls;
}

//
// Begin class 'CEGUI::Font'
//
void CEGUI__Font__Destroy(void* cls){
	delete (CEGUI::Font*)cls;
}
void CEGUI__Font_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::Font*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
float CEGUI__Font_getFontHeight(void* cls, float a){
	return ((CEGUI::Font*)cls)->getFontHeight(((float)a));
}
bool CEGUI__Font_isCodepointAvailable(void* cls, unsigned int a){
	return ((CEGUI::Font*)cls)->isCodepointAvailable(((unsigned int)a));
}
void* CEGUI__Font_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Font*)cls)->getName());
}
void CEGUI__Font_drawText(void* cls, void* a, void* b, void* c, void* d, void* e, float f, float g, float h){
	((CEGUI::Font*)cls)->drawText(*((CEGUI::GeometryBuffer*)a), *((CEGUI::String*)b), *((CEGUI::Vector2*)c), ((CEGUI::Rect*)d), *((CEGUI::ColourRect*)e), ((float)f), ((float)g), ((float)h));
}
void* CEGUI__Font_getNativeResolution(void* cls){
	return new CEGUI::Size(((CEGUI::Font*)cls)->getNativeResolution());
}
void CEGUI__Font_writeXMLToStream(void* cls, void* a){
	((CEGUI::Font*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
float CEGUI__Font_getTextExtent(void* cls, void* a, float b){
	return ((CEGUI::Font*)cls)->getTextExtent(*((CEGUI::String*)a), ((float)b));
}
void* CEGUI__Font_getTypeName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Font*)cls)->getTypeName());
}
float CEGUI__Font_getLineSpacing(void* cls, float a){
	return ((CEGUI::Font*)cls)->getLineSpacing(((float)a));
}
void* CEGUI__Font_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Font*)cls)->getDefaultResourceGroup());
}
void CEGUI__Font_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::Font*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
bool CEGUI__Font_isAutoScaled(void* cls){
	return ((CEGUI::Font*)cls)->isAutoScaled();
}
void* CEGUI__Font_getGlyphData(void* cls, unsigned int a){
	return const_cast<CEGUI::FontGlyph*>(((CEGUI::Font*)cls)->getGlyphData(((unsigned int)a)));
}
unsigned int CEGUI__Font_getCharAtPixel0(void* cls, void* a, float b, float c){
	return ((CEGUI::Font*)cls)->getCharAtPixel(*((CEGUI::String*)a), ((float)b), ((float)c));
}
unsigned int CEGUI__Font_getCharAtPixel1(void* cls, void* a, unsigned int b, float c, float d){
	return ((CEGUI::Font*)cls)->getCharAtPixel(*((CEGUI::String*)a), ((unsigned int)b), ((float)c), ((float)d));
}
void CEGUI__Font_setAutoScaled(void* cls, bool a){
	((CEGUI::Font*)cls)->setAutoScaled(((bool)a));
}
void CEGUI__Font_setNativeResolution(void* cls, void* a){
	((CEGUI::Font*)cls)->setNativeResolution(*((CEGUI::Size*)a));
}
float CEGUI__Font_getBaseline(void* cls, float a){
	return ((CEGUI::Font*)cls)->getBaseline(((float)a));
}

//
// Begin class 'CEGUI::ItemEntryWindowRenderer'
//
void CEGUI__ItemEntryWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ItemEntryWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::MCLGridRef'
//
void* CEGUI__MCLGridRef__Create(unsigned int a, unsigned int b){
	return new CEGUI::MCLGridRef(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__MCLGridRef__Destroy(void* cls){
	delete (CEGUI::MCLGridRef*)cls;
}

//
// Begin class 'CEGUI::StringInterpolator'
//
void CEGUI__StringInterpolator__Destroy(void* cls){
	delete (CEGUI::StringInterpolator*)cls;
}
void* CEGUI__StringInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::StringInterpolator*)cls)->getType());
}
void* CEGUI__StringInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::StringInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__StringInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::StringInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__StringInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::StringInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::ItemEntry'
//
void* CEGUI__ItemEntry__Create(void* a, void* b){
	return new CEGUI::ItemEntry(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ItemEntry__Destroy(void* cls){
	delete (CEGUI::ItemEntry*)cls;
}
void* CEGUI__ItemEntry_getItemPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::ItemEntry*)cls)->getItemPixelSize());
}
void CEGUI__ItemEntry_deselect(void* cls){
	((CEGUI::ItemEntry*)cls)->deselect();
}
void CEGUI__ItemEntry_setSelected_impl(void* cls, bool a, bool b){
	((CEGUI::ItemEntry*)cls)->setSelected_impl(((bool)a), ((bool)b));
}
void CEGUI__ItemEntry_setSelected(void* cls, bool a){
	((CEGUI::ItemEntry*)cls)->setSelected(((bool)a));
}
void* CEGUI__ItemEntry_getOwnerList(void* cls){
	return ((CEGUI::ItemEntry*)cls)->getOwnerList();
}
bool CEGUI__ItemEntry_isSelected(void* cls){
	return ((CEGUI::ItemEntry*)cls)->isSelected();
}
bool CEGUI__ItemEntry_isSelectable(void* cls){
	return ((CEGUI::ItemEntry*)cls)->isSelectable();
}
void CEGUI__ItemEntry_setSelectable(void* cls, bool a){
	((CEGUI::ItemEntry*)cls)->setSelectable(((bool)a));
}
void CEGUI__ItemEntry_select(void* cls){
	((CEGUI::ItemEntry*)cls)->select();
}

//
// Begin class 'CEGUI::String::FastLessCompare'
//
void CEGUI__String__FastLessCompare__Destroy(void* cls){
	delete (CEGUI::String::FastLessCompare*)cls;
}

//
// Begin class 'CEGUI::PopupMenu'
//
void CEGUI__PopupMenu__Destroy(void* cls){
	delete (CEGUI::PopupMenu*)cls;
}
float CEGUI__PopupMenu_getFadeOutTime(void* cls){
	return ((CEGUI::PopupMenu*)cls)->getFadeOutTime();
}
float CEGUI__PopupMenu_getFadeInTime(void* cls){
	return ((CEGUI::PopupMenu*)cls)->getFadeInTime();
}
void CEGUI__PopupMenu_openPopupMenu(void* cls, bool a){
	((CEGUI::PopupMenu*)cls)->openPopupMenu(((bool)a));
}
bool CEGUI__PopupMenu_isPopupMenuOpen(void* cls){
	return ((CEGUI::PopupMenu*)cls)->isPopupMenuOpen();
}
void CEGUI__PopupMenu_closePopupMenu(void* cls, bool a){
	((CEGUI::PopupMenu*)cls)->closePopupMenu(((bool)a));
}
void CEGUI__PopupMenu_setFadeOutTime(void* cls, float a){
	((CEGUI::PopupMenu*)cls)->setFadeOutTime(((float)a));
}
void CEGUI__PopupMenu_setFadeInTime(void* cls, float a){
	((CEGUI::PopupMenu*)cls)->setFadeInTime(((float)a));
}

//
// Begin class 'CEGUI::ListboxItem'
//
void CEGUI__ListboxItem__Destroy(void* cls){
	delete (CEGUI::ListboxItem*)cls;
}
void CEGUI__ListboxItem_setSelected(void* cls, bool a){
	((CEGUI::ListboxItem*)cls)->setSelected(((bool)a));
}
void CEGUI__ListboxItem_setAutoDeleted(void* cls, bool a){
	((CEGUI::ListboxItem*)cls)->setAutoDeleted(((bool)a));
}
bool CEGUI__ListboxItem_isAutoDeleted(void* cls){
	return ((CEGUI::ListboxItem*)cls)->isAutoDeleted();
}
void* CEGUI__ListboxItem_getSelectionColours(void* cls){
	return new CEGUI::ColourRect(((CEGUI::ListboxItem*)cls)->getSelectionColours());
}
void CEGUI__ListboxItem_setTooltipText(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setTooltipText(*((CEGUI::String*)a));
}
void* CEGUI__ListboxItem_getUserData(void* cls){
	return ((CEGUI::ListboxItem*)cls)->getUserData();
}
void CEGUI__ListboxItem_setSelectionBrushImage0(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setSelectionBrushImage(((CEGUI::Image*)a));
}
void CEGUI__ListboxItem_setSelectionBrushImage1(void* cls, void* a, void* b){
	((CEGUI::ListboxItem*)cls)->setSelectionBrushImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__ListboxItem_isDisabled(void* cls){
	return ((CEGUI::ListboxItem*)cls)->isDisabled();
}
void* CEGUI__ListboxItem_getTextVisual(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ListboxItem*)cls)->getTextVisual());
}
bool CEGUI__ListboxItem_isSelected(void* cls){
	return ((CEGUI::ListboxItem*)cls)->isSelected();
}
void* CEGUI__ListboxItem_getTooltipText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ListboxItem*)cls)->getTooltipText());
}
void* CEGUI__ListboxItem_getOwnerWindow(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::ListboxItem*)cls)->getOwnerWindow());
}
unsigned int CEGUI__ListboxItem_getID(void* cls){
	return ((CEGUI::ListboxItem*)cls)->getID();
}
void* CEGUI__ListboxItem_getSelectionBrushImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::ListboxItem*)cls)->getSelectionBrushImage());
}
void* CEGUI__ListboxItem_getText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ListboxItem*)cls)->getText());
}
void CEGUI__ListboxItem_setID(void* cls, unsigned int a){
	((CEGUI::ListboxItem*)cls)->setID(((unsigned int)a));
}
void CEGUI__ListboxItem_setUserData(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setUserData(((void*)a));
}
void CEGUI__ListboxItem_setOwnerWindow(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setOwnerWindow(((CEGUI::Window*)a));
}
void CEGUI__ListboxItem_setText(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setText(*((CEGUI::String*)a));
}
void CEGUI__ListboxItem_setSelectionColours0(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setSelectionColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__ListboxItem_setSelectionColours1(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::ListboxItem*)cls)->setSelectionColours(*((CEGUI::colour*)a), *((CEGUI::colour*)b), *((CEGUI::colour*)c), *((CEGUI::colour*)d));
}
void CEGUI__ListboxItem_setSelectionColours2(void* cls, void* a){
	((CEGUI::ListboxItem*)cls)->setSelectionColours(*((CEGUI::colour*)a));
}
void CEGUI__ListboxItem_setDisabled(void* cls, bool a){
	((CEGUI::ListboxItem*)cls)->setDisabled(((bool)a));
}

//
// Begin class 'CEGUI::BiDiVisualMapping'
//
void CEGUI__BiDiVisualMapping__Destroy(void* cls){
	delete (CEGUI::BiDiVisualMapping*)cls;
}
void* CEGUI__BiDiVisualMapping_getTextVisual(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::BiDiVisualMapping*)cls)->getTextVisual());
}
bool CEGUI__BiDiVisualMapping_updateVisual(void* cls, void* a){
	return ((CEGUI::BiDiVisualMapping*)cls)->updateVisual(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::RenderedStringTextComponent'
//
void CEGUI__RenderedStringTextComponent__Destroy(void* cls){
	delete (CEGUI::RenderedStringTextComponent*)cls;
}
void* CEGUI__RenderedStringTextComponent_clone(void* cls){
	return ((CEGUI::RenderedStringTextComponent*)cls)->clone();
}
void CEGUI__RenderedStringTextComponent_draw(void* cls, void* a, void* b, void* c, void* d, float e, float f){
	((CEGUI::RenderedStringTextComponent*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((float)e), ((float)f));
}
void* CEGUI__RenderedStringTextComponent_getFont(void* cls){
	return ((CEGUI::RenderedStringTextComponent*)cls)->getFont();
}
void CEGUI__RenderedStringTextComponent_setText(void* cls, void* a){
	((CEGUI::RenderedStringTextComponent*)cls)->setText(*((CEGUI::String*)a));
}
void* CEGUI__RenderedStringTextComponent_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::RenderedStringTextComponent*)cls)->getPixelSize());
}
void* CEGUI__RenderedStringTextComponent_getText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::RenderedStringTextComponent*)cls)->getText());
}
bool CEGUI__RenderedStringTextComponent_canSplit(void* cls){
	return ((CEGUI::RenderedStringTextComponent*)cls)->canSplit();
}
void CEGUI__RenderedStringTextComponent_setFont0(void* cls, void* a){
	((CEGUI::RenderedStringTextComponent*)cls)->setFont(((CEGUI::Font*)a));
}
void CEGUI__RenderedStringTextComponent_setFont1(void* cls, void* a){
	((CEGUI::RenderedStringTextComponent*)cls)->setFont(*((CEGUI::String*)a));
}
void* CEGUI__RenderedStringTextComponent_getColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::RenderedStringTextComponent*)cls)->getColours());
}
unsigned int CEGUI__RenderedStringTextComponent_getSpaceCount(void* cls){
	return ((CEGUI::RenderedStringTextComponent*)cls)->getSpaceCount();
}
void CEGUI__RenderedStringTextComponent_setColours0(void* cls, void* a){
	((CEGUI::RenderedStringTextComponent*)cls)->setColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__RenderedStringTextComponent_setColours1(void* cls, void* a){
	((CEGUI::RenderedStringTextComponent*)cls)->setColours(*((CEGUI::colour*)a));
}
void* CEGUI__RenderedStringTextComponent_split(void* cls, float a, bool b){
	return ((CEGUI::RenderedStringTextComponent*)cls)->split(((float)a), ((bool)b));
}

//
// Begin class 'CEGUI::Event::ScopedConnection'
//
void* CEGUI__Event__ScopedConnection__Create0(){
	return new CEGUI::Event::ScopedConnection();
}
void CEGUI__Event__ScopedConnection__Destroy(void* cls){
	delete (CEGUI::Event::ScopedConnection*)cls;
}
void CEGUI__Event__ScopedConnection_disconnect(void* cls){
	((CEGUI::Event::ScopedConnection*)cls)->disconnect();
}
bool CEGUI__Event__ScopedConnection_connected(void* cls){
	return ((CEGUI::Event::ScopedConnection*)cls)->connected();
}

//
// Begin class 'CEGUI::EditboxWindowRenderer'
//
void CEGUI__EditboxWindowRenderer__Destroy(void* cls){
	delete (CEGUI::EditboxWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::ResourceEventArgs'
//
void* CEGUI__ResourceEventArgs__Create(void* a, void* b){
	return new CEGUI::ResourceEventArgs(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ResourceEventArgs__Destroy(void* cls){
	delete (CEGUI::ResourceEventArgs*)cls;
}

//
// Begin class 'CEGUI::FontManager'
//
void* CEGUI__FontManager__Create(){
	return new CEGUI::FontManager();
}
void CEGUI__FontManager__Destroy(void* cls){
	delete (CEGUI::FontManager*)cls;
}
void CEGUI__FontManager_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::FontManager*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
void* CEGUI__FontManager_createFreeTypeFont(void* cls, void* a, float b, bool c, void* d, void* e, bool f, float g, float h, unsigned int i){
	return &((CEGUI::FontManager*)cls)->createFreeTypeFont(*((CEGUI::String*)a), ((float)b), ((bool)c), *((CEGUI::String*)d), *((CEGUI::String*)e), ((bool)f), ((float)g), ((float)h), ((CEGUI::XMLResourceExistsAction)i));
}
void* CEGUI__FontManager_createPixmapFont(void* cls, void* a, void* b, void* c, bool d, float e, float f, unsigned int g){
	return &((CEGUI::FontManager*)cls)->createPixmapFont(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((bool)d), ((float)e), ((float)f), ((CEGUI::XMLResourceExistsAction)g));
}

//
// Begin class 'CEGUI::RenderingSurface'
//
void* CEGUI__RenderingSurface__Create(void* a){
	return new CEGUI::RenderingSurface(*((CEGUI::RenderTarget*)a));
}
void CEGUI__RenderingSurface__Destroy(void* cls){
	delete (CEGUI::RenderingSurface*)cls;
}
void CEGUI__RenderingSurface_invalidate(void* cls){
	((CEGUI::RenderingSurface*)cls)->invalidate();
}
void CEGUI__RenderingSurface_draw0(void* cls){
	((CEGUI::RenderingSurface*)cls)->draw();
}
bool CEGUI__RenderingSurface_isRenderingWindow(void* cls){
	return ((CEGUI::RenderingSurface*)cls)->isRenderingWindow();
}
void* CEGUI__RenderingSurface_getRenderTarget0(void* cls){
	return const_cast<CEGUI::RenderTarget*>(&((CEGUI::RenderingSurface*)cls)->getRenderTarget());
}
void* CEGUI__RenderingSurface_getRenderTarget1(void* cls){
	return &((CEGUI::RenderingSurface*)cls)->getRenderTarget();
}
void CEGUI__RenderingSurface_addGeometryBuffer(void* cls, unsigned int a, void* b){
	((CEGUI::RenderingSurface*)cls)->addGeometryBuffer(((CEGUI::RenderQueueID)a), *((CEGUI::GeometryBuffer*)b));
}
void CEGUI__RenderingSurface_transferRenderingWindow(void* cls, void* a){
	((CEGUI::RenderingSurface*)cls)->transferRenderingWindow(*((CEGUI::RenderingWindow*)a));
}
bool CEGUI__RenderingSurface_isInvalidated(void* cls){
	return ((CEGUI::RenderingSurface*)cls)->isInvalidated();
}
void CEGUI__RenderingSurface_removeGeometryBuffer(void* cls, unsigned int a, void* b){
	((CEGUI::RenderingSurface*)cls)->removeGeometryBuffer(((CEGUI::RenderQueueID)a), *((CEGUI::GeometryBuffer*)b));
}
void CEGUI__RenderingSurface_destroyRenderingWindow(void* cls, void* a){
	((CEGUI::RenderingSurface*)cls)->destroyRenderingWindow(*((CEGUI::RenderingWindow*)a));
}
void* CEGUI__RenderingSurface_createRenderingWindow(void* cls, void* a){
	return &((CEGUI::RenderingSurface*)cls)->createRenderingWindow(*((CEGUI::TextureTarget*)a));
}
void CEGUI__RenderingSurface_clearGeometry0(void* cls, unsigned int a){
	((CEGUI::RenderingSurface*)cls)->clearGeometry(((CEGUI::RenderQueueID)a));
}
void CEGUI__RenderingSurface_clearGeometry1(void* cls){
	((CEGUI::RenderingSurface*)cls)->clearGeometry();
}

//
// Begin class 'CEGUI::ColourRect'
//
void* CEGUI__ColourRect__Create0(){
	return new CEGUI::ColourRect();
}
void* CEGUI__ColourRect__Create1(void* a){
	return new CEGUI::ColourRect(*((CEGUI::colour*)a));
}
void* CEGUI__ColourRect__Create2(void* a, void* b, void* c, void* d){
	return new CEGUI::ColourRect(*((CEGUI::colour*)a), *((CEGUI::colour*)b), *((CEGUI::colour*)c), *((CEGUI::colour*)d));
}
void* CEGUI__ColourRect__Create3(void* a){
	return new CEGUI::ColourRect(*((CEGUI::ColourRect*)a));
}
void CEGUI__ColourRect__Destroy(void* cls){
	delete (CEGUI::ColourRect*)cls;
}
void CEGUI__ColourRect_setLeftAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->setLeftAlpha(((float)a));
}
void* CEGUI__ColourRect_getSubRectangle(void* cls, float a, float b, float c, float d){
	return new CEGUI::ColourRect(((CEGUI::ColourRect*)cls)->getSubRectangle(((float)a), ((float)b), ((float)c), ((float)d)));
}
void CEGUI__ColourRect_setRightAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->setRightAlpha(((float)a));
}
void CEGUI__ColourRect_setBottomAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->setBottomAlpha(((float)a));
}
bool CEGUI__ColourRect_isMonochromatic(void* cls){
	return ((CEGUI::ColourRect*)cls)->isMonochromatic();
}
void* CEGUI__ColourRect_getColourAtPoint(void* cls, float a, float b){
	return new CEGUI::colour(((CEGUI::ColourRect*)cls)->getColourAtPoint(((float)a), ((float)b)));
}
void CEGUI__ColourRect_setTopAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->setTopAlpha(((float)a));
}
void CEGUI__ColourRect_modulateAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->modulateAlpha(((float)a));
}
void CEGUI__ColourRect_setAlpha(void* cls, float a){
	((CEGUI::ColourRect*)cls)->setAlpha(((float)a));
}
void CEGUI__ColourRect_setColours(void* cls, void* a){
	((CEGUI::ColourRect*)cls)->setColours(*((CEGUI::colour*)a));
}

//
// Begin class 'CEGUI::ComponentArea'
//
void CEGUI__ComponentArea__Destroy(void* cls){
	delete (CEGUI::ComponentArea*)cls;
}
void* CEGUI__ComponentArea_getPixelRect0(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::ComponentArea*)cls)->getPixelRect(*((CEGUI::Window*)a)));
}
void* CEGUI__ComponentArea_getPixelRect1(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::ComponentArea*)cls)->getPixelRect(*((CEGUI::Window*)a), *((CEGUI::Rect*)b)));
}
bool CEGUI__ComponentArea_isAreaFetchedFromProperty(void* cls){
	return ((CEGUI::ComponentArea*)cls)->isAreaFetchedFromProperty();
}
void* CEGUI__ComponentArea_getAreaPropertySource(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ComponentArea*)cls)->getAreaPropertySource());
}
void CEGUI__ComponentArea_setAreaPropertySource(void* cls, void* a){
	((CEGUI::ComponentArea*)cls)->setAreaPropertySource(*((CEGUI::String*)a));
}
void CEGUI__ComponentArea_writeXMLToStream(void* cls, void* a){
	((CEGUI::ComponentArea*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}

//
// Begin class 'CEGUI::Affector'
//
void* CEGUI__Affector__Create(void* a){
	return new CEGUI::Affector(((CEGUI::Animation*)a));
}
void CEGUI__Affector__Destroy(void* cls){
	delete (CEGUI::Affector*)cls;
}
unsigned int CEGUI__Affector_getApplicationMethod(void* cls){
	return ((CEGUI::Affector*)cls)->getApplicationMethod();
}
void CEGUI__Affector_savePropertyValues(void* cls, void* a){
	((CEGUI::Affector*)cls)->savePropertyValues(((CEGUI::AnimationInstance*)a));
}
void CEGUI__Affector_setApplicationMethod(void* cls, unsigned int a){
	((CEGUI::Affector*)cls)->setApplicationMethod(((CEGUI::Affector::ApplicationMethod)a));
}
void* CEGUI__Affector_createKeyFrame0(void* cls, float a){
	return ((CEGUI::Affector*)cls)->createKeyFrame(((float)a));
}
void* CEGUI__Affector_createKeyFrame1(void* cls, float a, void* b, unsigned int c, void* d){
	return ((CEGUI::Affector*)cls)->createKeyFrame(((float)a), *((CEGUI::String*)b), ((CEGUI::KeyFrame::Progression)c), *((CEGUI::String*)d));
}
void CEGUI__Affector_moveKeyFrameToPosition0(void* cls, void* a, float b){
	((CEGUI::Affector*)cls)->moveKeyFrameToPosition(((CEGUI::KeyFrame*)a), ((float)b));
}
void CEGUI__Affector_moveKeyFrameToPosition1(void* cls, float a, float b){
	((CEGUI::Affector*)cls)->moveKeyFrameToPosition(((float)a), ((float)b));
}
void* CEGUI__Affector_getTargetProperty(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Affector*)cls)->getTargetProperty());
}
void CEGUI__Affector_setTargetProperty(void* cls, void* a){
	((CEGUI::Affector*)cls)->setTargetProperty(*((CEGUI::String*)a));
}
void CEGUI__Affector_setInterpolator0(void* cls, void* a){
	((CEGUI::Affector*)cls)->setInterpolator(((CEGUI::Interpolator*)a));
}
void CEGUI__Affector_setInterpolator1(void* cls, void* a){
	((CEGUI::Affector*)cls)->setInterpolator(*((CEGUI::String*)a));
}
void* CEGUI__Affector_getInterpolator(void* cls){
	return ((CEGUI::Affector*)cls)->getInterpolator();
}
void CEGUI__Affector_destroyKeyFrame(void* cls, void* a){
	((CEGUI::Affector*)cls)->destroyKeyFrame(((CEGUI::KeyFrame*)a));
}
void* CEGUI__Affector_getKeyFrameAtIdx(void* cls, unsigned int a){
	return ((CEGUI::Affector*)cls)->getKeyFrameAtIdx(((unsigned int)a));
}
void CEGUI__Affector_apply(void* cls, void* a){
	((CEGUI::Affector*)cls)->apply(((CEGUI::AnimationInstance*)a));
}
void* CEGUI__Affector_getKeyFrameAtPosition(void* cls, float a){
	return ((CEGUI::Affector*)cls)->getKeyFrameAtPosition(((float)a));
}
unsigned int CEGUI__Affector_getNumKeyFrames(void* cls){
	return ((CEGUI::Affector*)cls)->getNumKeyFrames();
}

//
// Begin class 'CEGUI::Interpolator'
//
void CEGUI__Interpolator__Destroy(void* cls){
	delete (CEGUI::Interpolator*)cls;
}

//
// Begin class 'CEGUI::SchemeManager'
//
void* CEGUI__SchemeManager__Create(){
	return new CEGUI::SchemeManager();
}
void CEGUI__SchemeManager__Destroy(void* cls){
	delete (CEGUI::SchemeManager*)cls;
}

//
// Begin class 'CEGUI::GeometryBuffer'
//
void CEGUI__GeometryBuffer__Destroy(void* cls){
	delete (CEGUI::GeometryBuffer*)cls;
}
unsigned int CEGUI__GeometryBuffer_getBlendMode(void* cls){
	return ((CEGUI::GeometryBuffer*)cls)->getBlendMode();
}
void CEGUI__GeometryBuffer_setBlendMode(void* cls, unsigned int a){
	((CEGUI::GeometryBuffer*)cls)->setBlendMode(((CEGUI::BlendMode)a));
}

//
// Begin class 'CEGUI::FrameComponent'
//
void CEGUI__FrameComponent__Destroy(void* cls){
	delete (CEGUI::FrameComponent*)cls;
}
unsigned int CEGUI__FrameComponent_getBackgroundHorizontalFormatting(void* cls){
	return ((CEGUI::FrameComponent*)cls)->getBackgroundHorizontalFormatting();
}
void CEGUI__FrameComponent_setBackgroundHorizontalFormatting(void* cls, unsigned int a){
	((CEGUI::FrameComponent*)cls)->setBackgroundHorizontalFormatting(((CEGUI::HorizontalFormatting)a));
}
void CEGUI__FrameComponent_setImage0(void* cls, unsigned int a, void* b){
	((CEGUI::FrameComponent*)cls)->setImage(((CEGUI::FrameImageComponent)a), ((CEGUI::Image*)b));
}
void CEGUI__FrameComponent_setImage1(void* cls, unsigned int a, void* b, void* c){
	((CEGUI::FrameComponent*)cls)->setImage(((CEGUI::FrameImageComponent)a), *((CEGUI::String*)b), *((CEGUI::String*)c));
}
unsigned int CEGUI__FrameComponent_getBackgroundVerticalFormatting(void* cls){
	return ((CEGUI::FrameComponent*)cls)->getBackgroundVerticalFormatting();
}
void CEGUI__FrameComponent_setBackgroundVerticalFormatting(void* cls, unsigned int a){
	((CEGUI::FrameComponent*)cls)->setBackgroundVerticalFormatting(((CEGUI::VerticalFormatting)a));
}
void CEGUI__FrameComponent_writeXMLToStream(void* cls, void* a){
	((CEGUI::FrameComponent*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void* CEGUI__FrameComponent_getImage(void* cls, unsigned int a){
	return const_cast<CEGUI::Image*>(((CEGUI::FrameComponent*)cls)->getImage(((CEGUI::FrameImageComponent)a)));
}

//
// Begin class 'CEGUI::ListHeader'
//
void* CEGUI__ListHeader__Create(void* a, void* b){
	return new CEGUI::ListHeader(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ListHeader__Destroy(void* cls){
	delete (CEGUI::ListHeader*)cls;
}
void CEGUI__ListHeader_setColumnSizingEnabled(void* cls, bool a){
	((CEGUI::ListHeader*)cls)->setColumnSizingEnabled(((bool)a));
}
unsigned int CEGUI__ListHeader_getSortDirection(void* cls){
	return ((CEGUI::ListHeader*)cls)->getSortDirection();
}
void CEGUI__ListHeader_moveSegment0(void* cls, void* a, unsigned int b){
	((CEGUI::ListHeader*)cls)->moveSegment(*((CEGUI::ListHeaderSegment*)a), ((unsigned int)b));
}
void CEGUI__ListHeader_moveSegment1(void* cls, void* a, void* b){
	((CEGUI::ListHeader*)cls)->moveSegment(*((CEGUI::ListHeaderSegment*)a), *((CEGUI::ListHeaderSegment*)b));
}
unsigned int CEGUI__ListHeader_getColumnWithText(void* cls, void* a){
	return ((CEGUI::ListHeader*)cls)->getColumnWithText(*((CEGUI::String*)a));
}
void CEGUI__ListHeader_setColumnWidth(void* cls, unsigned int a, void* b){
	((CEGUI::ListHeader*)cls)->setColumnWidth(((unsigned int)a), *((CEGUI::UDim*)b));
}
void* CEGUI__ListHeader_getSortSegment(void* cls){
	return &((CEGUI::ListHeader*)cls)->getSortSegment();
}
float CEGUI__ListHeader_getSegmentOffset(void* cls){
	return ((CEGUI::ListHeader*)cls)->getSegmentOffset();
}
unsigned int CEGUI__ListHeader_getColumnCount(void* cls){
	return ((CEGUI::ListHeader*)cls)->getColumnCount();
}
bool CEGUI__ListHeader_isColumnDraggingEnabled(void* cls){
	return ((CEGUI::ListHeader*)cls)->isColumnDraggingEnabled();
}
unsigned int CEGUI__ListHeader_getColumnFromSegment(void* cls, void* a){
	return ((CEGUI::ListHeader*)cls)->getColumnFromSegment(*((CEGUI::ListHeaderSegment*)a));
}
void CEGUI__ListHeader_setSortColumn(void* cls, unsigned int a){
	((CEGUI::ListHeader*)cls)->setSortColumn(((unsigned int)a));
}
void CEGUI__ListHeader_moveColumn0(void* cls, unsigned int a, unsigned int b){
	((CEGUI::ListHeader*)cls)->moveColumn(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__ListHeader_moveColumn1(void* cls, unsigned int a, void* b){
	((CEGUI::ListHeader*)cls)->moveColumn(((unsigned int)a), *((CEGUI::ListHeaderSegment*)b));
}
void CEGUI__ListHeader_setSortDirection(void* cls, unsigned int a){
	((CEGUI::ListHeader*)cls)->setSortDirection(((CEGUI::ListHeaderSegment::SortDirection)a));
}
float CEGUI__ListHeader_getTotalSegmentsPixelExtent(void* cls){
	return ((CEGUI::ListHeader*)cls)->getTotalSegmentsPixelExtent();
}
void* CEGUI__ListHeader_getSegmentFromColumn(void* cls, unsigned int a){
	return &((CEGUI::ListHeader*)cls)->getSegmentFromColumn(((unsigned int)a));
}
void CEGUI__ListHeader_setSegmentOffset(void* cls, float a){
	((CEGUI::ListHeader*)cls)->setSegmentOffset(((float)a));
}
void CEGUI__ListHeader_setSortColumnFromID(void* cls, unsigned int a){
	((CEGUI::ListHeader*)cls)->setSortColumnFromID(((unsigned int)a));
}
void* CEGUI__ListHeader_getColumnWidth(void* cls, unsigned int a){
	return new CEGUI::UDim(((CEGUI::ListHeader*)cls)->getColumnWidth(((unsigned int)a)));
}
unsigned int CEGUI__ListHeader_getColumnFromID(void* cls, unsigned int a){
	return ((CEGUI::ListHeader*)cls)->getColumnFromID(((unsigned int)a));
}
float CEGUI__ListHeader_getPixelOffsetToSegment(void* cls, void* a){
	return ((CEGUI::ListHeader*)cls)->getPixelOffsetToSegment(*((CEGUI::ListHeaderSegment*)a));
}
bool CEGUI__ListHeader_isSortingEnabled(void* cls){
	return ((CEGUI::ListHeader*)cls)->isSortingEnabled();
}
void CEGUI__ListHeader_setSortSegment(void* cls, void* a){
	((CEGUI::ListHeader*)cls)->setSortSegment(*((CEGUI::ListHeaderSegment*)a));
}
void CEGUI__ListHeader_removeColumn(void* cls, unsigned int a){
	((CEGUI::ListHeader*)cls)->removeColumn(((unsigned int)a));
}
void CEGUI__ListHeader_addColumn(void* cls, void* a, unsigned int b, void* c){
	((CEGUI::ListHeader*)cls)->addColumn(*((CEGUI::String*)a), ((unsigned int)b), *((CEGUI::UDim*)c));
}
void CEGUI__ListHeader_insertColumn0(void* cls, void* a, unsigned int b, void* c, unsigned int d){
	((CEGUI::ListHeader*)cls)->insertColumn(*((CEGUI::String*)a), ((unsigned int)b), *((CEGUI::UDim*)c), ((unsigned int)d));
}
void CEGUI__ListHeader_insertColumn1(void* cls, void* a, unsigned int b, void* c, void* d){
	((CEGUI::ListHeader*)cls)->insertColumn(*((CEGUI::String*)a), ((unsigned int)b), *((CEGUI::UDim*)c), *((CEGUI::ListHeaderSegment*)d));
}
unsigned int CEGUI__ListHeader_getSortColumn(void* cls){
	return ((CEGUI::ListHeader*)cls)->getSortColumn();
}
void CEGUI__ListHeader_setColumnDraggingEnabled(void* cls, bool a){
	((CEGUI::ListHeader*)cls)->setColumnDraggingEnabled(((bool)a));
}
void CEGUI__ListHeader_setSortingEnabled(void* cls, bool a){
	((CEGUI::ListHeader*)cls)->setSortingEnabled(((bool)a));
}
void* CEGUI__ListHeader_getSegmentFromID(void* cls, unsigned int a){
	return &((CEGUI::ListHeader*)cls)->getSegmentFromID(((unsigned int)a));
}
void CEGUI__ListHeader_removeSegment(void* cls, void* a){
	((CEGUI::ListHeader*)cls)->removeSegment(*((CEGUI::ListHeaderSegment*)a));
}
float CEGUI__ListHeader_getPixelOffsetToColumn(void* cls, unsigned int a){
	return ((CEGUI::ListHeader*)cls)->getPixelOffsetToColumn(((unsigned int)a));
}
bool CEGUI__ListHeader_isColumnSizingEnabled(void* cls){
	return ((CEGUI::ListHeader*)cls)->isColumnSizingEnabled();
}

//
// Begin class 'CEGUI::Tooltip'
//
void* CEGUI__Tooltip__Create(void* a, void* b){
	return new CEGUI::Tooltip(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Tooltip__Destroy(void* cls){
	delete (CEGUI::Tooltip*)cls;
}
void* CEGUI__Tooltip_getTextSize(void* cls){
	return new CEGUI::Size(((CEGUI::Tooltip*)cls)->getTextSize());
}
void CEGUI__Tooltip_setHoverTime(void* cls, float a){
	((CEGUI::Tooltip*)cls)->setHoverTime(((float)a));
}
float CEGUI__Tooltip_getDisplayTime(void* cls){
	return ((CEGUI::Tooltip*)cls)->getDisplayTime();
}
void CEGUI__Tooltip_setDisplayTime(void* cls, float a){
	((CEGUI::Tooltip*)cls)->setDisplayTime(((float)a));
}
void CEGUI__Tooltip_setFadeTime(void* cls, float a){
	((CEGUI::Tooltip*)cls)->setFadeTime(((float)a));
}
float CEGUI__Tooltip_getFadeTime(void* cls){
	return ((CEGUI::Tooltip*)cls)->getFadeTime();
}
void CEGUI__Tooltip_setTargetWindow(void* cls, void* a){
	((CEGUI::Tooltip*)cls)->setTargetWindow(((CEGUI::Window*)a));
}
void CEGUI__Tooltip_sizeSelf(void* cls){
	((CEGUI::Tooltip*)cls)->sizeSelf();
}
void* CEGUI__Tooltip_getTargetWindow(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::Tooltip*)cls)->getTargetWindow());
}
float CEGUI__Tooltip_getHoverTime(void* cls){
	return ((CEGUI::Tooltip*)cls)->getHoverTime();
}
void CEGUI__Tooltip_positionSelf(void* cls){
	((CEGUI::Tooltip*)cls)->positionSelf();
}
void CEGUI__Tooltip_resetTimer(void* cls){
	((CEGUI::Tooltip*)cls)->resetTimer();
}
void* CEGUI__Tooltip_getTextSize_impl(void* cls){
	return new CEGUI::Size(((CEGUI::Tooltip*)cls)->getTextSize_impl());
}

//
// Begin class 'CEGUI::FontGlyph'
//
void* CEGUI__FontGlyph__Create(float a, void* b){
	return new CEGUI::FontGlyph(((float)a), ((CEGUI::Image*)b));
}
void CEGUI__FontGlyph__Destroy(void* cls){
	delete (CEGUI::FontGlyph*)cls;
}
float CEGUI__FontGlyph_getWidth(void* cls, float a){
	return ((CEGUI::FontGlyph*)cls)->getWidth(((float)a));
}
float CEGUI__FontGlyph_getRenderedAdvance(void* cls, float a){
	return ((CEGUI::FontGlyph*)cls)->getRenderedAdvance(((float)a));
}
void CEGUI__FontGlyph_setImage(void* cls, void* a){
	((CEGUI::FontGlyph*)cls)->setImage(((CEGUI::Image*)a));
}
float CEGUI__FontGlyph_getAdvance(void* cls, float a){
	return ((CEGUI::FontGlyph*)cls)->getAdvance(((float)a));
}
void CEGUI__FontGlyph_setAdvance(void* cls, float a){
	((CEGUI::FontGlyph*)cls)->setAdvance(((float)a));
}
float CEGUI__FontGlyph_getHeight(void* cls, float a){
	return ((CEGUI::FontGlyph*)cls)->getHeight(((float)a));
}
void* CEGUI__FontGlyph_getImageset(void* cls){
	return const_cast<CEGUI::Imageset*>(((CEGUI::FontGlyph*)cls)->getImageset());
}
void* CEGUI__FontGlyph_getSize(void* cls, float a, float b){
	return new CEGUI::Size(((CEGUI::FontGlyph*)cls)->getSize(((float)a), ((float)b)));
}
void* CEGUI__FontGlyph_getImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::FontGlyph*)cls)->getImage());
}

//
// Begin class 'CEGUI::ButtonBase'
//
void* CEGUI__ButtonBase__Create(void* a, void* b){
	return new CEGUI::ButtonBase(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ButtonBase__Destroy(void* cls){
	delete (CEGUI::ButtonBase*)cls;
}
bool CEGUI__ButtonBase_isPushed(void* cls){
	return ((CEGUI::ButtonBase*)cls)->isPushed();
}
bool CEGUI__ButtonBase_isHovering(void* cls){
	return ((CEGUI::ButtonBase*)cls)->isHovering();
}

//
// Begin class 'CEGUI::RenderEffect'
//
void CEGUI__RenderEffect__Destroy(void* cls){
	delete (CEGUI::RenderEffect*)cls;
}

//
// Begin class 'CEGUI::ItemListbox'
//
void CEGUI__ItemListbox__Destroy(void* cls){
	delete (CEGUI::ItemListbox*)cls;
}
void* CEGUI__ItemListbox_getFirstSelectedItem(void* cls, unsigned int a){
	return ((CEGUI::ItemListbox*)cls)->getFirstSelectedItem(((unsigned int)a));
}
void* CEGUI__ItemListbox_getLastSelectedItem(void* cls){
	return ((CEGUI::ItemListbox*)cls)->getLastSelectedItem();
}
void CEGUI__ItemListbox_selectRange(void* cls, unsigned int a, unsigned int b){
	((CEGUI::ItemListbox*)cls)->selectRange(((unsigned int)a), ((unsigned int)b));
}
void CEGUI__ItemListbox_initialiseComponents(void* cls){
	((CEGUI::ItemListbox*)cls)->initialiseComponents();
}
void CEGUI__ItemListbox_layoutItemWidgets(void* cls){
	((CEGUI::ItemListbox*)cls)->layoutItemWidgets();
}
unsigned int CEGUI__ItemListbox_getSelectedCount(void* cls){
	return ((CEGUI::ItemListbox*)cls)->getSelectedCount();
}
void CEGUI__ItemListbox_clearAllSelections(void* cls){
	((CEGUI::ItemListbox*)cls)->clearAllSelections();
}
void CEGUI__ItemListbox_setMultiSelectEnabled(void* cls, bool a){
	((CEGUI::ItemListbox*)cls)->setMultiSelectEnabled(((bool)a));
}
void* CEGUI__ItemListbox_getNextSelectedItem(void* cls){
	return ((CEGUI::ItemListbox*)cls)->getNextSelectedItem();
}
void CEGUI__ItemListbox_selectAllItems(void* cls){
	((CEGUI::ItemListbox*)cls)->selectAllItems();
}
void* CEGUI__ItemListbox_getContentSize(void* cls){
	return new CEGUI::Size(((CEGUI::ItemListbox*)cls)->getContentSize());
}
bool CEGUI__ItemListbox_isItemSelected(void* cls, unsigned int a){
	return ((CEGUI::ItemListbox*)cls)->isItemSelected(((unsigned int)a));
}
bool CEGUI__ItemListbox_testClassName_impl(void* cls, void* a){
	return ((CEGUI::ItemListbox*)cls)->testClassName_impl(*((CEGUI::String*)a));
}
void* CEGUI__ItemListbox_getNextSelectedItemAfter(void* cls, void* a){
	return ((CEGUI::ItemListbox*)cls)->getNextSelectedItemAfter(((CEGUI::ItemEntry*)a));
}
void CEGUI__ItemListbox_notifyItemSelectState(void* cls, void* a, bool b){
	((CEGUI::ItemListbox*)cls)->notifyItemSelectState(((CEGUI::ItemEntry*)a), ((bool)b));
}
bool CEGUI__ItemListbox_isMultiSelectEnabled(void* cls){
	return ((CEGUI::ItemListbox*)cls)->isMultiSelectEnabled();
}
void CEGUI__ItemListbox_notifyItemClicked(void* cls, void* a){
	((CEGUI::ItemListbox*)cls)->notifyItemClicked(((CEGUI::ItemEntry*)a));
}

//
// Begin class 'CEGUI::FreeFunctionSlot'
//
void CEGUI__FreeFunctionSlot__Destroy(void* cls){
	delete (CEGUI::FreeFunctionSlot*)cls;
}

//
// Begin class 'CEGUI::Dimension'
//
void* CEGUI__Dimension__Create0(){
	return new CEGUI::Dimension();
}
void* CEGUI__Dimension__Create1(void* a, unsigned int b){
	return new CEGUI::Dimension(*((CEGUI::BaseDim*)a), ((CEGUI::DimensionType)b));
}
void* CEGUI__Dimension__Create2(void* a){
	return new CEGUI::Dimension(*((CEGUI::Dimension*)a));
}
void CEGUI__Dimension__Destroy(void* cls){
	delete (CEGUI::Dimension*)cls;
}
unsigned int CEGUI__Dimension_getDimensionType(void* cls){
	return ((CEGUI::Dimension*)cls)->getDimensionType();
}
void CEGUI__Dimension_setBaseDimension(void* cls, void* a){
	((CEGUI::Dimension*)cls)->setBaseDimension(*((CEGUI::BaseDim*)a));
}
void CEGUI__Dimension_setDimensionType(void* cls, unsigned int a){
	((CEGUI::Dimension*)cls)->setDimensionType(((CEGUI::DimensionType)a));
}
void* CEGUI__Dimension_getBaseDimension(void* cls){
	return const_cast<CEGUI::BaseDim*>(&((CEGUI::Dimension*)cls)->getBaseDimension());
}
void CEGUI__Dimension_writeXMLToStream(void* cls, void* a){
	((CEGUI::Dimension*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}

//
// Begin class 'CEGUI::MouseEventArgs'
//
void* CEGUI__MouseEventArgs__Create(void* a){
	return new CEGUI::MouseEventArgs(((CEGUI::Window*)a));
}
void CEGUI__MouseEventArgs__Destroy(void* cls){
	delete (CEGUI::MouseEventArgs*)cls;
}

//
// Begin class 'CEGUI::Font_xmlHandler'
//
void* CEGUI__Font_xmlHandler__Create(void* a, void* b){
	return new CEGUI::Font_xmlHandler(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Font_xmlHandler__Destroy(void* cls){
	delete (CEGUI::Font_xmlHandler*)cls;
}
void CEGUI__Font_xmlHandler_elementStart(void* cls, void* a, void* b){
	((CEGUI::Font_xmlHandler*)cls)->elementStart(*((CEGUI::String*)a), *((CEGUI::XMLAttributes*)b));
}
void* CEGUI__Font_xmlHandler_getObject(void* cls){
	return &((CEGUI::Font_xmlHandler*)cls)->getObject();
}
void* CEGUI__Font_xmlHandler_getObjectName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Font_xmlHandler*)cls)->getObjectName());
}
void CEGUI__Font_xmlHandler_elementEnd(void* cls, void* a){
	((CEGUI::Font_xmlHandler*)cls)->elementEnd(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::TreeEventArgs'
//
void* CEGUI__TreeEventArgs__Create(void* a){
	return new CEGUI::TreeEventArgs(((CEGUI::Window*)a));
}
void CEGUI__TreeEventArgs__Destroy(void* cls){
	delete (CEGUI::TreeEventArgs*)cls;
}

//
// Begin class 'CEGUI::RegexMatcher'
//
void CEGUI__RegexMatcher__Destroy(void* cls){
	delete (CEGUI::RegexMatcher*)cls;
}

//
// Begin class 'CEGUI::EventSet'
//
void* CEGUI__EventSet__Create0(){
	return new CEGUI::EventSet();
}
void CEGUI__EventSet__Destroy(void* cls){
	delete (CEGUI::EventSet*)cls;
}
void CEGUI__EventSet_removeEvent(void* cls, void* a){
	((CEGUI::EventSet*)cls)->removeEvent(*((CEGUI::String*)a));
}
bool CEGUI__EventSet_isMuted(void* cls){
	return ((CEGUI::EventSet*)cls)->isMuted();
}
void CEGUI__EventSet_addEvent(void* cls, void* a){
	((CEGUI::EventSet*)cls)->addEvent(*((CEGUI::String*)a));
}
void CEGUI__EventSet_removeAllEvents(void* cls){
	((CEGUI::EventSet*)cls)->removeAllEvents();
}
bool CEGUI__EventSet_isEventPresent(void* cls, void* a){
	return ((CEGUI::EventSet*)cls)->isEventPresent(*((CEGUI::String*)a));
}
void CEGUI__EventSet_fireEvent(void* cls, void* a, void* b, void* c){
	((CEGUI::EventSet*)cls)->fireEvent(*((CEGUI::String*)a), *((CEGUI::EventArgs*)b), *((CEGUI::String*)c));
}
void CEGUI__EventSet_setMutedState(void* cls, bool a){
	((CEGUI::EventSet*)cls)->setMutedState(((bool)a));
}

//
// Begin class 'CEGUI::RenderedStringParser'
//
void CEGUI__RenderedStringParser__Destroy(void* cls){
	delete (CEGUI::RenderedStringParser*)cls;
}

//
// Begin class 'CEGUI::AnimationEventArgs'
//
void* CEGUI__AnimationEventArgs__Create(void* a){
	return new CEGUI::AnimationEventArgs(((CEGUI::AnimationInstance*)a));
}
void CEGUI__AnimationEventArgs__Destroy(void* cls){
	delete (CEGUI::AnimationEventArgs*)cls;
}

//
// Begin class 'CEGUI::TooltipWindowRenderer'
//
void CEGUI__TooltipWindowRenderer__Destroy(void* cls){
	delete (CEGUI::TooltipWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::PropertyHelper'
//
void CEGUI__PropertyHelper__Destroy(void* cls){
	delete (CEGUI::PropertyHelper*)cls;
}
void* CEGUI__PropertyHelper_boolToString(void* cls, bool a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->boolToString(((bool)a)));
}
void* CEGUI__PropertyHelper_stringToVector3(void* cls, void* a){
	return new CEGUI::Vector3(((CEGUI::PropertyHelper*)cls)->stringToVector3(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_urectToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->urectToString(*((CEGUI::URect*)a)));
}
void* CEGUI__PropertyHelper_stringToUVector2(void* cls, void* a){
	return new CEGUI::UVector2(((CEGUI::PropertyHelper*)cls)->stringToUVector2(*((CEGUI::String*)a)));
}
int CEGUI__PropertyHelper_stringToInt(void* cls, void* a){
	return ((CEGUI::PropertyHelper*)cls)->stringToInt(*((CEGUI::String*)a));
}
float CEGUI__PropertyHelper_stringToFloat(void* cls, void* a){
	return ((CEGUI::PropertyHelper*)cls)->stringToFloat(*((CEGUI::String*)a));
}
void* CEGUI__PropertyHelper_udimToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->udimToString(*((CEGUI::UDim*)a)));
}
void* CEGUI__PropertyHelper_uintToString(void* cls, unsigned int a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->uintToString(((unsigned int)a)));
}
void* CEGUI__PropertyHelper_floatToString(void* cls, float a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->floatToString(((float)a)));
}
unsigned int CEGUI__PropertyHelper_stringToUint(void* cls, void* a){
	return ((CEGUI::PropertyHelper*)cls)->stringToUint(*((CEGUI::String*)a));
}
void* CEGUI__PropertyHelper_stringToColourRect(void* cls, void* a){
	return new CEGUI::ColourRect(((CEGUI::PropertyHelper*)cls)->stringToColourRect(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_uvector2ToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->uvector2ToString(*((CEGUI::UVector2*)a)));
}
void* CEGUI__PropertyHelper_stringToUDim(void* cls, void* a){
	return new CEGUI::UDim(((CEGUI::PropertyHelper*)cls)->stringToUDim(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_pointToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->pointToString(*((CEGUI::Vector2*)a)));
}
void* CEGUI__PropertyHelper_stringToImage(void* cls, void* a){
	return const_cast<CEGUI::Image*>(((CEGUI::PropertyHelper*)cls)->stringToImage(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_colourToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->colourToString(*((CEGUI::colour*)a)));
}
void* CEGUI__PropertyHelper_stringToSize(void* cls, void* a){
	return new CEGUI::Size(((CEGUI::PropertyHelper*)cls)->stringToSize(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_uboxToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->uboxToString(*((CEGUI::UBox*)a)));
}
void* CEGUI__PropertyHelper_imageToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->imageToString(((CEGUI::Image*)a)));
}
void* CEGUI__PropertyHelper_stringToURect(void* cls, void* a){
	return new CEGUI::URect(((CEGUI::PropertyHelper*)cls)->stringToURect(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_sizeToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->sizeToString(*((CEGUI::Size*)a)));
}
void* CEGUI__PropertyHelper_colourRectToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->colourRectToString(*((CEGUI::ColourRect*)a)));
}
void* CEGUI__PropertyHelper_rectToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->rectToString(*((CEGUI::Rect*)a)));
}
void* CEGUI__PropertyHelper_stringToUBox(void* cls, void* a){
	return new CEGUI::UBox(((CEGUI::PropertyHelper*)cls)->stringToUBox(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_stringToColour(void* cls, void* a){
	return new CEGUI::colour(((CEGUI::PropertyHelper*)cls)->stringToColour(*((CEGUI::String*)a)));
}
bool CEGUI__PropertyHelper_stringToBool(void* cls, void* a){
	return ((CEGUI::PropertyHelper*)cls)->stringToBool(*((CEGUI::String*)a));
}
void* CEGUI__PropertyHelper_stringToPoint(void* cls, void* a){
	return new CEGUI::Vector2(((CEGUI::PropertyHelper*)cls)->stringToPoint(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_intToString(void* cls, int a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->intToString(((int)a)));
}
void* CEGUI__PropertyHelper_stringToRect(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::PropertyHelper*)cls)->stringToRect(*((CEGUI::String*)a)));
}
void* CEGUI__PropertyHelper_vector3ToString(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PropertyHelper*)cls)->vector3ToString(*((CEGUI::Vector3*)a)));
}

//
// Begin class 'CEGUI::Slider'
//
void* CEGUI__Slider__Create(void* a, void* b){
	return new CEGUI::Slider(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Slider__Destroy(void* cls){
	delete (CEGUI::Slider*)cls;
}
void CEGUI__Slider_setClickStep(void* cls, float a){
	((CEGUI::Slider*)cls)->setClickStep(((float)a));
}
void CEGUI__Slider_initialiseComponents(void* cls){
	((CEGUI::Slider*)cls)->initialiseComponents();
}
void CEGUI__Slider_setCurrentValue(void* cls, float a){
	((CEGUI::Slider*)cls)->setCurrentValue(((float)a));
}
float CEGUI__Slider_getMaxValue(void* cls){
	return ((CEGUI::Slider*)cls)->getMaxValue();
}
float CEGUI__Slider_getClickStep(void* cls){
	return ((CEGUI::Slider*)cls)->getClickStep();
}
void* CEGUI__Slider_getThumb(void* cls){
	return ((CEGUI::Slider*)cls)->getThumb();
}
float CEGUI__Slider_getCurrentValue(void* cls){
	return ((CEGUI::Slider*)cls)->getCurrentValue();
}
void CEGUI__Slider_setMaxValue(void* cls, float a){
	((CEGUI::Slider*)cls)->setMaxValue(((float)a));
}

//
// Begin class 'CEGUI::HorizontalLayoutContainer'
//
void CEGUI__HorizontalLayoutContainer__Destroy(void* cls){
	delete (CEGUI::HorizontalLayoutContainer*)cls;
}
void CEGUI__HorizontalLayoutContainer_layout(void* cls){
	((CEGUI::HorizontalLayoutContainer*)cls)->layout();
}

//
// Begin class 'CEGUI::Thumb'
//
void* CEGUI__Thumb__Create(void* a, void* b){
	return new CEGUI::Thumb(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Thumb__Destroy(void* cls){
	delete (CEGUI::Thumb*)cls;
}
void CEGUI__Thumb_setHorzRange(void* cls, float a, float b){
	((CEGUI::Thumb*)cls)->setHorzRange(((float)a), ((float)b));
}
void CEGUI__Thumb_setVertFree(void* cls, bool a){
	((CEGUI::Thumb*)cls)->setVertFree(((bool)a));
}
void CEGUI__Thumb_setVertRange(void* cls, float a, float b){
	((CEGUI::Thumb*)cls)->setVertRange(((float)a), ((float)b));
}
bool CEGUI__Thumb_isHotTracked(void* cls){
	return ((CEGUI::Thumb*)cls)->isHotTracked();
}
void CEGUI__Thumb_setHorzFree(void* cls, bool a){
	((CEGUI::Thumb*)cls)->setHorzFree(((bool)a));
}
bool CEGUI__Thumb_isVertFree(void* cls){
	return ((CEGUI::Thumb*)cls)->isVertFree();
}
bool CEGUI__Thumb_isHorzFree(void* cls){
	return ((CEGUI::Thumb*)cls)->isHorzFree();
}
void CEGUI__Thumb_setHotTracked(void* cls, bool a){
	((CEGUI::Thumb*)cls)->setHotTracked(((bool)a));
}

//
// Begin class 'CEGUI::Animation'
//
void* CEGUI__Animation__Create(void* a){
	return new CEGUI::Animation(*((CEGUI::String*)a));
}
void CEGUI__Animation__Destroy(void* cls){
	delete (CEGUI::Animation*)cls;
}
void CEGUI__Animation_undefineAllAutoSubscriptions(void* cls){
	((CEGUI::Animation*)cls)->undefineAllAutoSubscriptions();
}
void CEGUI__Animation_setReplayMode(void* cls, unsigned int a){
	((CEGUI::Animation*)cls)->setReplayMode(((CEGUI::Animation::ReplayMode)a));
}
void* CEGUI__Animation_getAffectorAtIdx(void* cls, unsigned int a){
	return ((CEGUI::Animation*)cls)->getAffectorAtIdx(((unsigned int)a));
}
void* CEGUI__Animation_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Animation*)cls)->getName());
}
void CEGUI__Animation_apply(void* cls, void* a){
	((CEGUI::Animation*)cls)->apply(((CEGUI::AnimationInstance*)a));
}
unsigned int CEGUI__Animation_getNumAffectors(void* cls){
	return ((CEGUI::Animation*)cls)->getNumAffectors();
}
bool CEGUI__Animation_getAutoStart(void* cls){
	return ((CEGUI::Animation*)cls)->getAutoStart();
}
void CEGUI__Animation_savePropertyValues(void* cls, void* a){
	((CEGUI::Animation*)cls)->savePropertyValues(((CEGUI::AnimationInstance*)a));
}
unsigned int CEGUI__Animation_getReplayMode(void* cls){
	return ((CEGUI::Animation*)cls)->getReplayMode();
}
void CEGUI__Animation_setAutoStart(void* cls, bool a){
	((CEGUI::Animation*)cls)->setAutoStart(((bool)a));
}
void CEGUI__Animation_defineAutoSubscription(void* cls, void* a, void* b){
	((CEGUI::Animation*)cls)->defineAutoSubscription(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__Animation_createAffector0(void* cls){
	return ((CEGUI::Animation*)cls)->createAffector();
}
void* CEGUI__Animation_createAffector1(void* cls, void* a, void* b){
	return ((CEGUI::Animation*)cls)->createAffector(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
float CEGUI__Animation_getDuration(void* cls){
	return ((CEGUI::Animation*)cls)->getDuration();
}
void CEGUI__Animation_destroyAffector(void* cls, void* a){
	((CEGUI::Animation*)cls)->destroyAffector(((CEGUI::Affector*)a));
}
void CEGUI__Animation_setDuration(void* cls, float a){
	((CEGUI::Animation*)cls)->setDuration(((float)a));
}
void CEGUI__Animation_autoSubscribe(void* cls, void* a){
	((CEGUI::Animation*)cls)->autoSubscribe(((CEGUI::AnimationInstance*)a));
}
void CEGUI__Animation_undefineAutoSubscription(void* cls, void* a, void* b){
	((CEGUI::Animation*)cls)->undefineAutoSubscription(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Animation_autoUnsubscribe(void* cls, void* a){
	((CEGUI::Animation*)cls)->autoUnsubscribe(((CEGUI::AnimationInstance*)a));
}

//
// Begin class 'CEGUI::Spinner'
//
void* CEGUI__Spinner__Create(void* a, void* b){
	return new CEGUI::Spinner(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Spinner__Destroy(void* cls){
	delete (CEGUI::Spinner*)cls;
}
void CEGUI__Spinner_initialiseComponents(void* cls){
	((CEGUI::Spinner*)cls)->initialiseComponents();
}
void CEGUI__Spinner_setTextInputMode(void* cls, unsigned int a){
	((CEGUI::Spinner*)cls)->setTextInputMode(((CEGUI::Spinner::TextInputMode)a));
}
void CEGUI__Spinner_setCurrentValue(void* cls, double a){
	((CEGUI::Spinner*)cls)->setCurrentValue(((double)a));
}
double CEGUI__Spinner_getMinimumValue(void* cls){
	return ((CEGUI::Spinner*)cls)->getMinimumValue();
}
unsigned int CEGUI__Spinner_getTextInputMode(void* cls){
	return ((CEGUI::Spinner*)cls)->getTextInputMode();
}
void CEGUI__Spinner_setMinimumValue(void* cls, double a){
	((CEGUI::Spinner*)cls)->setMinimumValue(((double)a));
}
double CEGUI__Spinner_getStepSize(void* cls){
	return ((CEGUI::Spinner*)cls)->getStepSize();
}
void CEGUI__Spinner_setMaximumValue(void* cls, double a){
	((CEGUI::Spinner*)cls)->setMaximumValue(((double)a));
}
void CEGUI__Spinner_setStepSize(void* cls, double a){
	((CEGUI::Spinner*)cls)->setStepSize(((double)a));
}
double CEGUI__Spinner_getCurrentValue(void* cls){
	return ((CEGUI::Spinner*)cls)->getCurrentValue();
}
double CEGUI__Spinner_getMaximumValue(void* cls){
	return ((CEGUI::Spinner*)cls)->getMaximumValue();
}

//
// Begin class 'CEGUI::CoordConverter'
//
void CEGUI__CoordConverter__Destroy(void* cls){
	delete (CEGUI::CoordConverter*)cls;
}
float CEGUI__CoordConverter_windowToScreenX0(void* cls, void* a, void* b){
	return ((CEGUI::CoordConverter*)cls)->windowToScreenX(*((CEGUI::Window*)a), *((CEGUI::UDim*)b));
}
float CEGUI__CoordConverter_windowToScreenX1(void* cls, void* a, float b){
	return ((CEGUI::CoordConverter*)cls)->windowToScreenX(*((CEGUI::Window*)a), ((float)b));
}
float CEGUI__CoordConverter_windowToScreenY0(void* cls, void* a, void* b){
	return ((CEGUI::CoordConverter*)cls)->windowToScreenY(*((CEGUI::Window*)a), *((CEGUI::UDim*)b));
}
float CEGUI__CoordConverter_windowToScreenY1(void* cls, void* a, float b){
	return ((CEGUI::CoordConverter*)cls)->windowToScreenY(*((CEGUI::Window*)a), ((float)b));
}
float CEGUI__CoordConverter_screenToWindowX0(void* cls, void* a, void* b){
	return ((CEGUI::CoordConverter*)cls)->screenToWindowX(*((CEGUI::Window*)a), *((CEGUI::UDim*)b));
}
float CEGUI__CoordConverter_screenToWindowX1(void* cls, void* a, float b){
	return ((CEGUI::CoordConverter*)cls)->screenToWindowX(*((CEGUI::Window*)a), ((float)b));
}
float CEGUI__CoordConverter_screenToWindowY0(void* cls, void* a, void* b){
	return ((CEGUI::CoordConverter*)cls)->screenToWindowY(*((CEGUI::Window*)a), *((CEGUI::UDim*)b));
}
float CEGUI__CoordConverter_screenToWindowY1(void* cls, void* a, float b){
	return ((CEGUI::CoordConverter*)cls)->screenToWindowY(*((CEGUI::Window*)a), ((float)b));
}
void* CEGUI__CoordConverter_windowToScreen0(void* cls, void* a, void* b){
	return new CEGUI::Vector2(((CEGUI::CoordConverter*)cls)->windowToScreen(*((CEGUI::Window*)a), *((CEGUI::UVector2*)b)));
}
void* CEGUI__CoordConverter_windowToScreen1(void* cls, void* a, void* b){
	return new CEGUI::Vector2(((CEGUI::CoordConverter*)cls)->windowToScreen(*((CEGUI::Window*)a), *((CEGUI::Vector2*)b)));
}
void* CEGUI__CoordConverter_windowToScreen2(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::CoordConverter*)cls)->windowToScreen(*((CEGUI::Window*)a), *((CEGUI::URect*)b)));
}
void* CEGUI__CoordConverter_windowToScreen3(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::CoordConverter*)cls)->windowToScreen(*((CEGUI::Window*)a), *((CEGUI::Rect*)b)));
}
void* CEGUI__CoordConverter_screenToWindow0(void* cls, void* a, void* b){
	return new CEGUI::Vector2(((CEGUI::CoordConverter*)cls)->screenToWindow(*((CEGUI::Window*)a), *((CEGUI::UVector2*)b)));
}
void* CEGUI__CoordConverter_screenToWindow1(void* cls, void* a, void* b){
	return new CEGUI::Vector2(((CEGUI::CoordConverter*)cls)->screenToWindow(*((CEGUI::Window*)a), *((CEGUI::Vector2*)b)));
}
void* CEGUI__CoordConverter_screenToWindow2(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::CoordConverter*)cls)->screenToWindow(*((CEGUI::Window*)a), *((CEGUI::URect*)b)));
}
void* CEGUI__CoordConverter_screenToWindow3(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::CoordConverter*)cls)->screenToWindow(*((CEGUI::Window*)a), *((CEGUI::Rect*)b)));
}

//
// Begin class 'CEGUI::TreeItem'
//
void* CEGUI__TreeItem__Create(void* a, unsigned int b, void* c, bool d, bool e){
	return new CEGUI::TreeItem(*((CEGUI::String*)a), ((unsigned int)b), ((void*)c), ((bool)d), ((bool)e));
}
void CEGUI__TreeItem__Destroy(void* cls){
	delete (CEGUI::TreeItem*)cls;
}
void CEGUI__TreeItem_addItem(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->addItem(((CEGUI::TreeItem*)a));
}
void CEGUI__TreeItem_setSelected(void* cls, bool a){
	((CEGUI::TreeItem*)cls)->setSelected(((bool)a));
}
void* CEGUI__TreeItem_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::TreeItem*)cls)->getPixelSize());
}
void CEGUI__TreeItem_setAutoDeleted(void* cls, bool a){
	((CEGUI::TreeItem*)cls)->setAutoDeleted(((bool)a));
}
void CEGUI__TreeItem_setTextColours0(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setTextColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__TreeItem_setTextColours1(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::TreeItem*)cls)->setTextColours(*((CEGUI::colour*)a), *((CEGUI::colour*)b), *((CEGUI::colour*)c), *((CEGUI::colour*)d));
}
void CEGUI__TreeItem_setTextColours2(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setTextColours(*((CEGUI::colour*)a));
}
bool CEGUI__TreeItem_isAutoDeleted(void* cls){
	return ((CEGUI::TreeItem*)cls)->isAutoDeleted();
}
void* CEGUI__TreeItem_getSelectionColours(void* cls){
	return new CEGUI::ColourRect(((CEGUI::TreeItem*)cls)->getSelectionColours());
}
unsigned int CEGUI__TreeItem_getItemCount(void* cls){
	return ((CEGUI::TreeItem*)cls)->getItemCount();
}
void CEGUI__TreeItem_setID(void* cls, unsigned int a){
	((CEGUI::TreeItem*)cls)->setID(((unsigned int)a));
}
void CEGUI__TreeItem_toggleIsOpen(void* cls){
	((CEGUI::TreeItem*)cls)->toggleIsOpen();
}
void CEGUI__TreeItem_setButtonLocation(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setButtonLocation(*((CEGUI::Rect*)a));
}
void* CEGUI__TreeItem_getUserData(void* cls){
	return ((CEGUI::TreeItem*)cls)->getUserData();
}
void CEGUI__TreeItem_setSelectionBrushImage0(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setSelectionBrushImage(((CEGUI::Image*)a));
}
void CEGUI__TreeItem_setSelectionBrushImage1(void* cls, void* a, void* b){
	((CEGUI::TreeItem*)cls)->setSelectionBrushImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__TreeItem_isDisabled(void* cls){
	return ((CEGUI::TreeItem*)cls)->isDisabled();
}
void* CEGUI__TreeItem_getTextVisual(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TreeItem*)cls)->getTextVisual());
}
bool CEGUI__TreeItem_isSelected(void* cls){
	return ((CEGUI::TreeItem*)cls)->isSelected();
}
void CEGUI__TreeItem_setIcon(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setIcon(*((CEGUI::Image*)a));
}
void* CEGUI__TreeItem_getTooltipText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TreeItem*)cls)->getTooltipText());
}
void* CEGUI__TreeItem_getOwnerWindow(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::TreeItem*)cls)->getOwnerWindow());
}
void CEGUI__TreeItem_draw(void* cls, void* a, void* b, float c, void* d){
	((CEGUI::TreeItem*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Rect*)b), ((float)c), ((CEGUI::Rect*)d));
}
void* CEGUI__TreeItem_getTreeItemFromIndex(void* cls, unsigned int a){
	return ((CEGUI::TreeItem*)cls)->getTreeItemFromIndex(((unsigned int)a));
}
void* CEGUI__TreeItem_getFont(void* cls){
	return ((CEGUI::TreeItem*)cls)->getFont();
}
unsigned int CEGUI__TreeItem_getID(void* cls){
	return ((CEGUI::TreeItem*)cls)->getID();
}
void* CEGUI__TreeItem_getSelectionBrushImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::TreeItem*)cls)->getSelectionBrushImage());
}
void* CEGUI__TreeItem_getText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::TreeItem*)cls)->getText());
}
void* CEGUI__TreeItem_getTextColours(void* cls){
	return new CEGUI::ColourRect(((CEGUI::TreeItem*)cls)->getTextColours());
}
void CEGUI__TreeItem_removeItem(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->removeItem(((CEGUI::TreeItem*)a));
}
void CEGUI__TreeItem_setTooltipText(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setTooltipText(*((CEGUI::String*)a));
}
void CEGUI__TreeItem_setUserData(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setUserData(((void*)a));
}
void CEGUI__TreeItem_setOwnerWindow(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setOwnerWindow(((CEGUI::Window*)a));
}
void* CEGUI__TreeItem_getButtonLocation(void* cls){
	return &((CEGUI::TreeItem*)cls)->getButtonLocation();
}
void CEGUI__TreeItem_setText(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setText(*((CEGUI::String*)a));
}
void CEGUI__TreeItem_setSelectionColours0(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setSelectionColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__TreeItem_setSelectionColours1(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::TreeItem*)cls)->setSelectionColours(*((CEGUI::colour*)a), *((CEGUI::colour*)b), *((CEGUI::colour*)c), *((CEGUI::colour*)d));
}
void CEGUI__TreeItem_setSelectionColours2(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setSelectionColours(*((CEGUI::colour*)a));
}
void CEGUI__TreeItem_setDisabled(void* cls, bool a){
	((CEGUI::TreeItem*)cls)->setDisabled(((bool)a));
}
void CEGUI__TreeItem_setFont0(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setFont(((CEGUI::Font*)a));
}
void CEGUI__TreeItem_setFont1(void* cls, void* a){
	((CEGUI::TreeItem*)cls)->setFont(*((CEGUI::String*)a));
}
bool CEGUI__TreeItem_getIsOpen(void* cls){
	return ((CEGUI::TreeItem*)cls)->getIsOpen();
}

//
// Begin class 'CEGUI::Titlebar'
//
void* CEGUI__Titlebar__Create(void* a, void* b){
	return new CEGUI::Titlebar(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Titlebar__Destroy(void* cls){
	delete (CEGUI::Titlebar*)cls;
}
void CEGUI__Titlebar_setDraggingEnabled(void* cls, bool a){
	((CEGUI::Titlebar*)cls)->setDraggingEnabled(((bool)a));
}
bool CEGUI__Titlebar_isDraggingEnabled(void* cls){
	return ((CEGUI::Titlebar*)cls)->isDraggingEnabled();
}

//
// Begin class 'CEGUI::WidgetComponent'
//
void* CEGUI__WidgetComponent__Create0(){
	return new CEGUI::WidgetComponent();
}
void* CEGUI__WidgetComponent__Create1(void* a, void* b, void* c, void* d){
	return new CEGUI::WidgetComponent(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), *((CEGUI::String*)d));
}
void CEGUI__WidgetComponent__Destroy(void* cls){
	delete (CEGUI::WidgetComponent*)cls;
}
void* CEGUI__WidgetComponent_getWindowRendererType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetComponent*)cls)->getWindowRendererType());
}
void* CEGUI__WidgetComponent_getWidgetNameSuffix(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetComponent*)cls)->getWidgetNameSuffix());
}
void* CEGUI__WidgetComponent_getBaseWidgetType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetComponent*)cls)->getBaseWidgetType());
}
void CEGUI__WidgetComponent_setWindowRendererType(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->setWindowRendererType(*((CEGUI::String*)a));
}
void CEGUI__WidgetComponent_setWidgetNameSuffix(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->setWidgetNameSuffix(*((CEGUI::String*)a));
}
void CEGUI__WidgetComponent_clearPropertyInitialisers(void* cls){
	((CEGUI::WidgetComponent*)cls)->clearPropertyInitialisers();
}
void CEGUI__WidgetComponent_create(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->create(*((CEGUI::Window*)a));
}
unsigned int CEGUI__WidgetComponent_getHorizontalWidgetAlignment(void* cls){
	return ((CEGUI::WidgetComponent*)cls)->getHorizontalWidgetAlignment();
}
unsigned int CEGUI__WidgetComponent_getVerticalWidgetAlignment(void* cls){
	return ((CEGUI::WidgetComponent*)cls)->getVerticalWidgetAlignment();
}
void* CEGUI__WidgetComponent_findPropertyInitialiser(void* cls, void* a){
	return const_cast<CEGUI::PropertyInitialiser*>(((CEGUI::WidgetComponent*)cls)->findPropertyInitialiser(*((CEGUI::String*)a)));
}
void* CEGUI__WidgetComponent_getComponentArea(void* cls){
	return const_cast<CEGUI::ComponentArea*>(&((CEGUI::WidgetComponent*)cls)->getComponentArea());
}
void CEGUI__WidgetComponent_setVerticalWidgetAlignment(void* cls, unsigned int a){
	((CEGUI::WidgetComponent*)cls)->setVerticalWidgetAlignment(((CEGUI::VerticalAlignment)a));
}
void CEGUI__WidgetComponent_writeXMLToStream(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__WidgetComponent_setComponentArea(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->setComponentArea(*((CEGUI::ComponentArea*)a));
}
void CEGUI__WidgetComponent_setHorizontalWidgetAlignment(void* cls, unsigned int a){
	((CEGUI::WidgetComponent*)cls)->setHorizontalWidgetAlignment(((CEGUI::HorizontalAlignment)a));
}
void* CEGUI__WidgetComponent_getWidgetLookName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetComponent*)cls)->getWidgetLookName());
}
void CEGUI__WidgetComponent_addPropertyInitialiser(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->addPropertyInitialiser(*((CEGUI::PropertyInitialiser*)a));
}
void CEGUI__WidgetComponent_setWidgetLookName(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->setWidgetLookName(*((CEGUI::String*)a));
}
void CEGUI__WidgetComponent_setBaseWidgetType(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->setBaseWidgetType(*((CEGUI::String*)a));
}
void CEGUI__WidgetComponent_layout(void* cls, void* a){
	((CEGUI::WidgetComponent*)cls)->layout(*((CEGUI::Window*)a));
}

//
// Begin class 'CEGUI::WindowRendererManager'
//
void* CEGUI__WindowRendererManager__Create(){
	return new CEGUI::WindowRendererManager();
}
void CEGUI__WindowRendererManager__Destroy(void* cls){
	delete (CEGUI::WindowRendererManager*)cls;
}
void* CEGUI__WindowRendererManager_createWindowRenderer(void* cls, void* a){
	return ((CEGUI::WindowRendererManager*)cls)->createWindowRenderer(*((CEGUI::String*)a));
}
bool CEGUI__WindowRendererManager_isFactoryPresent(void* cls, void* a){
	return ((CEGUI::WindowRendererManager*)cls)->isFactoryPresent(*((CEGUI::String*)a));
}
void* CEGUI__WindowRendererManager_getFactory(void* cls, void* a){
	return ((CEGUI::WindowRendererManager*)cls)->getFactory(*((CEGUI::String*)a));
}
void CEGUI__WindowRendererManager_destroyWindowRenderer(void* cls, void* a){
	((CEGUI::WindowRendererManager*)cls)->destroyWindowRenderer(((CEGUI::WindowRenderer*)a));
}
void CEGUI__WindowRendererManager_removeFactory(void* cls, void* a){
	((CEGUI::WindowRendererManager*)cls)->removeFactory(*((CEGUI::String*)a));
}
void* CEGUI__WindowRendererManager_getSingleton(void* cls){
	return &((CEGUI::WindowRendererManager*)cls)->getSingleton();
}
void* CEGUI__WindowRendererManager_getSingletonPtr(void* cls){
	return ((CEGUI::WindowRendererManager*)cls)->getSingletonPtr();
}
void CEGUI__WindowRendererManager_addFactory(void* cls, void* a){
	((CEGUI::WindowRendererManager*)cls)->addFactory(((CEGUI::WindowRendererFactory*)a));
}

//
// Begin class 'CEGUI::Property'
//
void CEGUI__Property__Destroy(void* cls){
	delete (CEGUI::Property*)cls;
}
void* CEGUI__Property_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Property*)cls)->getName());
}
void* CEGUI__Property_getDefault(void* cls, void* a){
	return new CEGUI::String(((CEGUI::Property*)cls)->getDefault(((CEGUI::PropertyReceiver*)a)));
}
void* CEGUI__Property_getHelp(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Property*)cls)->getHelp());
}
void CEGUI__Property_writeXMLToStream(void* cls, void* a, void* b){
	((CEGUI::Property*)cls)->writeXMLToStream(((CEGUI::PropertyReceiver*)a), *((CEGUI::XMLSerializer*)b));
}
bool CEGUI__Property_isDefault(void* cls, void* a){
	return ((CEGUI::Property*)cls)->isDefault(((CEGUI::PropertyReceiver*)a));
}

//
// Begin class 'CEGUI::WindowRendererFactory'
//
void CEGUI__WindowRendererFactory__Destroy(void* cls){
	delete (CEGUI::WindowRendererFactory*)cls;
}
void* CEGUI__WindowRendererFactory_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowRendererFactory*)cls)->getName());
}

//
// Begin class 'CEGUI::FactoryModule'
//
void* CEGUI__FactoryModule__Create(void* a){
	return new CEGUI::FactoryModule(*((CEGUI::String*)a));
}
void CEGUI__FactoryModule__Destroy(void* cls){
	delete (CEGUI::FactoryModule*)cls;
}
void CEGUI__FactoryModule_registerFactory(void* cls, void* a){
	((CEGUI::FactoryModule*)cls)->registerFactory(*((CEGUI::String*)a));
}
unsigned int CEGUI__FactoryModule_registerAllFactories(void* cls){
	return ((CEGUI::FactoryModule*)cls)->registerAllFactories();
}

//
// Begin class 'CEGUI::ScrolledItemListBase'
//
void CEGUI__ScrolledItemListBase__Destroy(void* cls){
	delete (CEGUI::ScrolledItemListBase*)cls;
}
bool CEGUI__ScrolledItemListBase_isVertScrollbarAlwaysShown(void* cls){
	return ((CEGUI::ScrolledItemListBase*)cls)->isVertScrollbarAlwaysShown();
}
void CEGUI__ScrolledItemListBase_ensureItemIsVisibleVert(void* cls, void* a){
	((CEGUI::ScrolledItemListBase*)cls)->ensureItemIsVisibleVert(*((CEGUI::ItemEntry*)a));
}
void CEGUI__ScrolledItemListBase_setShowHorzScrollbar(void* cls, bool a){
	((CEGUI::ScrolledItemListBase*)cls)->setShowHorzScrollbar(((bool)a));
}
void* CEGUI__ScrolledItemListBase_getHorzScrollbar(void* cls){
	return ((CEGUI::ScrolledItemListBase*)cls)->getHorzScrollbar();
}
void CEGUI__ScrolledItemListBase_initialiseComponents(void* cls){
	((CEGUI::ScrolledItemListBase*)cls)->initialiseComponents();
}
void CEGUI__ScrolledItemListBase_setShowVertScrollbar(void* cls, bool a){
	((CEGUI::ScrolledItemListBase*)cls)->setShowVertScrollbar(((bool)a));
}
bool CEGUI__ScrolledItemListBase_isHorzScrollbarAlwaysShown(void* cls){
	return ((CEGUI::ScrolledItemListBase*)cls)->isHorzScrollbarAlwaysShown();
}
void CEGUI__ScrolledItemListBase_ensureItemIsVisibleHorz(void* cls, void* a){
	((CEGUI::ScrolledItemListBase*)cls)->ensureItemIsVisibleHorz(*((CEGUI::ItemEntry*)a));
}
void* CEGUI__ScrolledItemListBase_getVertScrollbar(void* cls){
	return ((CEGUI::ScrolledItemListBase*)cls)->getVertScrollbar();
}

//
// Begin class 'CEGUI::ActivationEventArgs'
//
void* CEGUI__ActivationEventArgs__Create(void* a){
	return new CEGUI::ActivationEventArgs(((CEGUI::Window*)a));
}
void CEGUI__ActivationEventArgs__Destroy(void* cls){
	delete (CEGUI::ActivationEventArgs*)cls;
}

//
// Begin class 'CEGUI::ListboxWindowRenderer'
//
void CEGUI__ListboxWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ListboxWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::ScrolledContainer'
//
void* CEGUI__ScrolledContainer__Create(void* a, void* b){
	return new CEGUI::ScrolledContainer(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ScrolledContainer__Destroy(void* cls){
	delete (CEGUI::ScrolledContainer*)cls;
}
void* CEGUI__ScrolledContainer_getChildExtentsArea(void* cls){
	return new CEGUI::Rect(((CEGUI::ScrolledContainer*)cls)->getChildExtentsArea());
}
bool CEGUI__ScrolledContainer_isContentPaneAutoSized(void* cls){
	return ((CEGUI::ScrolledContainer*)cls)->isContentPaneAutoSized();
}
void CEGUI__ScrolledContainer_setContentArea(void* cls, void* a){
	((CEGUI::ScrolledContainer*)cls)->setContentArea(*((CEGUI::Rect*)a));
}
void* CEGUI__ScrolledContainer_getContentArea(void* cls){
	return const_cast<CEGUI::Rect*>(&((CEGUI::ScrolledContainer*)cls)->getContentArea());
}
void CEGUI__ScrolledContainer_setContentPaneAutoSized(void* cls, bool a){
	((CEGUI::ScrolledContainer*)cls)->setContentPaneAutoSized(((bool)a));
}
void* CEGUI__ScrolledContainer_getUnclippedInnerRect_impl(void* cls){
	return new CEGUI::Rect(((CEGUI::ScrolledContainer*)cls)->getUnclippedInnerRect_impl());
}

//
// Begin class 'CEGUI::ImageryComponent'
//
void CEGUI__ImageryComponent__Destroy(void* cls){
	delete (CEGUI::ImageryComponent*)cls;
}
void CEGUI__ImageryComponent_setImagePropertySource(void* cls, void* a){
	((CEGUI::ImageryComponent*)cls)->setImagePropertySource(*((CEGUI::String*)a));
}
unsigned int CEGUI__ImageryComponent_getVerticalFormatting(void* cls){
	return ((CEGUI::ImageryComponent*)cls)->getVerticalFormatting();
}
void CEGUI__ImageryComponent_setImage0(void* cls, void* a){
	((CEGUI::ImageryComponent*)cls)->setImage(((CEGUI::Image*)a));
}
void CEGUI__ImageryComponent_setImage1(void* cls, void* a, void* b){
	((CEGUI::ImageryComponent*)cls)->setImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
unsigned int CEGUI__ImageryComponent_getHorizontalFormatting(void* cls){
	return ((CEGUI::ImageryComponent*)cls)->getHorizontalFormatting();
}
bool CEGUI__ImageryComponent_isImageFetchedFromProperty(void* cls){
	return ((CEGUI::ImageryComponent*)cls)->isImageFetchedFromProperty();
}
void CEGUI__ImageryComponent_setVerticalFormatting(void* cls, unsigned int a){
	((CEGUI::ImageryComponent*)cls)->setVerticalFormatting(((CEGUI::VerticalFormatting)a));
}
void CEGUI__ImageryComponent_writeXMLToStream(void* cls, void* a){
	((CEGUI::ImageryComponent*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void* CEGUI__ImageryComponent_getImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::ImageryComponent*)cls)->getImage());
}
void* CEGUI__ImageryComponent_getImagePropertySource(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ImageryComponent*)cls)->getImagePropertySource());
}
void CEGUI__ImageryComponent_setHorizontalFormatting(void* cls, unsigned int a){
	((CEGUI::ImageryComponent*)cls)->setHorizontalFormatting(((CEGUI::HorizontalFormatting)a));
}

//
// Begin class 'CEGUI::Listbox'
//
void* CEGUI__Listbox__Create(void* a, void* b){
	return new CEGUI::Listbox(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Listbox__Destroy(void* cls){
	delete (CEGUI::Listbox*)cls;
}
void* CEGUI__Listbox_getFirstSelectedItem(void* cls){
	return ((CEGUI::Listbox*)cls)->getFirstSelectedItem();
}
void CEGUI__Listbox_setMultiselectEnabled(void* cls, bool a){
	((CEGUI::Listbox*)cls)->setMultiselectEnabled(((bool)a));
}
bool CEGUI__Listbox_isItemTooltipsEnabled(void* cls){
	return ((CEGUI::Listbox*)cls)->isItemTooltipsEnabled();
}
bool CEGUI__Listbox_isMultiselectEnabled(void* cls){
	return ((CEGUI::Listbox*)cls)->isMultiselectEnabled();
}
void CEGUI__Listbox_initialiseComponents(void* cls){
	((CEGUI::Listbox*)cls)->initialiseComponents();
}
void CEGUI__Listbox_setItemSelectState0(void* cls, void* a, bool b){
	((CEGUI::Listbox*)cls)->setItemSelectState(((CEGUI::ListboxItem*)a), ((bool)b));
}
void CEGUI__Listbox_setItemSelectState1(void* cls, unsigned int a, bool b){
	((CEGUI::Listbox*)cls)->setItemSelectState(((unsigned int)a), ((bool)b));
}
unsigned int CEGUI__Listbox_getItemCount(void* cls){
	return ((CEGUI::Listbox*)cls)->getItemCount();
}
unsigned int CEGUI__Listbox_getSelectedCount(void* cls){
	return ((CEGUI::Listbox*)cls)->getSelectedCount();
}
void CEGUI__Listbox_clearAllSelections(void* cls){
	((CEGUI::Listbox*)cls)->clearAllSelections();
}
void CEGUI__Listbox_resetList(void* cls){
	((CEGUI::Listbox*)cls)->resetList();
}
void CEGUI__Listbox_setShowHorzScrollbar(void* cls, bool a){
	((CEGUI::Listbox*)cls)->setShowHorzScrollbar(((bool)a));
}
bool CEGUI__Listbox_isSortEnabled(void* cls){
	return ((CEGUI::Listbox*)cls)->isSortEnabled();
}
void* CEGUI__Listbox_getHorzScrollbar(void* cls){
	return ((CEGUI::Listbox*)cls)->getHorzScrollbar();
}
void* CEGUI__Listbox_findItemWithText(void* cls, void* a, void* b){
	return ((CEGUI::Listbox*)cls)->findItemWithText(*((CEGUI::String*)a), ((CEGUI::ListboxItem*)b));
}
void* CEGUI__Listbox_getListRenderArea(void* cls){
	return new CEGUI::Rect(((CEGUI::Listbox*)cls)->getListRenderArea());
}
bool CEGUI__Listbox_isItemSelected(void* cls, unsigned int a){
	return ((CEGUI::Listbox*)cls)->isItemSelected(((unsigned int)a));
}
float CEGUI__Listbox_getTotalItemsHeight(void* cls){
	return ((CEGUI::Listbox*)cls)->getTotalItemsHeight();
}
bool CEGUI__Listbox_isVertScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Listbox*)cls)->isVertScrollbarAlwaysShown();
}
float CEGUI__Listbox_getWidestItemWidth(void* cls){
	return ((CEGUI::Listbox*)cls)->getWidestItemWidth();
}
void CEGUI__Listbox_insertItem(void* cls, void* a, void* b){
	((CEGUI::Listbox*)cls)->insertItem(((CEGUI::ListboxItem*)a), ((CEGUI::ListboxItem*)b));
}
void CEGUI__Listbox_addItem(void* cls, void* a){
	((CEGUI::Listbox*)cls)->addItem(((CEGUI::ListboxItem*)a));
}
bool CEGUI__Listbox_isHorzScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Listbox*)cls)->isHorzScrollbarAlwaysShown();
}
void CEGUI__Listbox_removeItem(void* cls, void* a){
	((CEGUI::Listbox*)cls)->removeItem(((CEGUI::ListboxItem*)a));
}
bool CEGUI__Listbox_isListboxItemInList(void* cls, void* a){
	return ((CEGUI::Listbox*)cls)->isListboxItemInList(((CEGUI::ListboxItem*)a));
}
void* CEGUI__Listbox_getNextSelected(void* cls, void* a){
	return ((CEGUI::Listbox*)cls)->getNextSelected(((CEGUI::ListboxItem*)a));
}
void CEGUI__Listbox_ensureItemIsVisible0(void* cls, unsigned int a){
	((CEGUI::Listbox*)cls)->ensureItemIsVisible(((unsigned int)a));
}
void CEGUI__Listbox_ensureItemIsVisible1(void* cls, void* a){
	((CEGUI::Listbox*)cls)->ensureItemIsVisible(((CEGUI::ListboxItem*)a));
}
void CEGUI__Listbox_handleUpdatedItemData(void* cls){
	((CEGUI::Listbox*)cls)->handleUpdatedItemData();
}
void* CEGUI__Listbox_getListboxItemFromIndex(void* cls, unsigned int a){
	return ((CEGUI::Listbox*)cls)->getListboxItemFromIndex(((unsigned int)a));
}
void CEGUI__Listbox_setSortingEnabled(void* cls, bool a){
	((CEGUI::Listbox*)cls)->setSortingEnabled(((bool)a));
}
unsigned int CEGUI__Listbox_getItemIndex(void* cls, void* a){
	return ((CEGUI::Listbox*)cls)->getItemIndex(((CEGUI::ListboxItem*)a));
}
void CEGUI__Listbox_setItemTooltipsEnabled(void* cls, bool a){
	((CEGUI::Listbox*)cls)->setItemTooltipsEnabled(((bool)a));
}
void CEGUI__Listbox_setShowVertScrollbar(void* cls, bool a){
	((CEGUI::Listbox*)cls)->setShowVertScrollbar(((bool)a));
}
void* CEGUI__Listbox_getItemAtPoint(void* cls, void* a){
	return ((CEGUI::Listbox*)cls)->getItemAtPoint(*((CEGUI::Vector2*)a));
}
void* CEGUI__Listbox_getVertScrollbar(void* cls){
	return ((CEGUI::Listbox*)cls)->getVertScrollbar();
}

//
// Begin class 'CEGUI::RenderEffectFactory'
//
void CEGUI__RenderEffectFactory__Destroy(void* cls){
	delete (CEGUI::RenderEffectFactory*)cls;
}

//
// Begin class 'CEGUI::AnimationInstance'
//
void* CEGUI__AnimationInstance__Create(void* a){
	return new CEGUI::AnimationInstance(((CEGUI::Animation*)a));
}
void CEGUI__AnimationInstance__Destroy(void* cls){
	delete (CEGUI::AnimationInstance*)cls;
}
float CEGUI__AnimationInstance_getMaxStepDeltaClamp(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getMaxStepDeltaClamp();
}
bool CEGUI__AnimationInstance_getSkipNextStep(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getSkipNextStep();
}
void* CEGUI__AnimationInstance_getTarget(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getTarget();
}
void CEGUI__AnimationInstance_purgeSavedPropertyValues(void* cls){
	((CEGUI::AnimationInstance*)cls)->purgeSavedPropertyValues();
}
void CEGUI__AnimationInstance_unsubscribeAutoConnections(void* cls){
	((CEGUI::AnimationInstance*)cls)->unsubscribeAutoConnections();
}
float CEGUI__AnimationInstance_getMaxStepDeltaSkip(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getMaxStepDeltaSkip();
}
void CEGUI__AnimationInstance_setMaxStepDeltaSkip(void* cls, float a){
	((CEGUI::AnimationInstance*)cls)->setMaxStepDeltaSkip(((float)a));
}
bool CEGUI__AnimationInstance_handlePause(void* cls, void* a){
	return ((CEGUI::AnimationInstance*)cls)->handlePause(*((CEGUI::EventArgs*)a));
}
void CEGUI__AnimationInstance_pause(void* cls){
	((CEGUI::AnimationInstance*)cls)->pause();
}
void CEGUI__AnimationInstance_setMaxStepDeltaClamp(void* cls, float a){
	((CEGUI::AnimationInstance*)cls)->setMaxStepDeltaClamp(((float)a));
}
bool CEGUI__AnimationInstance_handleStart(void* cls, void* a){
	return ((CEGUI::AnimationInstance*)cls)->handleStart(*((CEGUI::EventArgs*)a));
}
void* CEGUI__AnimationInstance_getEventReceiver(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getEventReceiver();
}
void CEGUI__AnimationInstance_start(void* cls, bool a){
	((CEGUI::AnimationInstance*)cls)->start(((bool)a));
}
bool CEGUI__AnimationInstance_handleUnpause(void* cls, void* a){
	return ((CEGUI::AnimationInstance*)cls)->handleUnpause(*((CEGUI::EventArgs*)a));
}
bool CEGUI__AnimationInstance_handleTogglePause(void* cls, void* a){
	return ((CEGUI::AnimationInstance*)cls)->handleTogglePause(*((CEGUI::EventArgs*)a));
}
void CEGUI__AnimationInstance_setTargetWindow(void* cls, void* a){
	((CEGUI::AnimationInstance*)cls)->setTargetWindow(((CEGUI::Window*)a));
}
void CEGUI__AnimationInstance_savePropertyValue(void* cls, void* a){
	((CEGUI::AnimationInstance*)cls)->savePropertyValue(*((CEGUI::String*)a));
}
void CEGUI__AnimationInstance_unpause(void* cls, bool a){
	((CEGUI::AnimationInstance*)cls)->unpause(((bool)a));
}
void CEGUI__AnimationInstance_setSkipNextStep(void* cls, bool a){
	((CEGUI::AnimationInstance*)cls)->setSkipNextStep(((bool)a));
}
void CEGUI__AnimationInstance_setEventSender(void* cls, void* a){
	((CEGUI::AnimationInstance*)cls)->setEventSender(((CEGUI::EventSet*)a));
}
void* CEGUI__AnimationInstance_getSavedPropertyValue(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::AnimationInstance*)cls)->getSavedPropertyValue(*((CEGUI::String*)a)));
}
void CEGUI__AnimationInstance_setTarget(void* cls, void* a){
	((CEGUI::AnimationInstance*)cls)->setTarget(((CEGUI::PropertySet*)a));
}
void CEGUI__AnimationInstance_stop(void* cls){
	((CEGUI::AnimationInstance*)cls)->stop();
}
bool CEGUI__AnimationInstance_handleStop(void* cls, void* a){
	return ((CEGUI::AnimationInstance*)cls)->handleStop(*((CEGUI::EventArgs*)a));
}
void* CEGUI__AnimationInstance_getEventSender(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getEventSender();
}
void CEGUI__AnimationInstance_step(void* cls, float a){
	((CEGUI::AnimationInstance*)cls)->step(((float)a));
}
void CEGUI__AnimationInstance_togglePause(void* cls, bool a){
	((CEGUI::AnimationInstance*)cls)->togglePause(((bool)a));
}
void CEGUI__AnimationInstance_setPosition(void* cls, float a){
	((CEGUI::AnimationInstance*)cls)->setPosition(((float)a));
}
float CEGUI__AnimationInstance_getPosition(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getPosition();
}
bool CEGUI__AnimationInstance_isRunning(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->isRunning();
}
float CEGUI__AnimationInstance_getSpeed(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getSpeed();
}
void* CEGUI__AnimationInstance_getDefinition(void* cls){
	return ((CEGUI::AnimationInstance*)cls)->getDefinition();
}
void CEGUI__AnimationInstance_setSpeed(void* cls, float a){
	((CEGUI::AnimationInstance*)cls)->setSpeed(((float)a));
}
void CEGUI__AnimationInstance_setEventReceiver(void* cls, void* a){
	((CEGUI::AnimationInstance*)cls)->setEventReceiver(((CEGUI::EventSet*)a));
}

//
// Begin class 'CEGUI::Window'
//
void* CEGUI__Window__Create0(void* a, void* b){
	return new CEGUI::Window(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Window__Destroy(void* cls){
	delete (CEGUI::Window*)cls;
}
bool CEGUI__Window_testClassName(void* cls, void* a){
	return ((CEGUI::Window*)cls)->testClassName(*((CEGUI::String*)a));
}
void* CEGUI__Window_getMaxSize(void* cls){
	return const_cast<CEGUI::UVector2*>(&((CEGUI::Window*)cls)->getMaxSize());
}
void CEGUI__Window_show(void* cls){
	((CEGUI::Window*)cls)->show();
}
void* CEGUI__Window_getYPosition(void* cls){
	return const_cast<CEGUI::UDim*>(&((CEGUI::Window*)cls)->getYPosition());
}
void* CEGUI__Window_getChildAtIdx(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->getChildAtIdx(((unsigned int)a));
}
void CEGUI__Window_cloneChildWidgetsTo(void* cls, void* a){
	((CEGUI::Window*)cls)->cloneChildWidgetsTo(*((CEGUI::Window*)a));
}
void CEGUI__Window_addChildWindow0(void* cls, void* a){
	((CEGUI::Window*)cls)->addChildWindow(*((CEGUI::String*)a));
}
void CEGUI__Window_addChildWindow1(void* cls, void* a){
	((CEGUI::Window*)cls)->addChildWindow(((CEGUI::Window*)a));
}
void* CEGUI__Window_getSize(void* cls){
	return new CEGUI::UVector2(((CEGUI::Window*)cls)->getSize());
}
bool CEGUI__Window_isUsingDefaultTooltip(void* cls){
	return ((CEGUI::Window*)cls)->isUsingDefaultTooltip();
}
void CEGUI__Window_getRenderingContext(void* cls, void* a){
	((CEGUI::Window*)cls)->getRenderingContext(*((CEGUI::RenderingContext*)a));
}
bool CEGUI__Window_inheritsAlpha(void* cls){
	return ((CEGUI::Window*)cls)->inheritsAlpha();
}
void* CEGUI__Window_getRenderingSurface(void* cls){
	return ((CEGUI::Window*)cls)->getRenderingSurface();
}
void* CEGUI__Window_getUserString(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getUserString(*((CEGUI::String*)a)));
}
void CEGUI__Window_setYPosition(void* cls, void* a){
	((CEGUI::Window*)cls)->setYPosition(*((CEGUI::UDim*)a));
}
void* CEGUI__Window_getBiDiVisualMapping(void* cls){
	return const_cast<CEGUI::BiDiVisualMapping*>(((CEGUI::Window*)cls)->getBiDiVisualMapping());
}
void CEGUI__Window_setWritingXMLAllowed(void* cls, bool a){
	((CEGUI::Window*)cls)->setWritingXMLAllowed(((bool)a));
}
bool CEGUI__Window_wantsMultiClickEvents(void* cls){
	return ((CEGUI::Window*)cls)->wantsMultiClickEvents();
}
void* CEGUI__Window_getUnprojectedPosition(void* cls, void* a){
	return new CEGUI::Vector2(((CEGUI::Window*)cls)->getUnprojectedPosition(*((CEGUI::Vector2*)a)));
}
void CEGUI__Window_setModalState(void* cls, bool a){
	((CEGUI::Window*)cls)->setModalState(((bool)a));
}
void* CEGUI__Window_getActiveSibling(void* cls){
	return ((CEGUI::Window*)cls)->getActiveSibling();
}
void CEGUI__Window_setXPosition(void* cls, void* a){
	((CEGUI::Window*)cls)->setXPosition(*((CEGUI::UDim*)a));
}
void CEGUI__Window_notifyDragDropItemDropped(void* cls, void* a){
	((CEGUI::Window*)cls)->notifyDragDropItemDropped(((CEGUI::DragContainer*)a));
}
void* CEGUI__Window_getWindowRendererName(void* cls){
	return new CEGUI::String(((CEGUI::Window*)cls)->getWindowRendererName());
}
void CEGUI__Window_appendText(void* cls, void* a){
	((CEGUI::Window*)cls)->appendText(*((CEGUI::String*)a));
}
void* CEGUI__Window_getRenderedString(void* cls){
	return const_cast<CEGUI::RenderedString*>(&((CEGUI::Window*)cls)->getRenderedString());
}
float CEGUI__Window_getEffectiveAlpha(void* cls){
	return ((CEGUI::Window*)cls)->getEffectiveAlpha();
}
void* CEGUI__Window_getChildAtPosition(void* cls, void* a){
	return ((CEGUI::Window*)cls)->getChildAtPosition(*((CEGUI::Vector2*)a));
}
bool CEGUI__Window_isNonClientWindow(void* cls){
	return ((CEGUI::Window*)cls)->isNonClientWindow();
}
void CEGUI__Window_setWindowRenderer(void* cls, void* a){
	((CEGUI::Window*)cls)->setWindowRenderer(*((CEGUI::String*)a));
}
bool CEGUI__Window_isAutoWindow(void* cls){
	return ((CEGUI::Window*)cls)->isAutoWindow();
}
void* CEGUI__Window_getMargin(void* cls){
	return const_cast<CEGUI::UBox*>(&((CEGUI::Window*)cls)->getMargin());
}
bool CEGUI__Window_isAlwaysOnTop(void* cls){
	return ((CEGUI::Window*)cls)->isAlwaysOnTop();
}
void* CEGUI__Window_getUnclippedInnerRect_impl(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getUnclippedInnerRect_impl());
}
bool CEGUI__Window_isDragDropTarget(void* cls){
	return ((CEGUI::Window*)cls)->isDragDropTarget();
}
void CEGUI__Window_setMinSize(void* cls, void* a){
	((CEGUI::Window*)cls)->setMinSize(*((CEGUI::UVector2*)a));
}
void CEGUI__Window_initialiseComponents(void* cls){
	((CEGUI::Window*)cls)->initialiseComponents();
}
void CEGUI__Window_moveToBack(void* cls){
	((CEGUI::Window*)cls)->moveToBack();
}
void CEGUI__Window_releaseInput(void* cls){
	((CEGUI::Window*)cls)->releaseInput();
}
void CEGUI__Window_moveInFront(void* cls, void* a){
	((CEGUI::Window*)cls)->moveInFront(((CEGUI::Window*)a));
}
void CEGUI__Window_setHorizontalAlignment(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->setHorizontalAlignment(((CEGUI::HorizontalAlignment)a));
}
void* CEGUI__Window_getClipRect(void* cls, bool a){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getClipRect(((bool)a)));
}
float CEGUI__Window_getAlpha(void* cls){
	return ((CEGUI::Window*)cls)->getAlpha();
}
void CEGUI__Window_setSize(void* cls, void* a){
	((CEGUI::Window*)cls)->setSize(*((CEGUI::UVector2*)a));
}
void CEGUI__Window_insertText(void* cls, void* a, unsigned int b){
	((CEGUI::Window*)cls)->insertText(*((CEGUI::String*)a), ((unsigned int)b));
}
void CEGUI__Window_activate(void* cls){
	((CEGUI::Window*)cls)->activate();
}
void CEGUI__Window_setArea0(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::Window*)cls)->setArea(*((CEGUI::UDim*)a), *((CEGUI::UDim*)b), *((CEGUI::UDim*)c), *((CEGUI::UDim*)d));
}
void CEGUI__Window_setArea1(void* cls, void* a, void* b){
	((CEGUI::Window*)cls)->setArea(*((CEGUI::UVector2*)a), *((CEGUI::UVector2*)b));
}
void CEGUI__Window_setArea2(void* cls, void* a){
	((CEGUI::Window*)cls)->setArea(*((CEGUI::URect*)a));
}
bool CEGUI__Window_isWritingXMLAllowed(void* cls){
	return ((CEGUI::Window*)cls)->isWritingXMLAllowed();
}
bool CEGUI__Window_restoresOldCapture(void* cls){
	return ((CEGUI::Window*)cls)->restoresOldCapture();
}
bool CEGUI__Window_isTextParsingEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isTextParsingEnabled();
}
void CEGUI__Window_setDestroyedByParent(void* cls, bool a){
	((CEGUI::Window*)cls)->setDestroyedByParent(((bool)a));
}
void CEGUI__Window_setTextParsingEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setTextParsingEnabled(((bool)a));
}
bool CEGUI__Window_isCapturedByThis(void* cls){
	return ((CEGUI::Window*)cls)->isCapturedByThis();
}
void CEGUI__Window_setMouseCursor0(void* cls, void* a){
	((CEGUI::Window*)cls)->setMouseCursor(((CEGUI::Image*)a));
}
void CEGUI__Window_setMouseCursor1(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->setMouseCursor(((CEGUI::MouseCursorImage)a));
}
void CEGUI__Window_setMouseCursor2(void* cls, void* a, void* b){
	((CEGUI::Window*)cls)->setMouseCursor(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Window_hide(void* cls){
	((CEGUI::Window*)cls)->hide();
}
void* CEGUI__Window_getUserData(void* cls){
	return ((CEGUI::Window*)cls)->getUserData();
}
void CEGUI__Window_setAutoRepeatRate(void* cls, float a){
	((CEGUI::Window*)cls)->setAutoRepeatRate(((float)a));
}
void CEGUI__Window_deactivate(void* cls){
	((CEGUI::Window*)cls)->deactivate();
}
void* CEGUI__Window_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getName());
}
void CEGUI__Window_notifyDragDropItemLeaves(void* cls, void* a){
	((CEGUI::Window*)cls)->notifyDragDropItemLeaves(((CEGUI::DragContainer*)a));
}
bool CEGUI__Window_getModalState(void* cls){
	return ((CEGUI::Window*)cls)->getModalState();
}
void CEGUI__Window_setNonClientWindow(void* cls, bool a){
	((CEGUI::Window*)cls)->setNonClientWindow(((bool)a));
}
void* CEGUI__Window_getChildRecursive0(void* cls, void* a){
	return ((CEGUI::Window*)cls)->getChildRecursive(*((CEGUI::String*)a));
}
void* CEGUI__Window_getChildRecursive1(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->getChildRecursive(((unsigned int)a));
}
void CEGUI__Window_setRotation(void* cls, void* a){
	((CEGUI::Window*)cls)->setRotation(*((CEGUI::Vector3*)a));
}
void CEGUI__Window_notifyDragDropItemEnters(void* cls, void* a){
	((CEGUI::Window*)cls)->notifyDragDropItemEnters(((CEGUI::DragContainer*)a));
}
void CEGUI__Window_setUserString(void* cls, void* a, void* b){
	((CEGUI::Window*)cls)->setUserString(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__Window_getMouseCursor(void* cls, bool a){
	return const_cast<CEGUI::Image*>(((CEGUI::Window*)cls)->getMouseCursor(((bool)a)));
}
void CEGUI__Window_setRenderingSurface(void* cls, void* a){
	((CEGUI::Window*)cls)->setRenderingSurface(((CEGUI::RenderingSurface*)a));
}
void CEGUI__Window_setLookNFeel(void* cls, void* a){
	((CEGUI::Window*)cls)->setLookNFeel(*((CEGUI::String*)a));
}
void* CEGUI__Window_getCustomRenderedStringParser(void* cls){
	return ((CEGUI::Window*)cls)->getCustomRenderedStringParser();
}
void* CEGUI__Window_getActiveChild0(void* cls){
	return ((CEGUI::Window*)cls)->getActiveChild();
}
void* CEGUI__Window_getActiveChild1(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::Window*)cls)->getActiveChild());
}
bool CEGUI__Window_isMouseAutoRepeatEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isMouseAutoRepeatEnabled();
}
void CEGUI__Window_setVerticalAlignment(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->setVerticalAlignment(((CEGUI::VerticalAlignment)a));
}
void CEGUI__Window_setMargin(void* cls, void* a){
	((CEGUI::Window*)cls)->setMargin(*((CEGUI::UBox*)a));
}
bool CEGUI__Window_isZOrderingEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isZOrderingEnabled();
}
void* CEGUI__Window_getLookNFeel(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getLookNFeel());
}
void CEGUI__Window_setPosition(void* cls, void* a){
	((CEGUI::Window*)cls)->setPosition(*((CEGUI::UVector2*)a));
}
float CEGUI__Window_getAutoRepeatRate(void* cls){
	return ((CEGUI::Window*)cls)->getAutoRepeatRate();
}
bool CEGUI__Window_isChild0(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isChild(*((CEGUI::String*)a));
}
bool CEGUI__Window_isChild1(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->isChild(((unsigned int)a));
}
bool CEGUI__Window_isChild2(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isChild(((CEGUI::Window*)a));
}
bool CEGUI__Window_isActive(void* cls){
	return ((CEGUI::Window*)cls)->isActive();
}
void CEGUI__Window_setAlwaysOnTop(void* cls, bool a){
	((CEGUI::Window*)cls)->setAlwaysOnTop(((bool)a));
}
void CEGUI__Window_banPropertyFromXML0(void* cls, void* a){
	((CEGUI::Window*)cls)->banPropertyFromXML(*((CEGUI::String*)a));
}
void CEGUI__Window_banPropertyFromXML1(void* cls, void* a){
	((CEGUI::Window*)cls)->banPropertyFromXML(((CEGUI::Property*)a));
}
void* CEGUI__Window_getTooltip(void* cls){
	return ((CEGUI::Window*)cls)->getTooltip();
}
bool CEGUI__Window_isMouseInputPropagationEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isMouseInputPropagationEnabled();
}
bool CEGUI__Window_isAncestor0(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isAncestor(*((CEGUI::String*)a));
}
bool CEGUI__Window_isAncestor1(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->isAncestor(((unsigned int)a));
}
bool CEGUI__Window_isAncestor2(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isAncestor(((CEGUI::Window*)a));
}
void* CEGUI__Window_getInnerRectClipper(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getInnerRectClipper());
}
float CEGUI__Window_getParentPixelWidth(void* cls){
	return ((CEGUI::Window*)cls)->getParentPixelWidth();
}
bool CEGUI__Window_isPropertyBannedFromXML0(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isPropertyBannedFromXML(*((CEGUI::String*)a));
}
bool CEGUI__Window_isPropertyBannedFromXML1(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isPropertyBannedFromXML(((CEGUI::Property*)a));
}
bool CEGUI__Window_isVisible(void* cls, bool a){
	return ((CEGUI::Window*)cls)->isVisible(((bool)a));
}
bool CEGUI__Window_isCapturedByChild(void* cls){
	return ((CEGUI::Window*)cls)->isCapturedByChild();
}
bool CEGUI__Window_isHit(void* cls, void* a, bool b){
	return ((CEGUI::Window*)cls)->isHit(*((CEGUI::Vector2*)a), ((bool)b));
}
void* CEGUI__Window_getWindowRenderer(void* cls){
	return ((CEGUI::Window*)cls)->getWindowRenderer();
}
void* CEGUI__Window_getRootWindow0(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::Window*)cls)->getRootWindow());
}
void* CEGUI__Window_getRootWindow1(void* cls){
	return ((CEGUI::Window*)cls)->getRootWindow();
}
void CEGUI__Window_invalidate0(void* cls){
	((CEGUI::Window*)cls)->invalidate();
}
void CEGUI__Window_invalidate1(void* cls, bool a){
	((CEGUI::Window*)cls)->invalidate(((bool)a));
}
void CEGUI__Window_setTooltip(void* cls, void* a){
	((CEGUI::Window*)cls)->setTooltip(((CEGUI::Tooltip*)a));
}
void CEGUI__Window_setMouseAutoRepeatEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setMouseAutoRepeatEnabled(((bool)a));
}
void CEGUI__Window_render(void* cls){
	((CEGUI::Window*)cls)->render();
}
void* CEGUI__Window_getUnclippedRect(void* cls, bool a){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getUnclippedRect(((bool)a)));
}
void* CEGUI__Window_getUnclippedInnerRect(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getUnclippedInnerRect());
}
void* CEGUI__Window_getText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getText());
}
void CEGUI__Window_setTooltipType(void* cls, void* a){
	((CEGUI::Window*)cls)->setTooltipType(*((CEGUI::String*)a));
}
void* CEGUI__Window_getWidth(void* cls){
	return new CEGUI::UDim(((CEGUI::Window*)cls)->getWidth());
}
unsigned int CEGUI__Window_getUpdateMode(void* cls){
	return ((CEGUI::Window*)cls)->getUpdateMode();
}
void* CEGUI__Window_getRotation(void* cls){
	return const_cast<CEGUI::Vector3*>(&((CEGUI::Window*)cls)->getRotation());
}
float CEGUI__Window_getParentPixelHeight(void* cls){
	return ((CEGUI::Window*)cls)->getParentPixelHeight();
}
void CEGUI__Window_setWidth(void* cls, void* a){
	((CEGUI::Window*)cls)->setWidth(*((CEGUI::UDim*)a));
}
void CEGUI__Window_setTooltipText(void* cls, void* a){
	((CEGUI::Window*)cls)->setTooltipText(*((CEGUI::String*)a));
}
void CEGUI__Window_notifyScreenAreaChanged(void* cls, bool a){
	((CEGUI::Window*)cls)->notifyScreenAreaChanged(((bool)a));
}
void CEGUI__Window_setCustomRenderedStringParser(void* cls, void* a){
	((CEGUI::Window*)cls)->setCustomRenderedStringParser(((CEGUI::RenderedStringParser*)a));
}
void* CEGUI__Window_getGeometryBuffer(void* cls){
	return &((CEGUI::Window*)cls)->getGeometryBuffer();
}
void CEGUI__Window_setInheritsAlpha(void* cls, bool a){
	((CEGUI::Window*)cls)->setInheritsAlpha(((bool)a));
}
void CEGUI__Window_setMouseInputPropagationEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setMouseInputPropagationEnabled(((bool)a));
}
void* CEGUI__Window_getArea(void* cls){
	return const_cast<CEGUI::URect*>(&((CEGUI::Window*)cls)->getArea());
}
bool CEGUI__Window_isDisabled(void* cls, bool a){
	return ((CEGUI::Window*)cls)->isDisabled(((bool)a));
}
void* CEGUI__Window_getUnclippedOuterRect(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getUnclippedOuterRect());
}
void CEGUI__Window_setDragDropTarget(void* cls, bool a){
	((CEGUI::Window*)cls)->setDragDropTarget(((bool)a));
}
void* CEGUI__Window_getTextVisual(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getTextVisual());
}
void* CEGUI__Window_getChild0(void* cls, void* a){
	return ((CEGUI::Window*)cls)->getChild(*((CEGUI::String*)a));
}
void* CEGUI__Window_getChild1(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->getChild(((unsigned int)a));
}
void CEGUI__Window_setUsingAutoRenderingSurface(void* cls, bool a){
	((CEGUI::Window*)cls)->setUsingAutoRenderingSurface(((bool)a));
}
bool CEGUI__Window_isUsingAutoRenderingSurface(void* cls){
	return ((CEGUI::Window*)cls)->isUsingAutoRenderingSurface();
}
void CEGUI__Window_setRiseOnClickEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setRiseOnClickEnabled(((bool)a));
}
void CEGUI__Window_setEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setEnabled(((bool)a));
}
void* CEGUI__Window_getTargetRenderingSurface(void* cls){
	return &((CEGUI::Window*)cls)->getTargetRenderingSurface();
}
void* CEGUI__Window_getChildWindowContentArea(void* cls, bool a){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getChildWindowContentArea(((bool)a)));
}
bool CEGUI__Window_isDestroyedByParent(void* cls){
	return ((CEGUI::Window*)cls)->isDestroyedByParent();
}
void* CEGUI__Window_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getType());
}
bool CEGUI__Window_distributesCapturedInputs(void* cls){
	return ((CEGUI::Window*)cls)->distributesCapturedInputs();
}
void* CEGUI__Window_getCaptureWindow(void* cls){
	return ((CEGUI::Window*)cls)->getCaptureWindow();
}
void* CEGUI__Window_getHitTestRect(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getHitTestRect());
}
unsigned int CEGUI__Window_getVerticalAlignment(void* cls){
	return ((CEGUI::Window*)cls)->getVerticalAlignment();
}
void* CEGUI__Window_getPosition(void* cls){
	return const_cast<CEGUI::UVector2*>(&((CEGUI::Window*)cls)->getPosition());
}
void* CEGUI__Window_getOuterRectClipper(void* cls){
	return new CEGUI::Rect(((CEGUI::Window*)cls)->getOuterRectClipper());
}
bool CEGUI__Window_isClippedByParent(void* cls){
	return ((CEGUI::Window*)cls)->isClippedByParent();
}
void* CEGUI__Window_getParent(void* cls){
	return ((CEGUI::Window*)cls)->getParent();
}
bool CEGUI__Window_isRiseOnClickEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isRiseOnClickEnabled();
}
void* CEGUI__Window_getTargetChildAtPosition(void* cls, void* a, bool b){
	return ((CEGUI::Window*)cls)->getTargetChildAtPosition(*((CEGUI::Vector2*)a), ((bool)b));
}
void CEGUI__Window_setInheritsTooltipText(void* cls, bool a){
	((CEGUI::Window*)cls)->setInheritsTooltipText(((bool)a));
}
void CEGUI__Window_setUpdateMode(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->setUpdateMode(((CEGUI::WindowUpdateMode)a));
}
void* CEGUI__Window_getMinSize(void* cls){
	return const_cast<CEGUI::UVector2*>(&((CEGUI::Window*)cls)->getMinSize());
}
void CEGUI__Window_setZOrderingEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setZOrderingEnabled(((bool)a));
}
void CEGUI__Window_getRenderingContext_impl(void* cls, void* a){
	((CEGUI::Window*)cls)->getRenderingContext_impl(*((CEGUI::RenderingContext*)a));
}
void* CEGUI__Window_getRenderedStringParser(void* cls){
	return &((CEGUI::Window*)cls)->getRenderedStringParser();
}
void CEGUI__Window_setVisible(void* cls, bool a){
	((CEGUI::Window*)cls)->setVisible(((bool)a));
}
void CEGUI__Window_rename(void* cls, void* a){
	((CEGUI::Window*)cls)->rename(*((CEGUI::String*)a));
}
void CEGUI__Window_unbanPropertyFromXML0(void* cls, void* a){
	((CEGUI::Window*)cls)->unbanPropertyFromXML(*((CEGUI::String*)a));
}
void CEGUI__Window_unbanPropertyFromXML1(void* cls, void* a){
	((CEGUI::Window*)cls)->unbanPropertyFromXML(((CEGUI::Property*)a));
}
void CEGUI__Window_moveBehind(void* cls, void* a){
	((CEGUI::Window*)cls)->moveBehind(((CEGUI::Window*)a));
}
void* CEGUI__Window_getXPosition(void* cls){
	return const_cast<CEGUI::UDim*>(&((CEGUI::Window*)cls)->getXPosition());
}
void* CEGUI__Window_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::Window*)cls)->getPixelSize());
}
unsigned int CEGUI__Window_getID(void* cls){
	return ((CEGUI::Window*)cls)->getID();
}
bool CEGUI__Window_inheritsTooltipText(void* cls){
	return ((CEGUI::Window*)cls)->inheritsTooltipText();
}
void CEGUI__Window_enable(void* cls){
	((CEGUI::Window*)cls)->enable();
}
void CEGUI__Window_beginInitialisation(void* cls){
	((CEGUI::Window*)cls)->beginInitialisation();
}
void* CEGUI__Window_getFont(void* cls, bool a){
	return ((CEGUI::Window*)cls)->getFont(((bool)a));
}
float CEGUI__Window_getAutoRepeatDelay(void* cls){
	return ((CEGUI::Window*)cls)->getAutoRepeatDelay();
}
bool CEGUI__Window_isChildRecursive(void* cls, unsigned int a){
	return ((CEGUI::Window*)cls)->isChildRecursive(((unsigned int)a));
}
void CEGUI__Window_setRestoreCapture(void* cls, bool a){
	((CEGUI::Window*)cls)->setRestoreCapture(((bool)a));
}
unsigned int CEGUI__Window_getHorizontalAlignment(void* cls){
	return ((CEGUI::Window*)cls)->getHorizontalAlignment();
}
void CEGUI__Window_setDistributesCapturedInputs(void* cls, bool a){
	((CEGUI::Window*)cls)->setDistributesCapturedInputs(((bool)a));
}
void CEGUI__Window_setAutoRepeatDelay(void* cls, float a){
	((CEGUI::Window*)cls)->setAutoRepeatDelay(((float)a));
}
void* CEGUI__Window_getHeight(void* cls){
	return new CEGUI::UDim(((CEGUI::Window*)cls)->getHeight());
}
bool CEGUI__Window_isMousePassThroughEnabled(void* cls){
	return ((CEGUI::Window*)cls)->isMousePassThroughEnabled();
}
void CEGUI__Window_setFalagardType(void* cls, void* a, void* b){
	((CEGUI::Window*)cls)->setFalagardType(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Window_setAlpha(void* cls, float a){
	((CEGUI::Window*)cls)->setAlpha(((float)a));
}
void CEGUI__Window_endInitialisation(void* cls){
	((CEGUI::Window*)cls)->endInitialisation();
}
unsigned int CEGUI__Window_getChildCount(void* cls){
	return ((CEGUI::Window*)cls)->getChildCount();
}
void CEGUI__Window_writeXMLToStream(void* cls, void* a){
	((CEGUI::Window*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__Window_destroy(void* cls){
	((CEGUI::Window*)cls)->destroy();
}
void* CEGUI__Window_getTooltipText(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Window*)cls)->getTooltipText());
}
void CEGUI__Window_setMaxSize(void* cls, void* a){
	((CEGUI::Window*)cls)->setMaxSize(*((CEGUI::UVector2*)a));
}
void CEGUI__Window_setWantsMultiClickEvents(void* cls, bool a){
	((CEGUI::Window*)cls)->setWantsMultiClickEvents(((bool)a));
}
void CEGUI__Window_performChildWindowLayout(void* cls){
	((CEGUI::Window*)cls)->performChildWindowLayout();
}
void* CEGUI__Window_clone(void* cls, void* a, bool b){
	return ((CEGUI::Window*)cls)->clone(*((CEGUI::String*)a), ((bool)b));
}
void CEGUI__Window_update(void* cls, float a){
	((CEGUI::Window*)cls)->update(((float)a));
}
void CEGUI__Window_disable(void* cls){
	((CEGUI::Window*)cls)->disable();
}
void CEGUI__Window_setMousePassThroughEnabled(void* cls, bool a){
	((CEGUI::Window*)cls)->setMousePassThroughEnabled(((bool)a));
}
void CEGUI__Window_removeChildWindow0(void* cls, void* a){
	((CEGUI::Window*)cls)->removeChildWindow(*((CEGUI::String*)a));
}
void CEGUI__Window_removeChildWindow1(void* cls, void* a){
	((CEGUI::Window*)cls)->removeChildWindow(((CEGUI::Window*)a));
}
void CEGUI__Window_removeChildWindow2(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->removeChildWindow(((unsigned int)a));
}
void CEGUI__Window_setID(void* cls, unsigned int a){
	((CEGUI::Window*)cls)->setID(((unsigned int)a));
}
void CEGUI__Window_setHeight(void* cls, void* a){
	((CEGUI::Window*)cls)->setHeight(*((CEGUI::UDim*)a));
}
void CEGUI__Window_setUserData(void* cls, void* a){
	((CEGUI::Window*)cls)->setUserData(((void*)a));
}
bool CEGUI__Window_isUserStringDefined(void* cls, void* a){
	return ((CEGUI::Window*)cls)->isUserStringDefined(*((CEGUI::String*)a));
}
void CEGUI__Window_invalidateRenderingSurface(void* cls){
	((CEGUI::Window*)cls)->invalidateRenderingSurface();
}
void CEGUI__Window_setText(void* cls, void* a){
	((CEGUI::Window*)cls)->setText(*((CEGUI::String*)a));
}
bool CEGUI__Window_captureInput(void* cls){
	return ((CEGUI::Window*)cls)->captureInput();
}
void CEGUI__Window_clonePropertiesTo(void* cls, void* a){
	((CEGUI::Window*)cls)->clonePropertiesTo(*((CEGUI::Window*)a));
}
void* CEGUI__Window_getParentPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::Window*)cls)->getParentPixelSize());
}
void CEGUI__Window_setClippedByParent(void* cls, bool a){
	((CEGUI::Window*)cls)->setClippedByParent(((bool)a));
}
void CEGUI__Window_moveToFront(void* cls){
	((CEGUI::Window*)cls)->moveToFront();
}
void CEGUI__Window_setFont0(void* cls, void* a){
	((CEGUI::Window*)cls)->setFont(((CEGUI::Font*)a));
}
void CEGUI__Window_setFont1(void* cls, void* a){
	((CEGUI::Window*)cls)->setFont(*((CEGUI::String*)a));
}
bool CEGUI__Window_isCapturedByAncestor(void* cls){
	return ((CEGUI::Window*)cls)->isCapturedByAncestor();
}
void* CEGUI__Window_getTooltipType(void* cls){
	return new CEGUI::String(((CEGUI::Window*)cls)->getTooltipType());
}

//
// Begin class 'CEGUI::Tree'
//
void* CEGUI__Tree__Create(void* a, void* b){
	return new CEGUI::Tree(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Tree__Destroy(void* cls){
	delete (CEGUI::Tree*)cls;
}
void* CEGUI__Tree_getFirstSelectedItem(void* cls){
	return ((CEGUI::Tree*)cls)->getFirstSelectedItem();
}
void* CEGUI__Tree_getLastSelectedItem(void* cls){
	return ((CEGUI::Tree*)cls)->getLastSelectedItem();
}
void* CEGUI__Tree_findNextItemWithText(void* cls, void* a, void* b){
	return ((CEGUI::Tree*)cls)->findNextItemWithText(*((CEGUI::String*)a), ((CEGUI::TreeItem*)b));
}
void* CEGUI__Tree_getHorzScrollbar(void* cls){
	return ((CEGUI::Tree*)cls)->getHorzScrollbar();
}
bool CEGUI__Tree_isItemTooltipsEnabled(void* cls){
	return ((CEGUI::Tree*)cls)->isItemTooltipsEnabled();
}
void* CEGUI__Tree_findNextItemWithID(void* cls, unsigned int a, void* b){
	return ((CEGUI::Tree*)cls)->findNextItemWithID(((unsigned int)a), ((CEGUI::TreeItem*)b));
}
bool CEGUI__Tree_isMultiselectEnabled(void* cls){
	return ((CEGUI::Tree*)cls)->isMultiselectEnabled();
}
void CEGUI__Tree_setItemSelectState0(void* cls, void* a, bool b){
	((CEGUI::Tree*)cls)->setItemSelectState(((CEGUI::TreeItem*)a), ((bool)b));
}
void CEGUI__Tree_setItemSelectState1(void* cls, unsigned int a, bool b){
	((CEGUI::Tree*)cls)->setItemSelectState(((unsigned int)a), ((bool)b));
}
unsigned int CEGUI__Tree_getItemCount(void* cls){
	return ((CEGUI::Tree*)cls)->getItemCount();
}
unsigned int CEGUI__Tree_getSelectedCount(void* cls){
	return ((CEGUI::Tree*)cls)->getSelectedCount();
}
void CEGUI__Tree_doTreeRender(void* cls){
	((CEGUI::Tree*)cls)->doTreeRender();
}
void CEGUI__Tree_clearAllSelections(void* cls){
	((CEGUI::Tree*)cls)->clearAllSelections();
}
void CEGUI__Tree_resetList(void* cls){
	((CEGUI::Tree*)cls)->resetList();
}
void CEGUI__Tree_setShowHorzScrollbar(void* cls, bool a){
	((CEGUI::Tree*)cls)->setShowHorzScrollbar(((bool)a));
}
bool CEGUI__Tree_isSortEnabled(void* cls){
	return ((CEGUI::Tree*)cls)->isSortEnabled();
}
void CEGUI__Tree_setMultiselectEnabled(void* cls, bool a){
	((CEGUI::Tree*)cls)->setMultiselectEnabled(((bool)a));
}
void CEGUI__Tree_doScrollbars(void* cls){
	((CEGUI::Tree*)cls)->doScrollbars();
}
void CEGUI__Tree_initialise(void* cls){
	((CEGUI::Tree*)cls)->initialise();
}
bool CEGUI__Tree_isTreeItemInList(void* cls, void* a){
	return ((CEGUI::Tree*)cls)->isTreeItemInList(((CEGUI::TreeItem*)a));
}
bool CEGUI__Tree_isVertScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Tree*)cls)->isVertScrollbarAlwaysShown();
}
void CEGUI__Tree_setLookNFeel(void* cls, void* a){
	((CEGUI::Tree*)cls)->setLookNFeel(*((CEGUI::String*)a));
}
void CEGUI__Tree_insertItem(void* cls, void* a, void* b){
	((CEGUI::Tree*)cls)->insertItem(((CEGUI::TreeItem*)a), ((CEGUI::TreeItem*)b));
}
void CEGUI__Tree_addItem(void* cls, void* a){
	((CEGUI::Tree*)cls)->addItem(((CEGUI::TreeItem*)a));
}
void* CEGUI__Tree_getVertScrollbar(void* cls){
	return ((CEGUI::Tree*)cls)->getVertScrollbar();
}
void CEGUI__Tree_removeItem(void* cls, void* a){
	((CEGUI::Tree*)cls)->removeItem(((CEGUI::TreeItem*)a));
}
void* CEGUI__Tree_findFirstItemWithText(void* cls, void* a){
	return ((CEGUI::Tree*)cls)->findFirstItemWithText(*((CEGUI::String*)a));
}
void CEGUI__Tree_setItemRenderArea(void* cls, void* a){
	((CEGUI::Tree*)cls)->setItemRenderArea(*((CEGUI::Rect*)a));
}
void* CEGUI__Tree_getNextSelected(void* cls, void* a){
	return ((CEGUI::Tree*)cls)->getNextSelected(((CEGUI::TreeItem*)a));
}
void CEGUI__Tree_ensureItemIsVisible(void* cls, void* a){
	((CEGUI::Tree*)cls)->ensureItemIsVisible(((CEGUI::TreeItem*)a));
}
void CEGUI__Tree_handleUpdatedItemData(void* cls){
	((CEGUI::Tree*)cls)->handleUpdatedItemData();
}
void* CEGUI__Tree_findFirstItemWithID(void* cls, unsigned int a){
	return ((CEGUI::Tree*)cls)->findFirstItemWithID(((unsigned int)a));
}
void CEGUI__Tree_setSortingEnabled(void* cls, bool a){
	((CEGUI::Tree*)cls)->setSortingEnabled(((bool)a));
}
void CEGUI__Tree_setItemTooltipsEnabled(void* cls, bool a){
	((CEGUI::Tree*)cls)->setItemTooltipsEnabled(((bool)a));
}
void CEGUI__Tree_setShowVertScrollbar(void* cls, bool a){
	((CEGUI::Tree*)cls)->setShowVertScrollbar(((bool)a));
}
bool CEGUI__Tree_isHorzScrollbarAlwaysShown(void* cls){
	return ((CEGUI::Tree*)cls)->isHorzScrollbarAlwaysShown();
}

//
// Begin class 'CEGUI::Editbox'
//
void* CEGUI__Editbox__Create(void* a, void* b){
	return new CEGUI::Editbox(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Editbox__Destroy(void* cls){
	delete (CEGUI::Editbox*)cls;
}
void CEGUI__Editbox_setValidationString(void* cls, void* a){
	((CEGUI::Editbox*)cls)->setValidationString(*((CEGUI::String*)a));
}
bool CEGUI__Editbox_isTextMasked(void* cls){
	return ((CEGUI::Editbox*)cls)->isTextMasked();
}
void* CEGUI__Editbox_getValidationString(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Editbox*)cls)->getValidationString());
}
unsigned int CEGUI__Editbox_getMaxTextLength(void* cls){
	return ((CEGUI::Editbox*)cls)->getMaxTextLength();
}
bool CEGUI__Editbox_hasInputFocus(void* cls){
	return ((CEGUI::Editbox*)cls)->hasInputFocus();
}
bool CEGUI__Editbox_isReadOnly(void* cls){
	return ((CEGUI::Editbox*)cls)->isReadOnly();
}
unsigned int CEGUI__Editbox_getSelectionEndIndex(void* cls){
	return ((CEGUI::Editbox*)cls)->getSelectionEndIndex();
}
unsigned int CEGUI__Editbox_getSelectionStartIndex(void* cls){
	return ((CEGUI::Editbox*)cls)->getSelectionStartIndex();
}
unsigned int CEGUI__Editbox_getCaratIndex(void* cls){
	return ((CEGUI::Editbox*)cls)->getCaratIndex();
}
void CEGUI__Editbox_setCaratIndex(void* cls, unsigned int a){
	((CEGUI::Editbox*)cls)->setCaratIndex(((unsigned int)a));
}
unsigned int CEGUI__Editbox_getMaskCodePoint(void* cls){
	return ((CEGUI::Editbox*)cls)->getMaskCodePoint();
}
void CEGUI__Editbox_setTextMasked(void* cls, bool a){
	((CEGUI::Editbox*)cls)->setTextMasked(((bool)a));
}
void CEGUI__Editbox_setMaxTextLength(void* cls, unsigned int a){
	((CEGUI::Editbox*)cls)->setMaxTextLength(((unsigned int)a));
}
void CEGUI__Editbox_setSelection(void* cls, unsigned int a, unsigned int b){
	((CEGUI::Editbox*)cls)->setSelection(((unsigned int)a), ((unsigned int)b));
}
unsigned int CEGUI__Editbox_getSelectionLength(void* cls){
	return ((CEGUI::Editbox*)cls)->getSelectionLength();
}
void CEGUI__Editbox_setReadOnly(void* cls, bool a){
	((CEGUI::Editbox*)cls)->setReadOnly(((bool)a));
}
bool CEGUI__Editbox_isTextValid(void* cls){
	return ((CEGUI::Editbox*)cls)->isTextValid();
}
void CEGUI__Editbox_setMaskCodePoint(void* cls, unsigned int a){
	((CEGUI::Editbox*)cls)->setMaskCodePoint(((unsigned int)a));
}

//
// Begin class 'CEGUI::ListHeaderWindowRenderer'
//
void CEGUI__ListHeaderWindowRenderer__Destroy(void* cls){
	delete (CEGUI::ListHeaderWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::TabButton'
//
void* CEGUI__TabButton__Create(void* a, void* b){
	return new CEGUI::TabButton(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__TabButton__Destroy(void* cls){
	delete (CEGUI::TabButton*)cls;
}
void* CEGUI__TabButton_getTargetWindow(void* cls){
	return ((CEGUI::TabButton*)cls)->getTargetWindow();
}
void CEGUI__TabButton_setSelected(void* cls, bool a){
	((CEGUI::TabButton*)cls)->setSelected(((bool)a));
}
void CEGUI__TabButton_setTargetWindow(void* cls, void* a){
	((CEGUI::TabButton*)cls)->setTargetWindow(((CEGUI::Window*)a));
}
bool CEGUI__TabButton_isSelected(void* cls){
	return ((CEGUI::TabButton*)cls)->isSelected();
}

//
// Begin class 'CEGUI::WidgetLookManager'
//
void* CEGUI__WidgetLookManager__Create(){
	return new CEGUI::WidgetLookManager();
}
void CEGUI__WidgetLookManager__Destroy(void* cls){
	delete (CEGUI::WidgetLookManager*)cls;
}
void* CEGUI__WidgetLookManager_getSingletonPtr(void* cls){
	return ((CEGUI::WidgetLookManager*)cls)->getSingletonPtr();
}
void CEGUI__WidgetLookManager_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::WidgetLookManager*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
void CEGUI__WidgetLookManager_addWidgetLook(void* cls, void* a){
	((CEGUI::WidgetLookManager*)cls)->addWidgetLook(*((CEGUI::WidgetLookFeel*)a));
}
void* CEGUI__WidgetLookManager_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetLookManager*)cls)->getDefaultResourceGroup());
}
void* CEGUI__WidgetLookManager_getSingleton(void* cls){
	return &((CEGUI::WidgetLookManager*)cls)->getSingleton();
}
void CEGUI__WidgetLookManager_parseLookNFeelSpecification(void* cls, void* a, void* b){
	((CEGUI::WidgetLookManager*)cls)->parseLookNFeelSpecification(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__WidgetLookManager_eraseWidgetLook(void* cls, void* a){
	((CEGUI::WidgetLookManager*)cls)->eraseWidgetLook(*((CEGUI::String*)a));
}
void* CEGUI__WidgetLookManager_getWidgetLook(void* cls, void* a){
	return const_cast<CEGUI::WidgetLookFeel*>(&((CEGUI::WidgetLookManager*)cls)->getWidgetLook(*((CEGUI::String*)a)));
}
bool CEGUI__WidgetLookManager_isWidgetLookAvailable(void* cls, void* a){
	return ((CEGUI::WidgetLookManager*)cls)->isWidgetLookAvailable(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::RenderedStringComponent'
//
void CEGUI__RenderedStringComponent__Destroy(void* cls){
	delete (CEGUI::RenderedStringComponent*)cls;
}
void CEGUI__RenderedStringComponent_setLeftPadding(void* cls, float a){
	((CEGUI::RenderedStringComponent*)cls)->setLeftPadding(((float)a));
}
unsigned int CEGUI__RenderedStringComponent_getVerticalFormatting(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getVerticalFormatting();
}
float CEGUI__RenderedStringComponent_getLeftPadding(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getLeftPadding();
}
void CEGUI__RenderedStringComponent_setBottomPadding(void* cls, float a){
	((CEGUI::RenderedStringComponent*)cls)->setBottomPadding(((float)a));
}
void* CEGUI__RenderedStringComponent_getPadding(void* cls){
	return const_cast<CEGUI::Rect*>(&((CEGUI::RenderedStringComponent*)cls)->getPadding());
}
bool CEGUI__RenderedStringComponent_getAspectLock(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getAspectLock();
}
float CEGUI__RenderedStringComponent_getRightPadding(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getRightPadding();
}
void CEGUI__RenderedStringComponent_setVerticalFormatting(void* cls, unsigned int a){
	((CEGUI::RenderedStringComponent*)cls)->setVerticalFormatting(((CEGUI::VerticalFormatting)a));
}
void CEGUI__RenderedStringComponent_setTopPadding(void* cls, float a){
	((CEGUI::RenderedStringComponent*)cls)->setTopPadding(((float)a));
}
void CEGUI__RenderedStringComponent_setAspectLock(void* cls, bool a){
	((CEGUI::RenderedStringComponent*)cls)->setAspectLock(((bool)a));
}
void CEGUI__RenderedStringComponent_setRightPadding(void* cls, float a){
	((CEGUI::RenderedStringComponent*)cls)->setRightPadding(((float)a));
}
float CEGUI__RenderedStringComponent_getTopPadding(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getTopPadding();
}
float CEGUI__RenderedStringComponent_getBottomPadding(void* cls){
	return ((CEGUI::RenderedStringComponent*)cls)->getBottomPadding();
}
void CEGUI__RenderedStringComponent_setPadding(void* cls, void* a){
	((CEGUI::RenderedStringComponent*)cls)->setPadding(*((CEGUI::Rect*)a));
}

//
// Begin class 'CEGUI::WidgetLookFeel'
//
void* CEGUI__WidgetLookFeel__Create0(void* a){
	return new CEGUI::WidgetLookFeel(*((CEGUI::String*)a));
}
void* CEGUI__WidgetLookFeel__Create1(){
	return new CEGUI::WidgetLookFeel();
}
void CEGUI__WidgetLookFeel__Destroy(void* cls){
	delete (CEGUI::WidgetLookFeel*)cls;
}
void CEGUI__WidgetLookFeel_addPropertyLinkDefinition(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addPropertyLinkDefinition(*((CEGUI::PropertyLinkDefinition*)a));
}
void CEGUI__WidgetLookFeel_addNamedArea(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addNamedArea(*((CEGUI::NamedArea*)a));
}
void CEGUI__WidgetLookFeel_cleanUpWidget(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->cleanUpWidget(*((CEGUI::Window*)a));
}
void CEGUI__WidgetLookFeel_clearNamedAreas(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearNamedAreas();
}
bool CEGUI__WidgetLookFeel_isNamedAreaDefined(void* cls, void* a){
	return ((CEGUI::WidgetLookFeel*)cls)->isNamedAreaDefined(*((CEGUI::String*)a));
}
void* CEGUI__WidgetLookFeel_getNamedArea(void* cls, void* a){
	return const_cast<CEGUI::NamedArea*>(&((CEGUI::WidgetLookFeel*)cls)->getNamedArea(*((CEGUI::String*)a)));
}
void CEGUI__WidgetLookFeel_clearPropertyLinkDefinitions(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearPropertyLinkDefinitions();
}
void* CEGUI__WidgetLookFeel_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WidgetLookFeel*)cls)->getName());
}
void CEGUI__WidgetLookFeel_addAnimationName(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addAnimationName(*((CEGUI::String*)a));
}
void CEGUI__WidgetLookFeel_writeXMLToStream(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__WidgetLookFeel_initialiseWidget(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->initialiseWidget(*((CEGUI::Window*)a));
}
void CEGUI__WidgetLookFeel_addStateSpecification(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addStateSpecification(*((CEGUI::StateImagery*)a));
}
bool CEGUI__WidgetLookFeel_isStateImageryPresent(void* cls, void* a){
	return ((CEGUI::WidgetLookFeel*)cls)->isStateImageryPresent(*((CEGUI::String*)a));
}
void CEGUI__WidgetLookFeel_renameChildren(void* cls, void* a, void* b){
	((CEGUI::WidgetLookFeel*)cls)->renameChildren(*((CEGUI::Window*)a), *((CEGUI::String*)b));
}
void CEGUI__WidgetLookFeel_addImagerySection(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addImagerySection(*((CEGUI::ImagerySection*)a));
}
void CEGUI__WidgetLookFeel_clearImagerySections(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearImagerySections();
}
void CEGUI__WidgetLookFeel_layoutChildWidgets(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->layoutChildWidgets(*((CEGUI::Window*)a));
}
void CEGUI__WidgetLookFeel_clearPropertyInitialisers(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearPropertyInitialisers();
}
void* CEGUI__WidgetLookFeel_findWidgetComponent(void* cls, void* a){
	return const_cast<CEGUI::WidgetComponent*>(((CEGUI::WidgetLookFeel*)cls)->findWidgetComponent(*((CEGUI::String*)a)));
}
void CEGUI__WidgetLookFeel_clearStateSpecifications(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearStateSpecifications();
}
void CEGUI__WidgetLookFeel_clearPropertyDefinitions(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearPropertyDefinitions();
}
void CEGUI__WidgetLookFeel_clearWidgetComponents(void* cls){
	((CEGUI::WidgetLookFeel*)cls)->clearWidgetComponents();
}
void* CEGUI__WidgetLookFeel_findPropertyInitialiser(void* cls, void* a){
	return const_cast<CEGUI::PropertyInitialiser*>(((CEGUI::WidgetLookFeel*)cls)->findPropertyInitialiser(*((CEGUI::String*)a)));
}
void* CEGUI__WidgetLookFeel_getImagerySection(void* cls, void* a){
	return const_cast<CEGUI::ImagerySection*>(&((CEGUI::WidgetLookFeel*)cls)->getImagerySection(*((CEGUI::String*)a)));
}
void CEGUI__WidgetLookFeel_addWidgetComponent(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addWidgetComponent(*((CEGUI::WidgetComponent*)a));
}
void CEGUI__WidgetLookFeel_addPropertyInitialiser(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addPropertyInitialiser(*((CEGUI::PropertyInitialiser*)a));
}
void* CEGUI__WidgetLookFeel_getStateImagery(void* cls, void* a){
	return const_cast<CEGUI::StateImagery*>(&((CEGUI::WidgetLookFeel*)cls)->getStateImagery(*((CEGUI::String*)a)));
}
void CEGUI__WidgetLookFeel_addPropertyDefinition(void* cls, void* a){
	((CEGUI::WidgetLookFeel*)cls)->addPropertyDefinition(*((CEGUI::PropertyDefinition*)a));
}

//
// Begin class 'CEGUI::CentredRenderedString'
//
void CEGUI__CentredRenderedString__Destroy(void* cls){
	delete (CEGUI::CentredRenderedString*)cls;
}
void CEGUI__CentredRenderedString_draw(void* cls, void* a, void* b, void* c, void* d){
	((CEGUI::CentredRenderedString*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d));
}
float CEGUI__CentredRenderedString_getHorizontalExtent(void* cls){
	return ((CEGUI::CentredRenderedString*)cls)->getHorizontalExtent();
}
float CEGUI__CentredRenderedString_getVerticalExtent(void* cls){
	return ((CEGUI::CentredRenderedString*)cls)->getVerticalExtent();
}
unsigned int CEGUI__CentredRenderedString_getFormattedLineCount(void* cls){
	return ((CEGUI::CentredRenderedString*)cls)->getFormattedLineCount();
}
void CEGUI__CentredRenderedString_format(void* cls, void* a){
	((CEGUI::CentredRenderedString*)cls)->format(*((CEGUI::Size*)a));
}

//
// Begin class 'CEGUI::DynamicModule'
//
void* CEGUI__DynamicModule__Create(void* a){
	return new CEGUI::DynamicModule(*((CEGUI::String*)a));
}
void CEGUI__DynamicModule__Destroy(void* cls){
	delete (CEGUI::DynamicModule*)cls;
}
void* CEGUI__DynamicModule_getModuleName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::DynamicModule*)cls)->getModuleName());
}
void* CEGUI__DynamicModule_getSymbolAddress(void* cls, void* a){
	return ((CEGUI::DynamicModule*)cls)->getSymbolAddress(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::RenderTarget'
//
void CEGUI__RenderTarget__Destroy(void* cls){
	delete (CEGUI::RenderTarget*)cls;
}

//
// Begin class 'CEGUI::Imageset_xmlHandler'
//
void* CEGUI__Imageset_xmlHandler__Create(void* a, void* b){
	return new CEGUI::Imageset_xmlHandler(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__Imageset_xmlHandler__Destroy(void* cls){
	delete (CEGUI::Imageset_xmlHandler*)cls;
}
void CEGUI__Imageset_xmlHandler_elementStart(void* cls, void* a, void* b){
	((CEGUI::Imageset_xmlHandler*)cls)->elementStart(*((CEGUI::String*)a), *((CEGUI::XMLAttributes*)b));
}
void CEGUI__Imageset_xmlHandler_elementEnd(void* cls, void* a){
	((CEGUI::Imageset_xmlHandler*)cls)->elementEnd(*((CEGUI::String*)a));
}
void* CEGUI__Imageset_xmlHandler_getObject(void* cls){
	return &((CEGUI::Imageset_xmlHandler*)cls)->getObject();
}
void* CEGUI__Imageset_xmlHandler_getObjectName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::Imageset_xmlHandler*)cls)->getObjectName());
}

//
// Begin class 'CEGUI::RenderQueue'
//
void CEGUI__RenderQueue__Destroy(void* cls){
	delete (CEGUI::RenderQueue*)cls;
}
void CEGUI__RenderQueue_reset(void* cls){
	((CEGUI::RenderQueue*)cls)->reset();
}
void CEGUI__RenderQueue_draw(void* cls){
	((CEGUI::RenderQueue*)cls)->draw();
}
void CEGUI__RenderQueue_addGeometryBuffer(void* cls, void* a){
	((CEGUI::RenderQueue*)cls)->addGeometryBuffer(*((CEGUI::GeometryBuffer*)a));
}
void CEGUI__RenderQueue_removeGeometryBuffer(void* cls, void* a){
	((CEGUI::RenderQueue*)cls)->removeGeometryBuffer(*((CEGUI::GeometryBuffer*)a));
}

//
// Begin class 'CEGUI::MenuBase'
//
void CEGUI__MenuBase__Destroy(void* cls){
	delete (CEGUI::MenuBase*)cls;
}
float CEGUI__MenuBase_getItemSpacing(void* cls){
	return ((CEGUI::MenuBase*)cls)->getItemSpacing();
}
void CEGUI__MenuBase_changePopupMenuItem(void* cls, void* a){
	((CEGUI::MenuBase*)cls)->changePopupMenuItem(((CEGUI::MenuItem*)a));
}
bool CEGUI__MenuBase_isMultiplePopupsAllowed(void* cls){
	return ((CEGUI::MenuBase*)cls)->isMultiplePopupsAllowed();
}
void* CEGUI__MenuBase_getPopupMenuItem(void* cls){
	return ((CEGUI::MenuBase*)cls)->getPopupMenuItem();
}
void CEGUI__MenuBase_setAllowMultiplePopups(void* cls, bool a){
	((CEGUI::MenuBase*)cls)->setAllowMultiplePopups(((bool)a));
}
void CEGUI__MenuBase_setItemSpacing(void* cls, float a){
	((CEGUI::MenuBase*)cls)->setItemSpacing(((float)a));
}

//
// Begin class 'CEGUI::MultiLineEditboxWindowRenderer'
//
void CEGUI__MultiLineEditboxWindowRenderer__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::IntInterpolator'
//
void CEGUI__IntInterpolator__Destroy(void* cls){
	delete (CEGUI::IntInterpolator*)cls;
}
void* CEGUI__IntInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::IntInterpolator*)cls)->getType());
}
void* CEGUI__IntInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::IntInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__IntInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::IntInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__IntInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::IntInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::BasicRenderedStringParser'
//
void CEGUI__BasicRenderedStringParser__Destroy(void* cls){
	delete (CEGUI::BasicRenderedStringParser*)cls;
}
void CEGUI__BasicRenderedStringParser_setInitialColours(void* cls, void* a){
	((CEGUI::BasicRenderedStringParser*)cls)->setInitialColours(*((CEGUI::ColourRect*)a));
}
void* CEGUI__BasicRenderedStringParser_parse(void* cls, void* a, void* b, void* c){
	return new CEGUI::RenderedString(((CEGUI::BasicRenderedStringParser*)cls)->parse(*((CEGUI::String*)a), ((CEGUI::Font*)b), ((CEGUI::ColourRect*)c)));
}
void CEGUI__BasicRenderedStringParser_setInitialFontName(void* cls, void* a){
	((CEGUI::BasicRenderedStringParser*)cls)->setInitialFontName(*((CEGUI::String*)a));
}
void* CEGUI__BasicRenderedStringParser_getInitialColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::BasicRenderedStringParser*)cls)->getInitialColours());
}
void* CEGUI__BasicRenderedStringParser_getInitialFontName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::BasicRenderedStringParser*)cls)->getInitialFontName());
}

//
// Begin class 'CEGUI::RectInterpolator'
//
void CEGUI__RectInterpolator__Destroy(void* cls){
	delete (CEGUI::RectInterpolator*)cls;
}
void* CEGUI__RectInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::RectInterpolator*)cls)->getType());
}
void* CEGUI__RectInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::RectInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__RectInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::RectInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__RectInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::RectInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::ResourceEventSet'
//
void CEGUI__ResourceEventSet__Destroy(void* cls){
	delete (CEGUI::ResourceEventSet*)cls;
}

//
// Begin class 'CEGUI::TextUtils'
//
unsigned int CEGUI__TextUtils_getNextWordStartIdx(void* cls, void* a, unsigned int b){
	return ((CEGUI::TextUtils*)cls)->getNextWordStartIdx(*((CEGUI::String*)a), ((unsigned int)b));
}
unsigned int CEGUI__TextUtils_getWordStartIdx(void* cls, void* a, unsigned int b){
	return ((CEGUI::TextUtils*)cls)->getWordStartIdx(*((CEGUI::String*)a), ((unsigned int)b));
}
void* CEGUI__TextUtils_getNextWord(void* cls, void* a, unsigned int b, void* c){
	return new CEGUI::String(((CEGUI::TextUtils*)cls)->getNextWord(*((CEGUI::String*)a), ((unsigned int)b), *((CEGUI::String*)c)));
}
void CEGUI__TextUtils_trimTrailingChars(void* cls, void* a, void* b){
	((CEGUI::TextUtils*)cls)->trimTrailingChars(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__TextUtils_trimLeadingChars(void* cls, void* a, void* b){
	((CEGUI::TextUtils*)cls)->trimLeadingChars(*((CEGUI::String*)a), *((CEGUI::String*)b));
}

//
// Begin class 'CEGUI::RenderedStringWidgetComponent'
//
void CEGUI__RenderedStringWidgetComponent__Destroy(void* cls){
	delete (CEGUI::RenderedStringWidgetComponent*)cls;
}
void CEGUI__RenderedStringWidgetComponent_draw(void* cls, void* a, void* b, void* c, void* d, float e, float f){
	((CEGUI::RenderedStringWidgetComponent*)cls)->draw(*((CEGUI::GeometryBuffer*)a), *((CEGUI::Vector2*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((float)e), ((float)f));
}
void* CEGUI__RenderedStringWidgetComponent_clone(void* cls){
	return ((CEGUI::RenderedStringWidgetComponent*)cls)->clone();
}
void* CEGUI__RenderedStringWidgetComponent_getPixelSize(void* cls){
	return new CEGUI::Size(((CEGUI::RenderedStringWidgetComponent*)cls)->getPixelSize());
}
bool CEGUI__RenderedStringWidgetComponent_canSplit(void* cls){
	return ((CEGUI::RenderedStringWidgetComponent*)cls)->canSplit();
}
void* CEGUI__RenderedStringWidgetComponent_split(void* cls, float a, bool b){
	return ((CEGUI::RenderedStringWidgetComponent*)cls)->split(((float)a), ((bool)b));
}
void* CEGUI__RenderedStringWidgetComponent_getWindow(void* cls){
	return const_cast<CEGUI::Window*>(((CEGUI::RenderedStringWidgetComponent*)cls)->getWindow());
}
unsigned int CEGUI__RenderedStringWidgetComponent_getSpaceCount(void* cls){
	return ((CEGUI::RenderedStringWidgetComponent*)cls)->getSpaceCount();
}
void CEGUI__RenderedStringWidgetComponent_setWindow0(void* cls, void* a){
	((CEGUI::RenderedStringWidgetComponent*)cls)->setWindow(*((CEGUI::String*)a));
}
void CEGUI__RenderedStringWidgetComponent_setWindow1(void* cls, void* a){
	((CEGUI::RenderedStringWidgetComponent*)cls)->setWindow(((CEGUI::Window*)a));
}

//
// Begin class 'CEGUI::UintInterpolator'
//
void CEGUI__UintInterpolator__Destroy(void* cls){
	delete (CEGUI::UintInterpolator*)cls;
}
void* CEGUI__UintInterpolator_getType(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::UintInterpolator*)cls)->getType());
}
void* CEGUI__UintInterpolator_interpolateAbsolute(void* cls, void* a, void* b, float c){
	return new CEGUI::String(((CEGUI::UintInterpolator*)cls)->interpolateAbsolute(*((CEGUI::String*)a), *((CEGUI::String*)b), ((float)c)));
}
void* CEGUI__UintInterpolator_interpolateRelative(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UintInterpolator*)cls)->interpolateRelative(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}
void* CEGUI__UintInterpolator_interpolateRelativeMultiply(void* cls, void* a, void* b, void* c, float d){
	return new CEGUI::String(((CEGUI::UintInterpolator*)cls)->interpolateRelativeMultiply(*((CEGUI::String*)a), *((CEGUI::String*)b), *((CEGUI::String*)c), ((float)d)));
}

//
// Begin class 'CEGUI::DefaultRenderedStringParser'
//
void CEGUI__DefaultRenderedStringParser__Destroy(void* cls){
	delete (CEGUI::DefaultRenderedStringParser*)cls;
}
void* CEGUI__DefaultRenderedStringParser_parse(void* cls, void* a, void* b, void* c){
	return new CEGUI::RenderedString(((CEGUI::DefaultRenderedStringParser*)cls)->parse(*((CEGUI::String*)a), ((CEGUI::Font*)b), ((CEGUI::ColourRect*)c)));
}

//
// Begin class 'CEGUI::WidgetDim'
//
void CEGUI__WidgetDim__Destroy(void* cls){
	delete (CEGUI::WidgetDim*)cls;
}
void CEGUI__WidgetDim_setWidgetName(void* cls, void* a){
	((CEGUI::WidgetDim*)cls)->setWidgetName(*((CEGUI::String*)a));
}
void CEGUI__WidgetDim_setSourceDimension(void* cls, unsigned int a){
	((CEGUI::WidgetDim*)cls)->setSourceDimension(((CEGUI::DimensionType)a));
}

//
// Begin class 'CEGUI::URect'
//
void* CEGUI__URect__Create0(){
	return new CEGUI::URect();
}
void* CEGUI__URect__Create1(void* a, void* b){
	return new CEGUI::URect(*((CEGUI::UVector2*)a), *((CEGUI::UVector2*)b));
}
void* CEGUI__URect__Create2(void* a, void* b, void* c, void* d){
	return new CEGUI::URect(*((CEGUI::UDim*)a), *((CEGUI::UDim*)b), *((CEGUI::UDim*)c), *((CEGUI::UDim*)d));
}
void* CEGUI__URect__Create3(void* a){
	return new CEGUI::URect(*((CEGUI::URect*)a));
}
void CEGUI__URect__Destroy(void* cls){
	delete (CEGUI::URect*)cls;
}
void CEGUI__URect_setHeight(void* cls, void* a){
	((CEGUI::URect*)cls)->setHeight(*((CEGUI::UDim*)a));
}
void* CEGUI__URect_getWidth(void* cls){
	return new CEGUI::UDim(((CEGUI::URect*)cls)->getWidth());
}
void* CEGUI__URect_asRelative(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::URect*)cls)->asRelative(*((CEGUI::Size*)a)));
}
void CEGUI__URect_setWidth(void* cls, void* a){
	((CEGUI::URect*)cls)->setWidth(*((CEGUI::UDim*)a));
}
void* CEGUI__URect_getHeight(void* cls){
	return new CEGUI::UDim(((CEGUI::URect*)cls)->getHeight());
}
void* CEGUI__URect_asAbsolute(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::URect*)cls)->asAbsolute(*((CEGUI::Size*)a)));
}
void* CEGUI__URect_getSize(void* cls){
	return new CEGUI::UVector2(((CEGUI::URect*)cls)->getSize());
}
void CEGUI__URect_offset(void* cls, void* a){
	((CEGUI::URect*)cls)->offset(*((CEGUI::UVector2*)a));
}
void CEGUI__URect_setPosition(void* cls, void* a){
	((CEGUI::URect*)cls)->setPosition(*((CEGUI::UVector2*)a));
}
void CEGUI__URect_setSize(void* cls, void* a){
	((CEGUI::URect*)cls)->setSize(*((CEGUI::UVector2*)a));
}
void* CEGUI__URect_getPosition(void* cls){
	return const_cast<CEGUI::UVector2*>(&((CEGUI::URect*)cls)->getPosition());
}

//
// Begin class 'CEGUI::EventArgs'
//
void* CEGUI__EventArgs__Create(){
	return new CEGUI::EventArgs();
}
void CEGUI__EventArgs__Destroy(void* cls){
	delete (CEGUI::EventArgs*)cls;
}

//
// Begin class 'CEGUI::KeyFrame'
//
void* CEGUI__KeyFrame__Create(void* a, float b){
	return new CEGUI::KeyFrame(((CEGUI::Affector*)a), ((float)b));
}
void CEGUI__KeyFrame__Destroy(void* cls){
	delete (CEGUI::KeyFrame*)cls;
}
void CEGUI__KeyFrame_setValue(void* cls, void* a){
	((CEGUI::KeyFrame*)cls)->setValue(*((CEGUI::String*)a));
}
void* CEGUI__KeyFrame_getParent(void* cls){
	return ((CEGUI::KeyFrame*)cls)->getParent();
}
void CEGUI__KeyFrame_savePropertyValue(void* cls, void* a){
	((CEGUI::KeyFrame*)cls)->savePropertyValue(((CEGUI::AnimationInstance*)a));
}
void CEGUI__KeyFrame_notifyPositionChanged(void* cls, float a){
	((CEGUI::KeyFrame*)cls)->notifyPositionChanged(((float)a));
}
void* CEGUI__KeyFrame_getValue(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::KeyFrame*)cls)->getValue());
}
void CEGUI__KeyFrame_setProgression(void* cls, unsigned int a){
	((CEGUI::KeyFrame*)cls)->setProgression(((CEGUI::KeyFrame::Progression)a));
}
void* CEGUI__KeyFrame_getValueForAnimation(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::KeyFrame*)cls)->getValueForAnimation(((CEGUI::AnimationInstance*)a)));
}
float CEGUI__KeyFrame_alterInterpolationPosition(void* cls, float a){
	return ((CEGUI::KeyFrame*)cls)->alterInterpolationPosition(((float)a));
}
void CEGUI__KeyFrame_setSourceProperty(void* cls, void* a){
	((CEGUI::KeyFrame*)cls)->setSourceProperty(*((CEGUI::String*)a));
}
void CEGUI__KeyFrame_moveToPosition(void* cls, float a){
	((CEGUI::KeyFrame*)cls)->moveToPosition(((float)a));
}
void* CEGUI__KeyFrame_getSourceProperty(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::KeyFrame*)cls)->getSourceProperty());
}
float CEGUI__KeyFrame_getPosition(void* cls){
	return ((CEGUI::KeyFrame*)cls)->getPosition();
}
unsigned int CEGUI__KeyFrame_getProgression(void* cls){
	return ((CEGUI::KeyFrame*)cls)->getProgression();
}

//
// Begin class 'CEGUI::FrameWindow'
//
void* CEGUI__FrameWindow__Create(void* a, void* b){
	return new CEGUI::FrameWindow(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__FrameWindow__Destroy(void* cls){
	delete (CEGUI::FrameWindow*)cls;
}
void CEGUI__FrameWindow_setEWSizingCursorImage0(void* cls, void* a){
	((CEGUI::FrameWindow*)cls)->setEWSizingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__FrameWindow_setEWSizingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::FrameWindow*)cls)->setEWSizingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
float CEGUI__FrameWindow_getSizingBorderThickness(void* cls){
	return ((CEGUI::FrameWindow*)cls)->getSizingBorderThickness();
}
void CEGUI__FrameWindow_setSizingBorderThickness(void* cls, float a){
	((CEGUI::FrameWindow*)cls)->setSizingBorderThickness(((float)a));
}
void CEGUI__FrameWindow_setNWSESizingCursorImage0(void* cls, void* a){
	((CEGUI::FrameWindow*)cls)->setNWSESizingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__FrameWindow_setNWSESizingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::FrameWindow*)cls)->setNWSESizingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindow_getEWSizingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::FrameWindow*)cls)->getEWSizingCursorImage());
}
void CEGUI__FrameWindow_initialiseComponents(void* cls){
	((CEGUI::FrameWindow*)cls)->initialiseComponents();
}
void CEGUI__FrameWindow_setNSSizingCursorImage0(void* cls, void* a){
	((CEGUI::FrameWindow*)cls)->setNSSizingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__FrameWindow_setNSSizingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::FrameWindow*)cls)->setNSSizingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__FrameWindow_isFrameEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isFrameEnabled();
}
void CEGUI__FrameWindow_setRollupEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setRollupEnabled(((bool)a));
}
void CEGUI__FrameWindow_setNESWSizingCursorImage0(void* cls, void* a){
	((CEGUI::FrameWindow*)cls)->setNESWSizingCursorImage(((CEGUI::Image*)a));
}
void CEGUI__FrameWindow_setNESWSizingCursorImage1(void* cls, void* a, void* b){
	((CEGUI::FrameWindow*)cls)->setNESWSizingCursorImage(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindow_getTitlebar(void* cls){
	return ((CEGUI::FrameWindow*)cls)->getTitlebar();
}
bool CEGUI__FrameWindow_isTitleBarEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isTitleBarEnabled();
}
void* CEGUI__FrameWindow_getCloseButton(void* cls){
	return ((CEGUI::FrameWindow*)cls)->getCloseButton();
}
void CEGUI__FrameWindow_setTitleBarEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setTitleBarEnabled(((bool)a));
}
bool CEGUI__FrameWindow_isRolledup(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isRolledup();
}
void CEGUI__FrameWindow_toggleRollup(void* cls){
	((CEGUI::FrameWindow*)cls)->toggleRollup();
}
void* CEGUI__FrameWindow_getNSSizingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::FrameWindow*)cls)->getNSSizingCursorImage());
}
void CEGUI__FrameWindow_setDragMovingEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setDragMovingEnabled(((bool)a));
}
void CEGUI__FrameWindow_offsetPixelPosition(void* cls, void* a){
	((CEGUI::FrameWindow*)cls)->offsetPixelPosition(*((CEGUI::Vector2*)a));
}
bool CEGUI__FrameWindow_isCloseButtonEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isCloseButtonEnabled();
}
void* CEGUI__FrameWindow_getNWSESizingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::FrameWindow*)cls)->getNWSESizingCursorImage());
}
void CEGUI__FrameWindow_setFrameEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setFrameEnabled(((bool)a));
}
bool CEGUI__FrameWindow_isRollupEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isRollupEnabled();
}
bool CEGUI__FrameWindow_isSizingEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isSizingEnabled();
}
void CEGUI__FrameWindow_setSizingEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setSizingEnabled(((bool)a));
}
bool CEGUI__FrameWindow_isDragMovingEnabled(void* cls){
	return ((CEGUI::FrameWindow*)cls)->isDragMovingEnabled();
}
bool CEGUI__FrameWindow_isHit(void* cls, void* a, bool b){
	return ((CEGUI::FrameWindow*)cls)->isHit(*((CEGUI::Vector2*)a), ((bool)b));
}
void* CEGUI__FrameWindow_getNESWSizingCursorImage(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::FrameWindow*)cls)->getNESWSizingCursorImage());
}
void CEGUI__FrameWindow_setCloseButtonEnabled(void* cls, bool a){
	((CEGUI::FrameWindow*)cls)->setCloseButtonEnabled(((bool)a));
}

//
// Begin class 'CEGUI::AnimationManager'
//
void* CEGUI__AnimationManager__Create(){
	return new CEGUI::AnimationManager();
}
void CEGUI__AnimationManager__Destroy(void* cls){
	delete (CEGUI::AnimationManager*)cls;
}
void* CEGUI__AnimationManager_getAnimation(void* cls, void* a){
	return ((CEGUI::AnimationManager*)cls)->getAnimation(*((CEGUI::String*)a));
}
void CEGUI__AnimationManager_removeInterpolator(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->removeInterpolator(((CEGUI::Interpolator*)a));
}
void* CEGUI__AnimationManager_createAnimation(void* cls, void* a){
	return ((CEGUI::AnimationManager*)cls)->createAnimation(*((CEGUI::String*)a));
}
void CEGUI__AnimationManager_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}
void* CEGUI__AnimationManager_instantiateAnimation0(void* cls, void* a){
	return ((CEGUI::AnimationManager*)cls)->instantiateAnimation(((CEGUI::Animation*)a));
}
void* CEGUI__AnimationManager_instantiateAnimation1(void* cls, void* a){
	return ((CEGUI::AnimationManager*)cls)->instantiateAnimation(*((CEGUI::String*)a));
}
void* CEGUI__AnimationManager_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::AnimationManager*)cls)->getDefaultResourceGroup());
}
void CEGUI__AnimationManager_stepInstances(void* cls, float a){
	((CEGUI::AnimationManager*)cls)->stepInstances(((float)a));
}
void* CEGUI__AnimationManager_getInterpolator(void* cls, void* a){
	return ((CEGUI::AnimationManager*)cls)->getInterpolator(*((CEGUI::String*)a));
}
void CEGUI__AnimationManager_addInterpolator(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->addInterpolator(((CEGUI::Interpolator*)a));
}
void CEGUI__AnimationManager_destroyAllInstancesOfAnimation(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->destroyAllInstancesOfAnimation(((CEGUI::Animation*)a));
}
void CEGUI__AnimationManager_destroyAnimationInstance(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->destroyAnimationInstance(((CEGUI::AnimationInstance*)a));
}
void CEGUI__AnimationManager_destroyAnimation0(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->destroyAnimation(((CEGUI::Animation*)a));
}
void CEGUI__AnimationManager_destroyAnimation1(void* cls, void* a){
	((CEGUI::AnimationManager*)cls)->destroyAnimation(*((CEGUI::String*)a));
}
unsigned int CEGUI__AnimationManager_getNumAnimations(void* cls){
	return ((CEGUI::AnimationManager*)cls)->getNumAnimations();
}
void* CEGUI__AnimationManager_getAnimationInstanceAtIdx(void* cls, unsigned int a){
	return ((CEGUI::AnimationManager*)cls)->getAnimationInstanceAtIdx(((unsigned int)a));
}
void* CEGUI__AnimationManager_getAnimationAtIdx(void* cls, unsigned int a){
	return ((CEGUI::AnimationManager*)cls)->getAnimationAtIdx(((unsigned int)a));
}
void CEGUI__AnimationManager_loadAnimationsFromXML(void* cls, void* a, void* b){
	((CEGUI::AnimationManager*)cls)->loadAnimationsFromXML(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
unsigned int CEGUI__AnimationManager_getNumAnimationInstances(void* cls){
	return ((CEGUI::AnimationManager*)cls)->getNumAnimationInstances();
}

//
// Begin class 'CEGUI::Rect'
//
void* CEGUI__Rect__Create0(){
	return new CEGUI::Rect();
}
void* CEGUI__Rect__Create1(float a, float b, float c, float d){
	return new CEGUI::Rect(((float)a), ((float)b), ((float)c), ((float)d));
}
void* CEGUI__Rect__Create2(void* a, void* b){
	return new CEGUI::Rect(*((CEGUI::Vector2*)a), *((CEGUI::Size*)b));
}
void* CEGUI__Rect__Create3(void* a){
	return new CEGUI::Rect(*((CEGUI::Rect*)a));
}
void CEGUI__Rect__Destroy(void* cls){
	delete (CEGUI::Rect*)cls;
}
void CEGUI__Rect_setHeight(void* cls, float a){
	((CEGUI::Rect*)cls)->setHeight(((float)a));
}
void* CEGUI__Rect_getSize(void* cls){
	return new CEGUI::Size(((CEGUI::Rect*)cls)->getSize());
}
void* CEGUI__Rect_constrainSizeMax(void* cls, void* a){
	return &((CEGUI::Rect*)cls)->constrainSizeMax(*((CEGUI::Size*)a));
}
void CEGUI__Rect_setSize(void* cls, void* a){
	((CEGUI::Rect*)cls)->setSize(*((CEGUI::Size*)a));
}
bool CEGUI__Rect_isPointInRect(void* cls, void* a){
	return ((CEGUI::Rect*)cls)->isPointInRect(*((CEGUI::Vector2*)a));
}
float CEGUI__Rect_getHeight(void* cls){
	return ((CEGUI::Rect*)cls)->getHeight();
}
void* CEGUI__Rect_getIntersection(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::Rect*)cls)->getIntersection(*((CEGUI::Rect*)a)));
}
float CEGUI__Rect_getWidth(void* cls){
	return ((CEGUI::Rect*)cls)->getWidth();
}
void* CEGUI__Rect_constrainSize(void* cls, void* a, void* b){
	return &((CEGUI::Rect*)cls)->constrainSize(*((CEGUI::Size*)a), *((CEGUI::Size*)b));
}
void* CEGUI__Rect_offset(void* cls, void* a){
	return &((CEGUI::Rect*)cls)->offset(*((CEGUI::Vector2*)a));
}
void* CEGUI__Rect_constrainSizeMin(void* cls, void* a){
	return &((CEGUI::Rect*)cls)->constrainSizeMin(*((CEGUI::Size*)a));
}
void CEGUI__Rect_setPosition(void* cls, void* a){
	((CEGUI::Rect*)cls)->setPosition(*((CEGUI::Vector2*)a));
}
void CEGUI__Rect_setWidth(void* cls, float a){
	((CEGUI::Rect*)cls)->setWidth(((float)a));
}
void* CEGUI__Rect_getPosition(void* cls){
	return new CEGUI::Vector2(((CEGUI::Rect*)cls)->getPosition());
}

//
// Begin class 'CEGUI::MouseCursorEventArgs'
//
void* CEGUI__MouseCursorEventArgs__Create(void* a){
	return new CEGUI::MouseCursorEventArgs(((CEGUI::MouseCursor*)a));
}
void CEGUI__MouseCursorEventArgs__Destroy(void* cls){
	delete (CEGUI::MouseCursorEventArgs*)cls;
}

//
// Begin class 'CEGUI::UpdateEventArgs'
//
void* CEGUI__UpdateEventArgs__Create(void* a, float b){
	return new CEGUI::UpdateEventArgs(((CEGUI::Window*)a), ((float)b));
}
void CEGUI__UpdateEventArgs__Destroy(void* cls){
	delete (CEGUI::UpdateEventArgs*)cls;
}

//
// Begin class 'CEGUI::Texture'
//
void CEGUI__Texture__Destroy(void* cls){
	delete (CEGUI::Texture*)cls;
}

//
// Begin class 'CEGUI::LayoutContainer'
//
void CEGUI__LayoutContainer__Destroy(void* cls){
	delete (CEGUI::LayoutContainer*)cls;
}
void CEGUI__LayoutContainer_layoutIfNecessary(void* cls){
	((CEGUI::LayoutContainer*)cls)->layoutIfNecessary();
}
void CEGUI__LayoutContainer_update(void* cls, float a){
	((CEGUI::LayoutContainer*)cls)->update(((float)a));
}
void CEGUI__LayoutContainer_markNeedsLayouting(void* cls){
	((CEGUI::LayoutContainer*)cls)->markNeedsLayouting();
}
void* CEGUI__LayoutContainer_getUnclippedInnerRect_impl(void* cls){
	return new CEGUI::Rect(((CEGUI::LayoutContainer*)cls)->getUnclippedInnerRect_impl());
}
bool CEGUI__LayoutContainer_needsLayouting(void* cls){
	return ((CEGUI::LayoutContainer*)cls)->needsLayouting();
}

//
// Begin class 'CEGUI::ScriptFunctor'
//
void* CEGUI__ScriptFunctor__Create0(void* a){
	return new CEGUI::ScriptFunctor(*((CEGUI::String*)a));
}
void* CEGUI__ScriptFunctor__Create1(void* a){
	return new CEGUI::ScriptFunctor(*((CEGUI::ScriptFunctor*)a));
}
void CEGUI__ScriptFunctor__Destroy(void* cls){
	delete (CEGUI::ScriptFunctor*)cls;
}

//
// Begin class 'CEGUI::MultiLineEditbox::LineInfo'
//
void CEGUI__MultiLineEditbox__LineInfo__Destroy(void* cls){
	delete (CEGUI::MultiLineEditbox::LineInfo*)cls;
}

//
// Begin class 'CEGUI::System'
//
bool CEGUI__System_injectMouseMove(void* cls, float a, float b){
	return ((CEGUI::System*)cls)->injectMouseMove(((float)a), ((float)b));
}
bool CEGUI__System_injectKeyUp(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectKeyUp(((unsigned int)a));
}
void CEGUI__System_setModalTarget(void* cls, void* a){
	((CEGUI::System*)cls)->setModalTarget(((CEGUI::Window*)a));
}
void CEGUI__System_invalidateAllCachedRendering(void* cls){
	((CEGUI::System*)cls)->invalidateAllCachedRendering();
}
bool CEGUI__System_injectMouseButtonDown(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectMouseButtonDown(((CEGUI::MouseButton)a));
}
int CEGUI__System_executeScriptGlobal(void* cls, void* a){
	return ((CEGUI::System*)cls)->executeScriptGlobal(*((CEGUI::String*)a));
}
void CEGUI__System_setXMLParser0(void* cls, void* a){
	((CEGUI::System*)cls)->setXMLParser(*((CEGUI::String*)a));
}
void CEGUI__System_setXMLParser1(void* cls, void* a){
	((CEGUI::System*)cls)->setXMLParser(((CEGUI::XMLParser*)a));
}
void CEGUI__System_setMultiClickToleranceAreaSize(void* cls, void* a){
	((CEGUI::System*)cls)->setMultiClickToleranceAreaSize(*((CEGUI::Size*)a));
}
bool CEGUI__System_injectKeyDown(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectKeyDown(((unsigned int)a));
}
void* CEGUI__System_getModalTarget(void* cls){
	return ((CEGUI::System*)cls)->getModalTarget();
}
void* CEGUI__System_getDefaultCustomRenderedStringParser(void* cls){
	return ((CEGUI::System*)cls)->getDefaultCustomRenderedStringParser();
}
unsigned int CEGUI__System_getSystemKeys(void* cls){
	return ((CEGUI::System*)cls)->getSystemKeys();
}
double CEGUI__System_getSingleClickTimeout(void* cls){
	return ((CEGUI::System*)cls)->getSingleClickTimeout();
}
void CEGUI__System_setDefaultImageCodecName(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultImageCodecName(*((CEGUI::String*)a));
}
bool CEGUI__System_injectMousePosition(void* cls, float a, float b){
	return ((CEGUI::System*)cls)->injectMousePosition(((float)a), ((float)b));
}
void CEGUI__System_setDefaultTooltip0(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultTooltip(((CEGUI::Tooltip*)a));
}
void CEGUI__System_setDefaultTooltip1(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultTooltip(*((CEGUI::String*)a));
}
void CEGUI__System_setMouseMoveScaling(void* cls, float a){
	((CEGUI::System*)cls)->setMouseMoveScaling(((float)a));
}
void CEGUI__System_executeScriptString(void* cls, void* a){
	((CEGUI::System*)cls)->executeScriptString(*((CEGUI::String*)a));
}
void* CEGUI__System_getImageCodec(void* cls){
	return &((CEGUI::System*)cls)->getImageCodec();
}
void* CEGUI__System_getDefaultFont(void* cls){
	return ((CEGUI::System*)cls)->getDefaultFont();
}
void CEGUI__System_setDefaultFont0(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultFont(*((CEGUI::String*)a));
}
void CEGUI__System_setDefaultFont1(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultFont(((CEGUI::Font*)a));
}
bool CEGUI__System_isRedrawRequested(void* cls){
	return ((CEGUI::System*)cls)->isRedrawRequested();
}
void* CEGUI__System_getScriptingModule(void* cls){
	return ((CEGUI::System*)cls)->getScriptingModule();
}
bool CEGUI__System_updateWindowContainingMouse(void* cls){
	return ((CEGUI::System*)cls)->updateWindowContainingMouse();
}
void* CEGUI__System_getWindowContainingMouse(void* cls){
	return ((CEGUI::System*)cls)->getWindowContainingMouse();
}
void CEGUI__System_setMultiClickTimeout(void* cls, double a){
	((CEGUI::System*)cls)->setMultiClickTimeout(((double)a));
}
void CEGUI__System_setDefaultCustomRenderedStringParser(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultCustomRenderedStringParser(((CEGUI::RenderedStringParser*)a));
}
void* CEGUI__System_getMultiClickToleranceAreaSize(void* cls){
	return const_cast<CEGUI::Size*>(&((CEGUI::System*)cls)->getMultiClickToleranceAreaSize());
}
bool CEGUI__System_injectMouseButtonDoubleClick(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectMouseButtonDoubleClick(((CEGUI::MouseButton)a));
}
void* CEGUI__System_getXMLParser(void* cls){
	return ((CEGUI::System*)cls)->getXMLParser();
}
void CEGUI__System_executeScriptFile(void* cls, void* a, void* b){
	((CEGUI::System*)cls)->executeScriptFile(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
bool CEGUI__System_injectMouseLeaves(void* cls){
	return ((CEGUI::System*)cls)->injectMouseLeaves();
}
void* CEGUI__System_getDefaultXMLParserName(void* cls){
	return new CEGUI::String(((CEGUI::System*)cls)->getDefaultXMLParserName());
}
void CEGUI__System_renderGUI(void* cls){
	((CEGUI::System*)cls)->renderGUI();
}
bool CEGUI__System_injectChar(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectChar(((unsigned int)a));
}
void* CEGUI__System_getDefaultMouseCursor(void* cls){
	return const_cast<CEGUI::Image*>(((CEGUI::System*)cls)->getDefaultMouseCursor());
}
void* CEGUI__System_getResourceProvider(void* cls){
	return ((CEGUI::System*)cls)->getResourceProvider();
}
bool CEGUI__System_injectMouseButtonTripleClick(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectMouseButtonTripleClick(((CEGUI::MouseButton)a));
}
bool CEGUI__System_injectMouseButtonClick(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectMouseButtonClick(((CEGUI::MouseButton)a));
}
void* CEGUI__System_create(void* cls, void* a, void* b, void* c, void* d, void* e, void* f, void* g){
	return &((CEGUI::System*)cls)->create(*((CEGUI::Renderer*)a), ((CEGUI::ResourceProvider*)b), ((CEGUI::XMLParser*)c), ((CEGUI::ImageCodec*)d), ((CEGUI::ScriptModule*)e), *((CEGUI::String*)f), *((CEGUI::String*)g));
}
void CEGUI__System_setDefaultMouseCursor0(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultMouseCursor(((CEGUI::Image*)a));
}
void CEGUI__System_setDefaultMouseCursor1(void* cls, unsigned int a){
	((CEGUI::System*)cls)->setDefaultMouseCursor(((CEGUI::MouseCursorImage)a));
}
void CEGUI__System_setDefaultMouseCursor2(void* cls, void* a, void* b){
	((CEGUI::System*)cls)->setDefaultMouseCursor(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void* CEGUI__System_getDefaultTooltip(void* cls){
	return ((CEGUI::System*)cls)->getDefaultTooltip();
}
void* CEGUI__System_setGUISheet(void* cls, void* a){
	return ((CEGUI::System*)cls)->setGUISheet(((CEGUI::Window*)a));
}
void CEGUI__System_signalRedraw(void* cls){
	((CEGUI::System*)cls)->signalRedraw();
}
void* CEGUI__System_getDefaultImageCodecName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::System*)cls)->getDefaultImageCodecName());
}
void CEGUI__System_notifyDisplaySizeChanged(void* cls, void* a){
	((CEGUI::System*)cls)->notifyDisplaySizeChanged(*((CEGUI::Size*)a));
}
void CEGUI__System_setDefaultXMLParserName(void* cls, void* a){
	((CEGUI::System*)cls)->setDefaultXMLParserName(*((CEGUI::String*)a));
}
void* CEGUI__System_getSingleton(void* cls){
	return &((CEGUI::System*)cls)->getSingleton();
}
bool CEGUI__System_injectMouseWheelChange(void* cls, float a){
	return ((CEGUI::System*)cls)->injectMouseWheelChange(((float)a));
}
void CEGUI__System_setMouseClickEventGenerationEnabled(void* cls, bool a){
	((CEGUI::System*)cls)->setMouseClickEventGenerationEnabled(((bool)a));
}
void CEGUI__System_setImageCodec0(void* cls, void* a){
	((CEGUI::System*)cls)->setImageCodec(*((CEGUI::String*)a));
}
void CEGUI__System_setImageCodec1(void* cls, void* a){
	((CEGUI::System*)cls)->setImageCodec(*((CEGUI::ImageCodec*)a));
}
bool CEGUI__System_isMouseClickEventGenerationEnabled(void* cls){
	return ((CEGUI::System*)cls)->isMouseClickEventGenerationEnabled();
}
float CEGUI__System_getMouseMoveScaling(void* cls){
	return ((CEGUI::System*)cls)->getMouseMoveScaling();
}
void* CEGUI__System_getGUISheet(void* cls){
	return ((CEGUI::System*)cls)->getGUISheet();
}
bool CEGUI__System_injectMouseButtonUp(void* cls, unsigned int a){
	return ((CEGUI::System*)cls)->injectMouseButtonUp(((CEGUI::MouseButton)a));
}
void CEGUI__System_setScriptingModule(void* cls, void* a){
	((CEGUI::System*)cls)->setScriptingModule(((CEGUI::ScriptModule*)a));
}
double CEGUI__System_getMultiClickTimeout(void* cls){
	return ((CEGUI::System*)cls)->getMultiClickTimeout();
}
void CEGUI__System_setSingleClickTimeout(void* cls, double a){
	((CEGUI::System*)cls)->setSingleClickTimeout(((double)a));
}
void* CEGUI__System_getRenderer(void* cls){
	return ((CEGUI::System*)cls)->getRenderer();
}
void CEGUI__System_destroy(void* cls){
	((CEGUI::System*)cls)->destroy();
}
bool CEGUI__System_injectTimePulse(void* cls, float a){
	return ((CEGUI::System*)cls)->injectTimePulse(((float)a));
}
void* CEGUI__System_getSingletonPtr(void* cls){
	return ((CEGUI::System*)cls)->getSingletonPtr();
}
void CEGUI__System_notifyWindowDestroyed(void* cls, void* a){
	((CEGUI::System*)cls)->notifyWindowDestroyed(((CEGUI::Window*)a));
}

//
// Begin class 'CEGUI::UVector2'
//
void* CEGUI__UVector2__Create0(){
	return new CEGUI::UVector2();
}
void* CEGUI__UVector2__Create1(void* a, void* b){
	return new CEGUI::UVector2(*((CEGUI::UDim*)a), *((CEGUI::UDim*)b));
}
void* CEGUI__UVector2__Create2(void* a){
	return new CEGUI::UVector2(*((CEGUI::UVector2*)a));
}
void CEGUI__UVector2__Destroy(void* cls){
	delete (CEGUI::UVector2*)cls;
}
void* CEGUI__UVector2_asRelative(void* cls, void* a){
	return new CEGUI::Vector2(((CEGUI::UVector2*)cls)->asRelative(*((CEGUI::Size*)a)));
}
void* CEGUI__UVector2_asAbsolute(void* cls, void* a){
	return new CEGUI::Vector2(((CEGUI::UVector2*)cls)->asAbsolute(*((CEGUI::Size*)a)));
}

//
// Begin class 'CEGUI::SliderWindowRenderer'
//
void CEGUI__SliderWindowRenderer__Destroy(void* cls){
	delete (CEGUI::SliderWindowRenderer*)cls;
}

//
// Begin class 'CEGUI::ImagerySection'
//
void* CEGUI__ImagerySection__Create0(){
	return new CEGUI::ImagerySection();
}
void* CEGUI__ImagerySection__Create1(void* a){
	return new CEGUI::ImagerySection(*((CEGUI::String*)a));
}
void CEGUI__ImagerySection__Destroy(void* cls){
	delete (CEGUI::ImagerySection*)cls;
}
void* CEGUI__ImagerySection_getBoundingRect0(void* cls, void* a){
	return new CEGUI::Rect(((CEGUI::ImagerySection*)cls)->getBoundingRect(*((CEGUI::Window*)a)));
}
void* CEGUI__ImagerySection_getBoundingRect1(void* cls, void* a, void* b){
	return new CEGUI::Rect(((CEGUI::ImagerySection*)cls)->getBoundingRect(*((CEGUI::Window*)a), *((CEGUI::Rect*)b)));
}
void CEGUI__ImagerySection_addImageryComponent(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->addImageryComponent(*((CEGUI::ImageryComponent*)a));
}
void CEGUI__ImagerySection_render0(void* cls, void* a, void* b, void* c, bool d){
	((CEGUI::ImagerySection*)cls)->render(*((CEGUI::Window*)a), ((CEGUI::ColourRect*)b), ((CEGUI::Rect*)c), ((bool)d));
}
void CEGUI__ImagerySection_render1(void* cls, void* a, void* b, void* c, void* d, bool e){
	((CEGUI::ImagerySection*)cls)->render(*((CEGUI::Window*)a), *((CEGUI::Rect*)b), ((CEGUI::ColourRect*)c), ((CEGUI::Rect*)d), ((bool)e));
}
void CEGUI__ImagerySection_clearFrameComponents(void* cls){
	((CEGUI::ImagerySection*)cls)->clearFrameComponents();
}
void CEGUI__ImagerySection_addFrameComponent(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->addFrameComponent(*((CEGUI::FrameComponent*)a));
}
void* CEGUI__ImagerySection_getMasterColours(void* cls){
	return const_cast<CEGUI::ColourRect*>(&((CEGUI::ImagerySection*)cls)->getMasterColours());
}
void CEGUI__ImagerySection_addTextComponent(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->addTextComponent(*((CEGUI::TextComponent*)a));
}
void CEGUI__ImagerySection_clearImageryComponents(void* cls){
	((CEGUI::ImagerySection*)cls)->clearImageryComponents();
}
void CEGUI__ImagerySection_clearTextComponents(void* cls){
	((CEGUI::ImagerySection*)cls)->clearTextComponents();
}
void CEGUI__ImagerySection_writeXMLToStream(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->writeXMLToStream(*((CEGUI::XMLSerializer*)a));
}
void CEGUI__ImagerySection_setMasterColours(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->setMasterColours(*((CEGUI::ColourRect*)a));
}
void CEGUI__ImagerySection_setMasterColoursPropertySource(void* cls, void* a){
	((CEGUI::ImagerySection*)cls)->setMasterColoursPropertySource(*((CEGUI::String*)a));
}
void CEGUI__ImagerySection_setMasterColoursPropertyIsColourRect(void* cls, bool a){
	((CEGUI::ImagerySection*)cls)->setMasterColoursPropertyIsColourRect(((bool)a));
}
void* CEGUI__ImagerySection_getName(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ImagerySection*)cls)->getName());
}

//
// Begin class 'CEGUI::RenderQueueEventArgs'
//
void* CEGUI__RenderQueueEventArgs__Create(unsigned int a){
	return new CEGUI::RenderQueueEventArgs(((CEGUI::RenderQueueID)a));
}
void CEGUI__RenderQueueEventArgs__Destroy(void* cls){
	delete (CEGUI::RenderQueueEventArgs*)cls;
}

//
// Begin class 'CEGUI::XMLParser'
//
void CEGUI__XMLParser__Destroy(void* cls){
	delete (CEGUI::XMLParser*)cls;
}
void* CEGUI__XMLParser_getIdentifierString(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::XMLParser*)cls)->getIdentifierString());
}
bool CEGUI__XMLParser_initialise(void* cls){
	return ((CEGUI::XMLParser*)cls)->initialise();
}
void CEGUI__XMLParser_cleanup(void* cls){
	((CEGUI::XMLParser*)cls)->cleanup();
}

//
// Begin class 'CEGUI::ResourceProvider'
//
void CEGUI__ResourceProvider__Destroy(void* cls){
	delete (CEGUI::ResourceProvider*)cls;
}
void* CEGUI__ResourceProvider_getDefaultResourceGroup(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::ResourceProvider*)cls)->getDefaultResourceGroup());
}
void CEGUI__ResourceProvider_unloadRawDataContainer(void* cls, void* a){
	((CEGUI::ResourceProvider*)cls)->unloadRawDataContainer(*((CEGUI::RawDataContainer*)a));
}
void CEGUI__ResourceProvider_setDefaultResourceGroup(void* cls, void* a){
	((CEGUI::ResourceProvider*)cls)->setDefaultResourceGroup(*((CEGUI::String*)a));
}

//
// Begin class 'CEGUI::UnifiedDim'
//
void CEGUI__UnifiedDim__Destroy(void* cls){
	delete (CEGUI::UnifiedDim*)cls;
}

//
// Begin class 'CEGUI::ComboDropList'
//
void* CEGUI__ComboDropList__Create(void* a, void* b){
	return new CEGUI::ComboDropList(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__ComboDropList__Destroy(void* cls){
	delete (CEGUI::ComboDropList*)cls;
}
bool CEGUI__ComboDropList_isArmed(void* cls){
	return ((CEGUI::ComboDropList*)cls)->isArmed();
}
void CEGUI__ComboDropList_setArmed(void* cls, bool a){
	((CEGUI::ComboDropList*)cls)->setArmed(((bool)a));
}
void CEGUI__ComboDropList_initialiseComponents(void* cls){
	((CEGUI::ComboDropList*)cls)->initialiseComponents();
}
void CEGUI__ComboDropList_setAutoArmEnabled(void* cls, bool a){
	((CEGUI::ComboDropList*)cls)->setAutoArmEnabled(((bool)a));
}
bool CEGUI__ComboDropList_isAutoArmEnabled(void* cls){
	return ((CEGUI::ComboDropList*)cls)->isAutoArmEnabled();
}

//
// Begin class 'CEGUI::GUISheet'
//
void* CEGUI__GUISheet__Create(void* a, void* b){
	return new CEGUI::GUISheet(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__GUISheet__Destroy(void* cls){
	delete (CEGUI::GUISheet*)cls;
}

//
// Begin class 'CEGUI::AbsoluteDim'
//
void CEGUI__AbsoluteDim__Destroy(void* cls){
	delete (CEGUI::AbsoluteDim*)cls;
}
void CEGUI__AbsoluteDim_setValue(void* cls, float a){
	((CEGUI::AbsoluteDim*)cls)->setValue(((float)a));
}

//
// Begin class 'CEGUI::Vector2'
//
void* CEGUI__Vector2__Create0(){
	return new CEGUI::Vector2();
}
void* CEGUI__Vector2__Create1(float a, float b){
	return new CEGUI::Vector2(((float)a), ((float)b));
}
void* CEGUI__Vector2__Create2(void* a){
	return new CEGUI::Vector2(*((CEGUI::Vector2*)a));
}
void CEGUI__Vector2__Destroy(void* cls){
	delete (CEGUI::Vector2*)cls;
}
void* CEGUI__Vector2_asSize(void* cls){
	return new CEGUI::Size(((CEGUI::Vector2*)cls)->asSize());
}

//
// Begin class 'CEGUI::WindowFactoryManager::AliasTargetStack'
//
void* CEGUI__WindowFactoryManager__AliasTargetStack__Create(){
	return new CEGUI::WindowFactoryManager::AliasTargetStack();
}
void CEGUI__WindowFactoryManager__AliasTargetStack__Destroy(void* cls){
	delete (CEGUI::WindowFactoryManager::AliasTargetStack*)cls;
}
unsigned int CEGUI__WindowFactoryManager__AliasTargetStack_getStackedTargetCount(void* cls){
	return ((CEGUI::WindowFactoryManager::AliasTargetStack*)cls)->getStackedTargetCount();
}
void* CEGUI__WindowFactoryManager__AliasTargetStack_getActiveTarget(void* cls){
	return const_cast<CEGUI::String*>(&((CEGUI::WindowFactoryManager::AliasTargetStack*)cls)->getActiveTarget());
}

//
// Begin class 'CEGUI::DefaultResourceProvider'
//
void CEGUI__DefaultResourceProvider__Destroy(void* cls){
	delete (CEGUI::DefaultResourceProvider*)cls;
}
void CEGUI__DefaultResourceProvider_setResourceGroupDirectory(void* cls, void* a, void* b){
	((CEGUI::DefaultResourceProvider*)cls)->setResourceGroupDirectory(*((CEGUI::String*)a), *((CEGUI::String*)b));
}
void CEGUI__DefaultResourceProvider_unloadRawDataContainer(void* cls, void* a){
	((CEGUI::DefaultResourceProvider*)cls)->unloadRawDataContainer(*((CEGUI::RawDataContainer*)a));
}
void* CEGUI__DefaultResourceProvider_getResourceGroupDirectory(void* cls, void* a){
	return const_cast<CEGUI::String*>(&((CEGUI::DefaultResourceProvider*)cls)->getResourceGroupDirectory(*((CEGUI::String*)a)));
}
void CEGUI__DefaultResourceProvider_clearResourceGroupDirectory(void* cls, void* a){
	((CEGUI::DefaultResourceProvider*)cls)->clearResourceGroupDirectory(*((CEGUI::String*)a));
}
void CEGUI__DefaultResourceProvider_loadRawDataContainer(void* cls, void* a, void* b, void* c){
	((CEGUI::DefaultResourceProvider*)cls)->loadRawDataContainer(*((CEGUI::String*)a), *((CEGUI::RawDataContainer*)b), *((CEGUI::String*)c));
}

//
// Begin class 'CEGUI::SpinnerProperties::CurrentValue'
//
void CEGUI__SpinnerProperties__CurrentValue__Destroy(void* cls){
	delete (CEGUI::SpinnerProperties::CurrentValue*)cls;
}
void CEGUI__SpinnerProperties__CurrentValue_set(void* cls, void* a, void* b){
	((CEGUI::SpinnerProperties::CurrentValue*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SpinnerProperties__CurrentValue_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SpinnerProperties::CurrentValue*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SpinnerProperties::MaximumValue'
//
void CEGUI__SpinnerProperties__MaximumValue__Destroy(void* cls){
	delete (CEGUI::SpinnerProperties::MaximumValue*)cls;
}
void CEGUI__SpinnerProperties__MaximumValue_set(void* cls, void* a, void* b){
	((CEGUI::SpinnerProperties::MaximumValue*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SpinnerProperties__MaximumValue_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SpinnerProperties::MaximumValue*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SpinnerProperties::MinimumValue'
//
void CEGUI__SpinnerProperties__MinimumValue__Destroy(void* cls){
	delete (CEGUI::SpinnerProperties::MinimumValue*)cls;
}
void CEGUI__SpinnerProperties__MinimumValue_set(void* cls, void* a, void* b){
	((CEGUI::SpinnerProperties::MinimumValue*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SpinnerProperties__MinimumValue_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SpinnerProperties::MinimumValue*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SpinnerProperties::TextInputMode'
//
void CEGUI__SpinnerProperties__TextInputMode__Destroy(void* cls){
	delete (CEGUI::SpinnerProperties::TextInputMode*)cls;
}
void CEGUI__SpinnerProperties__TextInputMode_set(void* cls, void* a, void* b){
	((CEGUI::SpinnerProperties::TextInputMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SpinnerProperties__TextInputMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SpinnerProperties::TextInputMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SpinnerProperties::StepSize'
//
void CEGUI__SpinnerProperties__StepSize__Destroy(void* cls){
	delete (CEGUI::SpinnerProperties::StepSize*)cls;
}
void CEGUI__SpinnerProperties__StepSize_set(void* cls, void* a, void* b){
	((CEGUI::SpinnerProperties::StepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SpinnerProperties__StepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SpinnerProperties::StepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ThumbProperties::HorzFree'
//
void CEGUI__ThumbProperties__HorzFree__Destroy(void* cls){
	delete (CEGUI::ThumbProperties::HorzFree*)cls;
}
void CEGUI__ThumbProperties__HorzFree_set(void* cls, void* a, void* b){
	((CEGUI::ThumbProperties::HorzFree*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ThumbProperties__HorzFree_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ThumbProperties::HorzFree*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ThumbProperties::HorzRange'
//
void CEGUI__ThumbProperties__HorzRange__Destroy(void* cls){
	delete (CEGUI::ThumbProperties::HorzRange*)cls;
}
void CEGUI__ThumbProperties__HorzRange_set(void* cls, void* a, void* b){
	((CEGUI::ThumbProperties::HorzRange*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ThumbProperties__HorzRange_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ThumbProperties::HorzRange*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ThumbProperties::VertFree'
//
void CEGUI__ThumbProperties__VertFree__Destroy(void* cls){
	delete (CEGUI::ThumbProperties::VertFree*)cls;
}
void CEGUI__ThumbProperties__VertFree_set(void* cls, void* a, void* b){
	((CEGUI::ThumbProperties::VertFree*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ThumbProperties__VertFree_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ThumbProperties::VertFree*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ThumbProperties::VertRange'
//
void CEGUI__ThumbProperties__VertRange__Destroy(void* cls){
	delete (CEGUI::ThumbProperties::VertRange*)cls;
}
void CEGUI__ThumbProperties__VertRange_set(void* cls, void* a, void* b){
	((CEGUI::ThumbProperties::VertRange*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ThumbProperties__VertRange_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ThumbProperties::VertRange*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ThumbProperties::HotTracked'
//
void CEGUI__ThumbProperties__HotTracked__Destroy(void* cls){
	delete (CEGUI::ThumbProperties::HotTracked*)cls;
}
void CEGUI__ThumbProperties__HotTracked_set(void* cls, void* a, void* b){
	((CEGUI::ThumbProperties::HotTracked*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ThumbProperties__HotTracked_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ThumbProperties::HotTracked*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertStepSize'
//
void CEGUI__ScrollablePaneProperties__VertStepSize__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::VertStepSize*)cls;
}
void CEGUI__ScrollablePaneProperties__VertStepSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::VertStepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__VertStepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::VertStepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::ForceHorzScrollbar'
//
void CEGUI__ScrollablePaneProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__ScrollablePaneProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::ContentPaneAutoSized'
//
void CEGUI__ScrollablePaneProperties__ContentPaneAutoSized__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::ContentPaneAutoSized*)cls;
}
void CEGUI__ScrollablePaneProperties__ContentPaneAutoSized_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::ContentPaneAutoSized*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__ContentPaneAutoSized_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::ContentPaneAutoSized*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzScrollPosition'
//
void CEGUI__ScrollablePaneProperties__HorzScrollPosition__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::HorzScrollPosition*)cls;
}
void CEGUI__ScrollablePaneProperties__HorzScrollPosition_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::HorzScrollPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__HorzScrollPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::HorzScrollPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertScrollPosition'
//
void CEGUI__ScrollablePaneProperties__VertScrollPosition__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::VertScrollPosition*)cls;
}
void CEGUI__ScrollablePaneProperties__VertScrollPosition_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::VertScrollPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__VertScrollPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::VertScrollPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertOverlapSize'
//
void CEGUI__ScrollablePaneProperties__VertOverlapSize__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::VertOverlapSize*)cls;
}
void CEGUI__ScrollablePaneProperties__VertOverlapSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::VertOverlapSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__VertOverlapSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::VertOverlapSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzOverlapSize'
//
void CEGUI__ScrollablePaneProperties__HorzOverlapSize__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::HorzOverlapSize*)cls;
}
void CEGUI__ScrollablePaneProperties__HorzOverlapSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::HorzOverlapSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__HorzOverlapSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::HorzOverlapSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzStepSize'
//
void CEGUI__ScrollablePaneProperties__HorzStepSize__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::HorzStepSize*)cls;
}
void CEGUI__ScrollablePaneProperties__HorzStepSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::HorzStepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__HorzStepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::HorzStepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::ContentArea'
//
void CEGUI__ScrollablePaneProperties__ContentArea__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::ContentArea*)cls;
}
void CEGUI__ScrollablePaneProperties__ContentArea_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::ContentArea*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__ContentArea_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::ContentArea*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollablePaneProperties::ForceVertScrollbar'
//
void CEGUI__ScrollablePaneProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::ScrollablePaneProperties::ForceVertScrollbar*)cls;
}
void CEGUI__ScrollablePaneProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ScrollablePaneProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollablePaneProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollablePaneProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::PopupMenuProperties::FadeInTime'
//
void CEGUI__PopupMenuProperties__FadeInTime__Destroy(void* cls){
	delete (CEGUI::PopupMenuProperties::FadeInTime*)cls;
}
void CEGUI__PopupMenuProperties__FadeInTime_set(void* cls, void* a, void* b){
	((CEGUI::PopupMenuProperties::FadeInTime*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__PopupMenuProperties__FadeInTime_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PopupMenuProperties::FadeInTime*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::PopupMenuProperties::FadeOutTime'
//
void CEGUI__PopupMenuProperties__FadeOutTime__Destroy(void* cls){
	delete (CEGUI::PopupMenuProperties::FadeOutTime*)cls;
}
void CEGUI__PopupMenuProperties__FadeOutTime_set(void* cls, void* a, void* b){
	((CEGUI::PopupMenuProperties::FadeOutTime*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__PopupMenuProperties__FadeOutTime_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::PopupMenuProperties::FadeOutTime*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::ScrollPosition'
//
void CEGUI__ScrollbarProperties__ScrollPosition__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::ScrollPosition*)cls;
}
void CEGUI__ScrollbarProperties__ScrollPosition_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::ScrollPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__ScrollPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::ScrollPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::OverlapSize'
//
void CEGUI__ScrollbarProperties__OverlapSize__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::OverlapSize*)cls;
}
void CEGUI__ScrollbarProperties__OverlapSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::OverlapSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__OverlapSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::OverlapSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::DocumentSize'
//
void CEGUI__ScrollbarProperties__DocumentSize__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::DocumentSize*)cls;
}
void CEGUI__ScrollbarProperties__DocumentSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::DocumentSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__DocumentSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::DocumentSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::StepSize'
//
void CEGUI__ScrollbarProperties__StepSize__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::StepSize*)cls;
}
void CEGUI__ScrollbarProperties__StepSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::StepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__StepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::StepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::PageSize'
//
void CEGUI__ScrollbarProperties__PageSize__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::PageSize*)cls;
}
void CEGUI__ScrollbarProperties__PageSize_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::PageSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__PageSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::PageSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrollbarProperties::EndLockEnabled'
//
void CEGUI__ScrollbarProperties__EndLockEnabled__Destroy(void* cls){
	delete (CEGUI::ScrollbarProperties::EndLockEnabled*)cls;
}
void CEGUI__ScrollbarProperties__EndLockEnabled_set(void* cls, void* a, void* b){
	((CEGUI::ScrollbarProperties::EndLockEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrollbarProperties__EndLockEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrollbarProperties::EndLockEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::NominatedSelectionColumnID'
//
void CEGUI__MultiColumnListProperties__NominatedSelectionColumnID__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::NominatedSelectionColumnID*)cls;
}
void CEGUI__MultiColumnListProperties__NominatedSelectionColumnID_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::NominatedSelectionColumnID*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__NominatedSelectionColumnID_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::NominatedSelectionColumnID*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::SortDirection'
//
void CEGUI__MultiColumnListProperties__SortDirection__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::SortDirection*)cls;
}
void CEGUI__MultiColumnListProperties__SortDirection_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::SortDirection*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__SortDirection_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::SortDirection*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::SortColumnID'
//
void CEGUI__MultiColumnListProperties__SortColumnID__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::SortColumnID*)cls;
}
void CEGUI__MultiColumnListProperties__SortColumnID_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::SortColumnID*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__SortColumnID_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::SortColumnID*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnsSizable'
//
void CEGUI__MultiColumnListProperties__ColumnsSizable__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::ColumnsSizable*)cls;
}
void CEGUI__MultiColumnListProperties__ColumnsSizable_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::ColumnsSizable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__ColumnsSizable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::ColumnsSizable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::NominatedSelectionRow'
//
void CEGUI__MultiColumnListProperties__NominatedSelectionRow__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::NominatedSelectionRow*)cls;
}
void CEGUI__MultiColumnListProperties__NominatedSelectionRow_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::NominatedSelectionRow*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__NominatedSelectionRow_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::NominatedSelectionRow*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::RowCount'
//
void CEGUI__MultiColumnListProperties__RowCount__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::RowCount*)cls;
}
void CEGUI__MultiColumnListProperties__RowCount_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::RowCount*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__RowCount_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::RowCount*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::ForceVertScrollbar'
//
void CEGUI__MultiColumnListProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::ForceVertScrollbar*)cls;
}
void CEGUI__MultiColumnListProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::SelectionMode'
//
void CEGUI__MultiColumnListProperties__SelectionMode__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::SelectionMode*)cls;
}
void CEGUI__MultiColumnListProperties__SelectionMode_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::SelectionMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__SelectionMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::SelectionMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::SortSettingEnabled'
//
void CEGUI__MultiColumnListProperties__SortSettingEnabled__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::SortSettingEnabled*)cls;
}
void CEGUI__MultiColumnListProperties__SortSettingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::SortSettingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__SortSettingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::SortSettingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnHeader'
//
void CEGUI__MultiColumnListProperties__ColumnHeader__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::ColumnHeader*)cls;
}
void CEGUI__MultiColumnListProperties__ColumnHeader_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::ColumnHeader*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__ColumnHeader_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::ColumnHeader*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::ForceHorzScrollbar'
//
void CEGUI__MultiColumnListProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__MultiColumnListProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnsMovable'
//
void CEGUI__MultiColumnListProperties__ColumnsMovable__Destroy(void* cls){
	delete (CEGUI::MultiColumnListProperties::ColumnsMovable*)cls;
}
void CEGUI__MultiColumnListProperties__ColumnsMovable_set(void* cls, void* a, void* b){
	((CEGUI::MultiColumnListProperties::ColumnsMovable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiColumnListProperties__ColumnsMovable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiColumnListProperties::ColumnsMovable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::TextParsingEnabled'
//
void CEGUI__WindowProperties__TextParsingEnabled__Destroy(void* cls){
	delete (CEGUI::WindowProperties::TextParsingEnabled*)cls;
}
void CEGUI__WindowProperties__TextParsingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::TextParsingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__TextParsingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::TextParsingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::MouseCursorImage'
//
void CEGUI__WindowProperties__MouseCursorImage__Destroy(void* cls){
	delete (CEGUI::WindowProperties::MouseCursorImage*)cls;
}
void CEGUI__WindowProperties__MouseCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::MouseCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
bool CEGUI__WindowProperties__MouseCursorImage_isDefault(void* cls, void* a){
	return ((CEGUI::WindowProperties::MouseCursorImage*)cls)->isDefault(((CEGUI::PropertyReceiver*)a));
}
void* CEGUI__WindowProperties__MouseCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::MouseCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::ZOrderChangeEnabled'
//
void CEGUI__WindowProperties__ZOrderChangeEnabled__Destroy(void* cls){
	delete (CEGUI::WindowProperties::ZOrderChangeEnabled*)cls;
}
void CEGUI__WindowProperties__ZOrderChangeEnabled_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::ZOrderChangeEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__ZOrderChangeEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::ZOrderChangeEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::DistributeCapturedInputs'
//
void CEGUI__WindowProperties__DistributeCapturedInputs__Destroy(void* cls){
	delete (CEGUI::WindowProperties::DistributeCapturedInputs*)cls;
}
void CEGUI__WindowProperties__DistributeCapturedInputs_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::DistributeCapturedInputs*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__DistributeCapturedInputs_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::DistributeCapturedInputs*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::RiseOnClick'
//
void CEGUI__WindowProperties__RiseOnClick__Destroy(void* cls){
	delete (CEGUI::WindowProperties::RiseOnClick*)cls;
}
void CEGUI__WindowProperties__RiseOnClick_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::RiseOnClick*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__RiseOnClick_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::RiseOnClick*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::DragDropTarget'
//
void CEGUI__WindowProperties__DragDropTarget__Destroy(void* cls){
	delete (CEGUI::WindowProperties::DragDropTarget*)cls;
}
void CEGUI__WindowProperties__DragDropTarget_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::DragDropTarget*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__DragDropTarget_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::DragDropTarget*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::AutoRepeatDelay'
//
void CEGUI__WindowProperties__AutoRepeatDelay__Destroy(void* cls){
	delete (CEGUI::WindowProperties::AutoRepeatDelay*)cls;
}
void CEGUI__WindowProperties__AutoRepeatDelay_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::AutoRepeatDelay*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__AutoRepeatDelay_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::AutoRepeatDelay*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Tooltip'
//
void CEGUI__WindowProperties__Tooltip__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Tooltip*)cls;
}
void CEGUI__WindowProperties__Tooltip_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Tooltip*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__Tooltip_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Tooltip*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedWidth'
//
void CEGUI__WindowProperties__UnifiedWidth__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedWidth*)cls;
}
void CEGUI__WindowProperties__UnifiedWidth_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedWidth*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedWidth_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedWidth*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::CustomTooltipType'
//
void CEGUI__WindowProperties__CustomTooltipType__Destroy(void* cls){
	delete (CEGUI::WindowProperties::CustomTooltipType*)cls;
}
void CEGUI__WindowProperties__CustomTooltipType_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::CustomTooltipType*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__CustomTooltipType_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::CustomTooltipType*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Text'
//
void CEGUI__WindowProperties__Text__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Text*)cls;
}
void CEGUI__WindowProperties__Text_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Text*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__Text_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Text*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::NonClient'
//
void CEGUI__WindowProperties__NonClient__Destroy(void* cls){
	delete (CEGUI::WindowProperties::NonClient*)cls;
}
void CEGUI__WindowProperties__NonClient_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::NonClient*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__NonClient_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::NonClient*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::YRotation'
//
void CEGUI__WindowProperties__YRotation__Destroy(void* cls){
	delete (CEGUI::WindowProperties::YRotation*)cls;
}
void CEGUI__WindowProperties__YRotation_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::YRotation*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__YRotation_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::YRotation*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::WantsMultiClickEvents'
//
void CEGUI__WindowProperties__WantsMultiClickEvents__Destroy(void* cls){
	delete (CEGUI::WindowProperties::WantsMultiClickEvents*)cls;
}
void CEGUI__WindowProperties__WantsMultiClickEvents_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::WantsMultiClickEvents*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__WantsMultiClickEvents_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::WantsMultiClickEvents*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::VerticalAlignment'
//
void CEGUI__WindowProperties__VerticalAlignment__Destroy(void* cls){
	delete (CEGUI::WindowProperties::VerticalAlignment*)cls;
}
void CEGUI__WindowProperties__VerticalAlignment_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::VerticalAlignment*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__VerticalAlignment_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::VerticalAlignment*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::ID'
//
void CEGUI__WindowProperties__ID__Destroy(void* cls){
	delete (CEGUI::WindowProperties::ID*)cls;
}
void CEGUI__WindowProperties__ID_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::ID*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__ID_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::ID*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Disabled'
//
void CEGUI__WindowProperties__Disabled__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Disabled*)cls;
}
void CEGUI__WindowProperties__Disabled_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Disabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
bool CEGUI__WindowProperties__Disabled_isDefault(void* cls, void* a){
	return ((CEGUI::WindowProperties::Disabled*)cls)->isDefault(((CEGUI::PropertyReceiver*)a));
}
void* CEGUI__WindowProperties__Disabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Disabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Margin'
//
void CEGUI__WindowProperties__Margin__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Margin*)cls;
}
void CEGUI__WindowProperties__Margin_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Margin*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__Margin_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Margin*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::ClippedByParent'
//
void CEGUI__WindowProperties__ClippedByParent__Destroy(void* cls){
	delete (CEGUI::WindowProperties::ClippedByParent*)cls;
}
void CEGUI__WindowProperties__ClippedByParent_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::ClippedByParent*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__ClippedByParent_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::ClippedByParent*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::WindowRenderer'
//
void CEGUI__WindowProperties__WindowRenderer__Destroy(void* cls){
	delete (CEGUI::WindowProperties::WindowRenderer*)cls;
}
void CEGUI__WindowProperties__WindowRenderer_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::WindowRenderer*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void CEGUI__WindowProperties__WindowRenderer_writeXMLToStream(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::WindowRenderer*)cls)->writeXMLToStream(((CEGUI::PropertyReceiver*)a), *((CEGUI::XMLSerializer*)b));
}
void* CEGUI__WindowProperties__WindowRenderer_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::WindowRenderer*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::LookNFeel'
//
void CEGUI__WindowProperties__LookNFeel__Destroy(void* cls){
	delete (CEGUI::WindowProperties::LookNFeel*)cls;
}
void CEGUI__WindowProperties__LookNFeel_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::LookNFeel*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void CEGUI__WindowProperties__LookNFeel_writeXMLToStream(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::LookNFeel*)cls)->writeXMLToStream(((CEGUI::PropertyReceiver*)a), *((CEGUI::XMLSerializer*)b));
}
void* CEGUI__WindowProperties__LookNFeel_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::LookNFeel*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedMinSize'
//
void CEGUI__WindowProperties__UnifiedMinSize__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedMinSize*)cls;
}
void CEGUI__WindowProperties__UnifiedMinSize_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedMinSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedMinSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedMinSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Rotation'
//
void CEGUI__WindowProperties__Rotation__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Rotation*)cls;
}
void CEGUI__WindowProperties__Rotation_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Rotation*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__Rotation_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Rotation*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedAreaRect'
//
void CEGUI__WindowProperties__UnifiedAreaRect__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedAreaRect*)cls;
}
void CEGUI__WindowProperties__UnifiedAreaRect_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedAreaRect*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedAreaRect_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedAreaRect*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::InheritsAlpha'
//
void CEGUI__WindowProperties__InheritsAlpha__Destroy(void* cls){
	delete (CEGUI::WindowProperties::InheritsAlpha*)cls;
}
void CEGUI__WindowProperties__InheritsAlpha_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::InheritsAlpha*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__InheritsAlpha_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::InheritsAlpha*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Font'
//
void CEGUI__WindowProperties__Font__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Font*)cls;
}
void CEGUI__WindowProperties__Font_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Font*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
bool CEGUI__WindowProperties__Font_isDefault(void* cls, void* a){
	return ((CEGUI::WindowProperties::Font*)cls)->isDefault(((CEGUI::PropertyReceiver*)a));
}
void* CEGUI__WindowProperties__Font_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Font*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::AutoRenderingSurface'
//
void CEGUI__WindowProperties__AutoRenderingSurface__Destroy(void* cls){
	delete (CEGUI::WindowProperties::AutoRenderingSurface*)cls;
}
void CEGUI__WindowProperties__AutoRenderingSurface_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::AutoRenderingSurface*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__AutoRenderingSurface_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::AutoRenderingSurface*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::MouseButtonDownAutoRepeat'
//
void CEGUI__WindowProperties__MouseButtonDownAutoRepeat__Destroy(void* cls){
	delete (CEGUI::WindowProperties::MouseButtonDownAutoRepeat*)cls;
}
void CEGUI__WindowProperties__MouseButtonDownAutoRepeat_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::MouseButtonDownAutoRepeat*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__MouseButtonDownAutoRepeat_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::MouseButtonDownAutoRepeat*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedPosition'
//
void CEGUI__WindowProperties__UnifiedPosition__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedPosition*)cls;
}
void CEGUI__WindowProperties__UnifiedPosition_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedMaxSize'
//
void CEGUI__WindowProperties__UnifiedMaxSize__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedMaxSize*)cls;
}
void CEGUI__WindowProperties__UnifiedMaxSize_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedMaxSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedMaxSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedMaxSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::InheritsTooltipText'
//
void CEGUI__WindowProperties__InheritsTooltipText__Destroy(void* cls){
	delete (CEGUI::WindowProperties::InheritsTooltipText*)cls;
}
void CEGUI__WindowProperties__InheritsTooltipText_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::InheritsTooltipText*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__InheritsTooltipText_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::InheritsTooltipText*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::XRotation'
//
void CEGUI__WindowProperties__XRotation__Destroy(void* cls){
	delete (CEGUI::WindowProperties::XRotation*)cls;
}
void CEGUI__WindowProperties__XRotation_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::XRotation*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__XRotation_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::XRotation*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::ZRotation'
//
void CEGUI__WindowProperties__ZRotation__Destroy(void* cls){
	delete (CEGUI::WindowProperties::ZRotation*)cls;
}
void CEGUI__WindowProperties__ZRotation_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::ZRotation*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__ZRotation_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::ZRotation*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::DestroyedByParent'
//
void CEGUI__WindowProperties__DestroyedByParent__Destroy(void* cls){
	delete (CEGUI::WindowProperties::DestroyedByParent*)cls;
}
void CEGUI__WindowProperties__DestroyedByParent_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::DestroyedByParent*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__DestroyedByParent_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::DestroyedByParent*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::HorizontalAlignment'
//
void CEGUI__WindowProperties__HorizontalAlignment__Destroy(void* cls){
	delete (CEGUI::WindowProperties::HorizontalAlignment*)cls;
}
void CEGUI__WindowProperties__HorizontalAlignment_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::HorizontalAlignment*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__HorizontalAlignment_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::HorizontalAlignment*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedHeight'
//
void CEGUI__WindowProperties__UnifiedHeight__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedHeight*)cls;
}
void CEGUI__WindowProperties__UnifiedHeight_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedHeight*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedHeight_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedHeight*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::RestoreOldCapture'
//
void CEGUI__WindowProperties__RestoreOldCapture__Destroy(void* cls){
	delete (CEGUI::WindowProperties::RestoreOldCapture*)cls;
}
void CEGUI__WindowProperties__RestoreOldCapture_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::RestoreOldCapture*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__RestoreOldCapture_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::RestoreOldCapture*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Alpha'
//
void CEGUI__WindowProperties__Alpha__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Alpha*)cls;
}
void CEGUI__WindowProperties__Alpha_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Alpha*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__Alpha_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Alpha*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::Visible'
//
void CEGUI__WindowProperties__Visible__Destroy(void* cls){
	delete (CEGUI::WindowProperties::Visible*)cls;
}
void CEGUI__WindowProperties__Visible_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::Visible*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
bool CEGUI__WindowProperties__Visible_isDefault(void* cls, void* a){
	return ((CEGUI::WindowProperties::Visible*)cls)->isDefault(((CEGUI::PropertyReceiver*)a));
}
void* CEGUI__WindowProperties__Visible_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::Visible*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::AutoRepeatRate'
//
void CEGUI__WindowProperties__AutoRepeatRate__Destroy(void* cls){
	delete (CEGUI::WindowProperties::AutoRepeatRate*)cls;
}
void CEGUI__WindowProperties__AutoRepeatRate_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::AutoRepeatRate*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__AutoRepeatRate_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::AutoRepeatRate*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedSize'
//
void CEGUI__WindowProperties__UnifiedSize__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedSize*)cls;
}
void CEGUI__WindowProperties__UnifiedSize_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UpdateMode'
//
void CEGUI__WindowProperties__UpdateMode__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UpdateMode*)cls;
}
void CEGUI__WindowProperties__UpdateMode_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UpdateMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UpdateMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UpdateMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::AlwaysOnTop'
//
void CEGUI__WindowProperties__AlwaysOnTop__Destroy(void* cls){
	delete (CEGUI::WindowProperties::AlwaysOnTop*)cls;
}
void CEGUI__WindowProperties__AlwaysOnTop_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::AlwaysOnTop*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__AlwaysOnTop_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::AlwaysOnTop*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::MouseInputPropagationEnabled'
//
void CEGUI__WindowProperties__MouseInputPropagationEnabled__Destroy(void* cls){
	delete (CEGUI::WindowProperties::MouseInputPropagationEnabled*)cls;
}
void CEGUI__WindowProperties__MouseInputPropagationEnabled_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::MouseInputPropagationEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__MouseInputPropagationEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::MouseInputPropagationEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedXPosition'
//
void CEGUI__WindowProperties__UnifiedXPosition__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedXPosition*)cls;
}
void CEGUI__WindowProperties__UnifiedXPosition_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedXPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedXPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedXPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::MousePassThroughEnabled'
//
void CEGUI__WindowProperties__MousePassThroughEnabled__Destroy(void* cls){
	delete (CEGUI::WindowProperties::MousePassThroughEnabled*)cls;
}
void CEGUI__WindowProperties__MousePassThroughEnabled_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::MousePassThroughEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__MousePassThroughEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::MousePassThroughEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::WindowProperties::UnifiedYPosition'
//
void CEGUI__WindowProperties__UnifiedYPosition__Destroy(void* cls){
	delete (CEGUI::WindowProperties::UnifiedYPosition*)cls;
}
void CEGUI__WindowProperties__UnifiedYPosition_set(void* cls, void* a, void* b){
	((CEGUI::WindowProperties::UnifiedYPosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__WindowProperties__UnifiedYPosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::WindowProperties::UnifiedYPosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::RollUpEnabled'
//
void CEGUI__FrameWindowProperties__RollUpEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::RollUpEnabled*)cls;
}
void CEGUI__FrameWindowProperties__RollUpEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::RollUpEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__RollUpEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::RollUpEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::CloseButtonEnabled'
//
void CEGUI__FrameWindowProperties__CloseButtonEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::CloseButtonEnabled*)cls;
}
void CEGUI__FrameWindowProperties__CloseButtonEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::CloseButtonEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__CloseButtonEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::CloseButtonEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::NESWSizingCursorImage'
//
void CEGUI__FrameWindowProperties__NESWSizingCursorImage__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::NESWSizingCursorImage*)cls;
}
void CEGUI__FrameWindowProperties__NESWSizingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::NESWSizingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__NESWSizingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::NESWSizingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::RollUpState'
//
void CEGUI__FrameWindowProperties__RollUpState__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::RollUpState*)cls;
}
void CEGUI__FrameWindowProperties__RollUpState_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::RollUpState*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__RollUpState_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::RollUpState*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::NWSESizingCursorImage'
//
void CEGUI__FrameWindowProperties__NWSESizingCursorImage__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::NWSESizingCursorImage*)cls;
}
void CEGUI__FrameWindowProperties__NWSESizingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::NWSESizingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__NWSESizingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::NWSESizingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::EWSizingCursorImage'
//
void CEGUI__FrameWindowProperties__EWSizingCursorImage__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::EWSizingCursorImage*)cls;
}
void CEGUI__FrameWindowProperties__EWSizingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::EWSizingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__EWSizingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::EWSizingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::TitlebarEnabled'
//
void CEGUI__FrameWindowProperties__TitlebarEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::TitlebarEnabled*)cls;
}
void CEGUI__FrameWindowProperties__TitlebarEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::TitlebarEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__TitlebarEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::TitlebarEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::FrameEnabled'
//
void CEGUI__FrameWindowProperties__FrameEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::FrameEnabled*)cls;
}
void CEGUI__FrameWindowProperties__FrameEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::FrameEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__FrameEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::FrameEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::DragMovingEnabled'
//
void CEGUI__FrameWindowProperties__DragMovingEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::DragMovingEnabled*)cls;
}
void CEGUI__FrameWindowProperties__DragMovingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::DragMovingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__DragMovingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::DragMovingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::NSSizingCursorImage'
//
void CEGUI__FrameWindowProperties__NSSizingCursorImage__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::NSSizingCursorImage*)cls;
}
void CEGUI__FrameWindowProperties__NSSizingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::NSSizingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__NSSizingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::NSSizingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::SizingEnabled'
//
void CEGUI__FrameWindowProperties__SizingEnabled__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::SizingEnabled*)cls;
}
void CEGUI__FrameWindowProperties__SizingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::SizingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__SizingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::SizingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::FrameWindowProperties::SizingBorderThickness'
//
void CEGUI__FrameWindowProperties__SizingBorderThickness__Destroy(void* cls){
	delete (CEGUI::FrameWindowProperties::SizingBorderThickness*)cls;
}
void CEGUI__FrameWindowProperties__SizingBorderThickness_set(void* cls, void* a, void* b){
	((CEGUI::FrameWindowProperties::SizingBorderThickness*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__FrameWindowProperties__SizingBorderThickness_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::FrameWindowProperties::SizingBorderThickness*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrolledContainerProperties::ContentArea'
//
void CEGUI__ScrolledContainerProperties__ContentArea__Destroy(void* cls){
	delete (CEGUI::ScrolledContainerProperties::ContentArea*)cls;
}
void CEGUI__ScrolledContainerProperties__ContentArea_set(void* cls, void* a, void* b){
	((CEGUI::ScrolledContainerProperties::ContentArea*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrolledContainerProperties__ContentArea_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrolledContainerProperties::ContentArea*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrolledContainerProperties::ChildExtentsArea'
//
void CEGUI__ScrolledContainerProperties__ChildExtentsArea__Destroy(void* cls){
	delete (CEGUI::ScrolledContainerProperties::ChildExtentsArea*)cls;
}
void CEGUI__ScrolledContainerProperties__ChildExtentsArea_set(void* cls, void* a, void* b){
	((CEGUI::ScrolledContainerProperties::ChildExtentsArea*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrolledContainerProperties__ChildExtentsArea_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrolledContainerProperties::ChildExtentsArea*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrolledContainerProperties::ContentPaneAutoSized'
//
void CEGUI__ScrolledContainerProperties__ContentPaneAutoSized__Destroy(void* cls){
	delete (CEGUI::ScrolledContainerProperties::ContentPaneAutoSized*)cls;
}
void CEGUI__ScrolledContainerProperties__ContentPaneAutoSized_set(void* cls, void* a, void* b){
	((CEGUI::ScrolledContainerProperties::ContentPaneAutoSized*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrolledContainerProperties__ContentPaneAutoSized_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrolledContainerProperties::ContentPaneAutoSized*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemListboxProperties::MultiSelect'
//
void CEGUI__ItemListboxProperties__MultiSelect__Destroy(void* cls){
	delete (CEGUI::ItemListboxProperties::MultiSelect*)cls;
}
void CEGUI__ItemListboxProperties__MultiSelect_set(void* cls, void* a, void* b){
	((CEGUI::ItemListboxProperties::MultiSelect*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemListboxProperties__MultiSelect_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemListboxProperties::MultiSelect*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::EditSelectionLength'
//
void CEGUI__ComboboxProperties__EditSelectionLength__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::EditSelectionLength*)cls;
}
void CEGUI__ComboboxProperties__EditSelectionLength_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::EditSelectionLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__EditSelectionLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::EditSelectionLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::ForceHorzScrollbar'
//
void CEGUI__ComboboxProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__ComboboxProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::CaratIndex'
//
void CEGUI__ComboboxProperties__CaratIndex__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::CaratIndex*)cls;
}
void CEGUI__ComboboxProperties__CaratIndex_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::CaratIndex*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__CaratIndex_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::CaratIndex*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::MaxEditTextLength'
//
void CEGUI__ComboboxProperties__MaxEditTextLength__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::MaxEditTextLength*)cls;
}
void CEGUI__ComboboxProperties__MaxEditTextLength_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::MaxEditTextLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__MaxEditTextLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::MaxEditTextLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::ForceVertScrollbar'
//
void CEGUI__ComboboxProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::ForceVertScrollbar*)cls;
}
void CEGUI__ComboboxProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::SingleClickMode'
//
void CEGUI__ComboboxProperties__SingleClickMode__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::SingleClickMode*)cls;
}
void CEGUI__ComboboxProperties__SingleClickMode_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::SingleClickMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__SingleClickMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::SingleClickMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::SortList'
//
void CEGUI__ComboboxProperties__SortList__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::SortList*)cls;
}
void CEGUI__ComboboxProperties__SortList_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::SortList*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__SortList_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::SortList*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::EditSelectionStart'
//
void CEGUI__ComboboxProperties__EditSelectionStart__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::EditSelectionStart*)cls;
}
void CEGUI__ComboboxProperties__EditSelectionStart_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::EditSelectionStart*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__EditSelectionStart_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::EditSelectionStart*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::ReadOnly'
//
void CEGUI__ComboboxProperties__ReadOnly__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::ReadOnly*)cls;
}
void CEGUI__ComboboxProperties__ReadOnly_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::ReadOnly*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__ReadOnly_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::ReadOnly*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ComboboxProperties::ValidationString'
//
void CEGUI__ComboboxProperties__ValidationString__Destroy(void* cls){
	delete (CEGUI::ComboboxProperties::ValidationString*)cls;
}
void CEGUI__ComboboxProperties__ValidationString_set(void* cls, void* a, void* b){
	((CEGUI::ComboboxProperties::ValidationString*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ComboboxProperties__ValidationString_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ComboboxProperties::ValidationString*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::DraggingEnabled'
//
void CEGUI__DragContainerProperties__DraggingEnabled__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::DraggingEnabled*)cls;
}
void CEGUI__DragContainerProperties__DraggingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::DraggingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__DraggingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::DraggingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::FixedDragOffset'
//
void CEGUI__DragContainerProperties__FixedDragOffset__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::FixedDragOffset*)cls;
}
void CEGUI__DragContainerProperties__FixedDragOffset_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::FixedDragOffset*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__FixedDragOffset_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::FixedDragOffset*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::DragThreshold'
//
void CEGUI__DragContainerProperties__DragThreshold__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::DragThreshold*)cls;
}
void CEGUI__DragContainerProperties__DragThreshold_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::DragThreshold*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__DragThreshold_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::DragThreshold*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::UseFixedDragOffset'
//
void CEGUI__DragContainerProperties__UseFixedDragOffset__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::UseFixedDragOffset*)cls;
}
void CEGUI__DragContainerProperties__UseFixedDragOffset_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::UseFixedDragOffset*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__UseFixedDragOffset_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::UseFixedDragOffset*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::StickyMode'
//
void CEGUI__DragContainerProperties__StickyMode__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::StickyMode*)cls;
}
void CEGUI__DragContainerProperties__StickyMode_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::StickyMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__StickyMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::StickyMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::DragCursorImage'
//
void CEGUI__DragContainerProperties__DragCursorImage__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::DragCursorImage*)cls;
}
void CEGUI__DragContainerProperties__DragCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::DragCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__DragCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::DragCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::DragContainerProperties::DragAlpha'
//
void CEGUI__DragContainerProperties__DragAlpha__Destroy(void* cls){
	delete (CEGUI::DragContainerProperties::DragAlpha*)cls;
}
void CEGUI__DragContainerProperties__DragAlpha_set(void* cls, void* a, void* b){
	((CEGUI::DragContainerProperties::DragAlpha*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__DragContainerProperties__DragAlpha_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::DragContainerProperties::DragAlpha*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemEntryProperties::Selected'
//
void CEGUI__ItemEntryProperties__Selected__Destroy(void* cls){
	delete (CEGUI::ItemEntryProperties::Selected*)cls;
}
void CEGUI__ItemEntryProperties__Selected_set(void* cls, void* a, void* b){
	((CEGUI::ItemEntryProperties::Selected*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemEntryProperties__Selected_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemEntryProperties::Selected*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemEntryProperties::Selectable'
//
void CEGUI__ItemEntryProperties__Selectable__Destroy(void* cls){
	delete (CEGUI::ItemEntryProperties::Selectable*)cls;
}
void CEGUI__ItemEntryProperties__Selectable_set(void* cls, void* a, void* b){
	((CEGUI::ItemEntryProperties::Selectable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemEntryProperties__Selectable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemEntryProperties::Selectable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TooltipProperties::HoverTime'
//
void CEGUI__TooltipProperties__HoverTime__Destroy(void* cls){
	delete (CEGUI::TooltipProperties::HoverTime*)cls;
}
void CEGUI__TooltipProperties__HoverTime_set(void* cls, void* a, void* b){
	((CEGUI::TooltipProperties::HoverTime*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TooltipProperties__HoverTime_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TooltipProperties::HoverTime*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TooltipProperties::DisplayTime'
//
void CEGUI__TooltipProperties__DisplayTime__Destroy(void* cls){
	delete (CEGUI::TooltipProperties::DisplayTime*)cls;
}
void CEGUI__TooltipProperties__DisplayTime_set(void* cls, void* a, void* b){
	((CEGUI::TooltipProperties::DisplayTime*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TooltipProperties__DisplayTime_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TooltipProperties::DisplayTime*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TooltipProperties::FadeTime'
//
void CEGUI__TooltipProperties__FadeTime__Destroy(void* cls){
	delete (CEGUI::TooltipProperties::FadeTime*)cls;
}
void CEGUI__TooltipProperties__FadeTime_set(void* cls, void* a, void* b){
	((CEGUI::TooltipProperties::FadeTime*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TooltipProperties__FadeTime_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TooltipProperties::FadeTime*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderProperties::ColumnsMovable'
//
void CEGUI__ListHeaderProperties__ColumnsMovable__Destroy(void* cls){
	delete (CEGUI::ListHeaderProperties::ColumnsMovable*)cls;
}
void CEGUI__ListHeaderProperties__ColumnsMovable_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderProperties::ColumnsMovable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderProperties__ColumnsMovable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderProperties::ColumnsMovable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderProperties::ColumnsSizable'
//
void CEGUI__ListHeaderProperties__ColumnsSizable__Destroy(void* cls){
	delete (CEGUI::ListHeaderProperties::ColumnsSizable*)cls;
}
void CEGUI__ListHeaderProperties__ColumnsSizable_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderProperties::ColumnsSizable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderProperties__ColumnsSizable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderProperties::ColumnsSizable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderProperties::SortDirection'
//
void CEGUI__ListHeaderProperties__SortDirection__Destroy(void* cls){
	delete (CEGUI::ListHeaderProperties::SortDirection*)cls;
}
void CEGUI__ListHeaderProperties__SortDirection_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderProperties::SortDirection*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderProperties__SortDirection_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderProperties::SortDirection*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderProperties::SortSettingEnabled'
//
void CEGUI__ListHeaderProperties__SortSettingEnabled__Destroy(void* cls){
	delete (CEGUI::ListHeaderProperties::SortSettingEnabled*)cls;
}
void CEGUI__ListHeaderProperties__SortSettingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderProperties::SortSettingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderProperties__SortSettingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderProperties::SortSettingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderProperties::SortColumnID'
//
void CEGUI__ListHeaderProperties__SortColumnID__Destroy(void* cls){
	delete (CEGUI::ListHeaderProperties::SortColumnID*)cls;
}
void CEGUI__ListHeaderProperties__SortColumnID_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderProperties::SortColumnID*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderProperties__SortColumnID_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderProperties::SortColumnID*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemListBaseProperties::SortEnabled'
//
void CEGUI__ItemListBaseProperties__SortEnabled__Destroy(void* cls){
	delete (CEGUI::ItemListBaseProperties::SortEnabled*)cls;
}
void CEGUI__ItemListBaseProperties__SortEnabled_set(void* cls, void* a, void* b){
	((CEGUI::ItemListBaseProperties::SortEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemListBaseProperties__SortEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemListBaseProperties::SortEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemListBaseProperties::AutoResizeEnabled'
//
void CEGUI__ItemListBaseProperties__AutoResizeEnabled__Destroy(void* cls){
	delete (CEGUI::ItemListBaseProperties::AutoResizeEnabled*)cls;
}
void CEGUI__ItemListBaseProperties__AutoResizeEnabled_set(void* cls, void* a, void* b){
	((CEGUI::ItemListBaseProperties::AutoResizeEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemListBaseProperties__AutoResizeEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemListBaseProperties::AutoResizeEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ItemListBaseProperties::SortMode'
//
void CEGUI__ItemListBaseProperties__SortMode__Destroy(void* cls){
	delete (CEGUI::ItemListBaseProperties::SortMode*)cls;
}
void CEGUI__ItemListBaseProperties__SortMode_set(void* cls, void* a, void* b){
	((CEGUI::ItemListBaseProperties::SortMode*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ItemListBaseProperties__SortMode_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ItemListBaseProperties::SortMode*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TitlebarProperties::DraggingEnabled'
//
void CEGUI__TitlebarProperties__DraggingEnabled__Destroy(void* cls){
	delete (CEGUI::TitlebarProperties::DraggingEnabled*)cls;
}
void CEGUI__TitlebarProperties__DraggingEnabled_set(void* cls, void* a, void* b){
	((CEGUI::TitlebarProperties::DraggingEnabled*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TitlebarProperties__DraggingEnabled_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TitlebarProperties::DraggingEnabled*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Dragable'
//
void CEGUI__ListHeaderSegmentProperties__Dragable__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::Dragable*)cls;
}
void CEGUI__ListHeaderSegmentProperties__Dragable_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::Dragable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__Dragable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::Dragable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::SizingCursorImage'
//
void CEGUI__ListHeaderSegmentProperties__SizingCursorImage__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::SizingCursorImage*)cls;
}
void CEGUI__ListHeaderSegmentProperties__SizingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::SizingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__SizingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::SizingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Sizable'
//
void CEGUI__ListHeaderSegmentProperties__Sizable__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::Sizable*)cls;
}
void CEGUI__ListHeaderSegmentProperties__Sizable_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::Sizable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__Sizable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::Sizable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Clickable'
//
void CEGUI__ListHeaderSegmentProperties__Clickable__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::Clickable*)cls;
}
void CEGUI__ListHeaderSegmentProperties__Clickable_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::Clickable*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__Clickable_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::Clickable*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::SortDirection'
//
void CEGUI__ListHeaderSegmentProperties__SortDirection__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::SortDirection*)cls;
}
void CEGUI__ListHeaderSegmentProperties__SortDirection_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::SortDirection*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__SortDirection_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::SortDirection*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::MovingCursorImage'
//
void CEGUI__ListHeaderSegmentProperties__MovingCursorImage__Destroy(void* cls){
	delete (CEGUI::ListHeaderSegmentProperties::MovingCursorImage*)cls;
}
void CEGUI__ListHeaderSegmentProperties__MovingCursorImage_set(void* cls, void* a, void* b){
	((CEGUI::ListHeaderSegmentProperties::MovingCursorImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListHeaderSegmentProperties__MovingCursorImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListHeaderSegmentProperties::MovingCursorImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ProgressBarProperties::CurrentProgress'
//
void CEGUI__ProgressBarProperties__CurrentProgress__Destroy(void* cls){
	delete (CEGUI::ProgressBarProperties::CurrentProgress*)cls;
}
void CEGUI__ProgressBarProperties__CurrentProgress_set(void* cls, void* a, void* b){
	((CEGUI::ProgressBarProperties::CurrentProgress*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ProgressBarProperties__CurrentProgress_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ProgressBarProperties::CurrentProgress*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ProgressBarProperties::StepSize'
//
void CEGUI__ProgressBarProperties__StepSize__Destroy(void* cls){
	delete (CEGUI::ProgressBarProperties::StepSize*)cls;
}
void CEGUI__ProgressBarProperties__StepSize_set(void* cls, void* a, void* b){
	((CEGUI::ProgressBarProperties::StepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ProgressBarProperties__StepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ProgressBarProperties::StepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TreeProperties::Sort'
//
void CEGUI__TreeProperties__Sort__Destroy(void* cls){
	delete (CEGUI::TreeProperties::Sort*)cls;
}
void CEGUI__TreeProperties__Sort_set(void* cls, void* a, void* b){
	((CEGUI::TreeProperties::Sort*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TreeProperties__Sort_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TreeProperties::Sort*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TreeProperties::MultiSelect'
//
void CEGUI__TreeProperties__MultiSelect__Destroy(void* cls){
	delete (CEGUI::TreeProperties::MultiSelect*)cls;
}
void CEGUI__TreeProperties__MultiSelect_set(void* cls, void* a, void* b){
	((CEGUI::TreeProperties::MultiSelect*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TreeProperties__MultiSelect_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TreeProperties::MultiSelect*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TreeProperties::ItemTooltips'
//
void CEGUI__TreeProperties__ItemTooltips__Destroy(void* cls){
	delete (CEGUI::TreeProperties::ItemTooltips*)cls;
}
void CEGUI__TreeProperties__ItemTooltips_set(void* cls, void* a, void* b){
	((CEGUI::TreeProperties::ItemTooltips*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TreeProperties__ItemTooltips_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TreeProperties::ItemTooltips*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TreeProperties::ForceVertScrollbar'
//
void CEGUI__TreeProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::TreeProperties::ForceVertScrollbar*)cls;
}
void CEGUI__TreeProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::TreeProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TreeProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TreeProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TreeProperties::ForceHorzScrollbar'
//
void CEGUI__TreeProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::TreeProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__TreeProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::TreeProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TreeProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TreeProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::RadioButtonProperties::Selected'
//
void CEGUI__RadioButtonProperties__Selected__Destroy(void* cls){
	delete (CEGUI::RadioButtonProperties::Selected*)cls;
}
void CEGUI__RadioButtonProperties__Selected_set(void* cls, void* a, void* b){
	((CEGUI::RadioButtonProperties::Selected*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__RadioButtonProperties__Selected_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::RadioButtonProperties::Selected*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::RadioButtonProperties::GroupID'
//
void CEGUI__RadioButtonProperties__GroupID__Destroy(void* cls){
	delete (CEGUI::RadioButtonProperties::GroupID*)cls;
}
void CEGUI__RadioButtonProperties__GroupID_set(void* cls, void* a, void* b){
	((CEGUI::RadioButtonProperties::GroupID*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__RadioButtonProperties__GroupID_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::RadioButtonProperties::GroupID*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListboxProperties::MultiSelect'
//
void CEGUI__ListboxProperties__MultiSelect__Destroy(void* cls){
	delete (CEGUI::ListboxProperties::MultiSelect*)cls;
}
void CEGUI__ListboxProperties__MultiSelect_set(void* cls, void* a, void* b){
	((CEGUI::ListboxProperties::MultiSelect*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListboxProperties__MultiSelect_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListboxProperties::MultiSelect*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListboxProperties::ItemTooltips'
//
void CEGUI__ListboxProperties__ItemTooltips__Destroy(void* cls){
	delete (CEGUI::ListboxProperties::ItemTooltips*)cls;
}
void CEGUI__ListboxProperties__ItemTooltips_set(void* cls, void* a, void* b){
	((CEGUI::ListboxProperties::ItemTooltips*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListboxProperties__ItemTooltips_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListboxProperties::ItemTooltips*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListboxProperties::ForceHorzScrollbar'
//
void CEGUI__ListboxProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::ListboxProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__ListboxProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ListboxProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListboxProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListboxProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListboxProperties::Sort'
//
void CEGUI__ListboxProperties__Sort__Destroy(void* cls){
	delete (CEGUI::ListboxProperties::Sort*)cls;
}
void CEGUI__ListboxProperties__Sort_set(void* cls, void* a, void* b){
	((CEGUI::ListboxProperties::Sort*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListboxProperties__Sort_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListboxProperties::Sort*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ListboxProperties::ForceVertScrollbar'
//
void CEGUI__ListboxProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::ListboxProperties::ForceVertScrollbar*)cls;
}
void CEGUI__ListboxProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ListboxProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ListboxProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ListboxProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::SelectionStart'
//
void CEGUI__EditboxProperties__SelectionStart__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::SelectionStart*)cls;
}
void CEGUI__EditboxProperties__SelectionStart_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::SelectionStart*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__SelectionStart_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::SelectionStart*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::NormalTextColour'
//
void CEGUI__EditboxProperties__NormalTextColour__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::NormalTextColour*)cls;
}
void CEGUI__EditboxProperties__NormalTextColour_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::NormalTextColour*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__NormalTextColour_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::NormalTextColour*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::MaskText'
//
void CEGUI__EditboxProperties__MaskText__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::MaskText*)cls;
}
void CEGUI__EditboxProperties__MaskText_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::MaskText*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__MaskText_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::MaskText*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::CaratIndex'
//
void CEGUI__EditboxProperties__CaratIndex__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::CaratIndex*)cls;
}
void CEGUI__EditboxProperties__CaratIndex_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::CaratIndex*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__CaratIndex_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::CaratIndex*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::MaskCodepoint'
//
void CEGUI__EditboxProperties__MaskCodepoint__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::MaskCodepoint*)cls;
}
void CEGUI__EditboxProperties__MaskCodepoint_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::MaskCodepoint*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__MaskCodepoint_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::MaskCodepoint*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::ActiveSelectionColour'
//
void CEGUI__EditboxProperties__ActiveSelectionColour__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::ActiveSelectionColour*)cls;
}
void CEGUI__EditboxProperties__ActiveSelectionColour_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::ActiveSelectionColour*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__ActiveSelectionColour_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::ActiveSelectionColour*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::SelectedTextColour'
//
void CEGUI__EditboxProperties__SelectedTextColour__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::SelectedTextColour*)cls;
}
void CEGUI__EditboxProperties__SelectedTextColour_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::SelectedTextColour*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__SelectedTextColour_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::SelectedTextColour*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::InactiveSelectionColour'
//
void CEGUI__EditboxProperties__InactiveSelectionColour__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::InactiveSelectionColour*)cls;
}
void CEGUI__EditboxProperties__InactiveSelectionColour_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::InactiveSelectionColour*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__InactiveSelectionColour_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::InactiveSelectionColour*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::ReadOnly'
//
void CEGUI__EditboxProperties__ReadOnly__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::ReadOnly*)cls;
}
void CEGUI__EditboxProperties__ReadOnly_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::ReadOnly*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__ReadOnly_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::ReadOnly*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::SelectionLength'
//
void CEGUI__EditboxProperties__SelectionLength__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::SelectionLength*)cls;
}
void CEGUI__EditboxProperties__SelectionLength_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::SelectionLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__SelectionLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::SelectionLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::ValidationString'
//
void CEGUI__EditboxProperties__ValidationString__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::ValidationString*)cls;
}
void CEGUI__EditboxProperties__ValidationString_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::ValidationString*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__ValidationString_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::ValidationString*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::EditboxProperties::MaxTextLength'
//
void CEGUI__EditboxProperties__MaxTextLength__Destroy(void* cls){
	delete (CEGUI::EditboxProperties::MaxTextLength*)cls;
}
void CEGUI__EditboxProperties__MaxTextLength_set(void* cls, void* a, void* b){
	((CEGUI::EditboxProperties::MaxTextLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__EditboxProperties__MaxTextLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::EditboxProperties::MaxTextLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrolledItemListBaseProperties::ForceHorzScrollbar'
//
void CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar__Destroy(void* cls){
	delete (CEGUI::ScrolledItemListBaseProperties::ForceHorzScrollbar*)cls;
}
void CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ScrolledItemListBaseProperties::ForceHorzScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrolledItemListBaseProperties::ForceHorzScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::ScrolledItemListBaseProperties::ForceVertScrollbar'
//
void CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::ScrolledItemListBaseProperties::ForceVertScrollbar*)cls;
}
void CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::ScrolledItemListBaseProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::ScrolledItemListBaseProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SliderProperties::MaximumValue'
//
void CEGUI__SliderProperties__MaximumValue__Destroy(void* cls){
	delete (CEGUI::SliderProperties::MaximumValue*)cls;
}
void CEGUI__SliderProperties__MaximumValue_set(void* cls, void* a, void* b){
	((CEGUI::SliderProperties::MaximumValue*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SliderProperties__MaximumValue_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SliderProperties::MaximumValue*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SliderProperties::CurrentValue'
//
void CEGUI__SliderProperties__CurrentValue__Destroy(void* cls){
	delete (CEGUI::SliderProperties::CurrentValue*)cls;
}
void CEGUI__SliderProperties__CurrentValue_set(void* cls, void* a, void* b){
	((CEGUI::SliderProperties::CurrentValue*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SliderProperties__CurrentValue_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SliderProperties::CurrentValue*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::SliderProperties::ClickStepSize'
//
void CEGUI__SliderProperties__ClickStepSize__Destroy(void* cls){
	delete (CEGUI::SliderProperties::ClickStepSize*)cls;
}
void CEGUI__SliderProperties__ClickStepSize_set(void* cls, void* a, void* b){
	((CEGUI::SliderProperties::ClickStepSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__SliderProperties__ClickStepSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::SliderProperties::ClickStepSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MenuBaseProperties::ItemSpacing'
//
void CEGUI__MenuBaseProperties__ItemSpacing__Destroy(void* cls){
	delete (CEGUI::MenuBaseProperties::ItemSpacing*)cls;
}
void CEGUI__MenuBaseProperties__ItemSpacing_set(void* cls, void* a, void* b){
	((CEGUI::MenuBaseProperties::ItemSpacing*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MenuBaseProperties__ItemSpacing_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MenuBaseProperties::ItemSpacing*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MenuBaseProperties::AllowMultiplePopups'
//
void CEGUI__MenuBaseProperties__AllowMultiplePopups__Destroy(void* cls){
	delete (CEGUI::MenuBaseProperties::AllowMultiplePopups*)cls;
}
void CEGUI__MenuBaseProperties__AllowMultiplePopups_set(void* cls, void* a, void* b){
	((CEGUI::MenuBaseProperties::AllowMultiplePopups*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MenuBaseProperties__AllowMultiplePopups_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MenuBaseProperties::AllowMultiplePopups*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::ReadOnly'
//
void CEGUI__MultiLineEditboxProperties__ReadOnly__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::ReadOnly*)cls;
}
void CEGUI__MultiLineEditboxProperties__ReadOnly_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::ReadOnly*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__ReadOnly_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::ReadOnly*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::CaratIndex'
//
void CEGUI__MultiLineEditboxProperties__CaratIndex__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::CaratIndex*)cls;
}
void CEGUI__MultiLineEditboxProperties__CaratIndex_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::CaratIndex*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__CaratIndex_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::CaratIndex*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionStart'
//
void CEGUI__MultiLineEditboxProperties__SelectionStart__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::SelectionStart*)cls;
}
void CEGUI__MultiLineEditboxProperties__SelectionStart_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::SelectionStart*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__SelectionStart_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::SelectionStart*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::ForceVertScrollbar'
//
void CEGUI__MultiLineEditboxProperties__ForceVertScrollbar__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::ForceVertScrollbar*)cls;
}
void CEGUI__MultiLineEditboxProperties__ForceVertScrollbar_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::ForceVertScrollbar*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__ForceVertScrollbar_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::ForceVertScrollbar*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionLength'
//
void CEGUI__MultiLineEditboxProperties__SelectionLength__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::SelectionLength*)cls;
}
void CEGUI__MultiLineEditboxProperties__SelectionLength_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::SelectionLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__SelectionLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::SelectionLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::MaxTextLength'
//
void CEGUI__MultiLineEditboxProperties__MaxTextLength__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::MaxTextLength*)cls;
}
void CEGUI__MultiLineEditboxProperties__MaxTextLength_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::MaxTextLength*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__MaxTextLength_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::MaxTextLength*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::WordWrap'
//
void CEGUI__MultiLineEditboxProperties__WordWrap__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::WordWrap*)cls;
}
void CEGUI__MultiLineEditboxProperties__WordWrap_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::WordWrap*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__WordWrap_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::WordWrap*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionBrushImage'
//
void CEGUI__MultiLineEditboxProperties__SelectionBrushImage__Destroy(void* cls){
	delete (CEGUI::MultiLineEditboxProperties::SelectionBrushImage*)cls;
}
void CEGUI__MultiLineEditboxProperties__SelectionBrushImage_set(void* cls, void* a, void* b){
	((CEGUI::MultiLineEditboxProperties::SelectionBrushImage*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__MultiLineEditboxProperties__SelectionBrushImage_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::MultiLineEditboxProperties::SelectionBrushImage*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TabControlProperties::TabPanePosition'
//
void CEGUI__TabControlProperties__TabPanePosition__Destroy(void* cls){
	delete (CEGUI::TabControlProperties::TabPanePosition*)cls;
}
void CEGUI__TabControlProperties__TabPanePosition_set(void* cls, void* a, void* b){
	((CEGUI::TabControlProperties::TabPanePosition*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TabControlProperties__TabPanePosition_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TabControlProperties::TabPanePosition*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TabControlProperties::TabHeight'
//
void CEGUI__TabControlProperties__TabHeight__Destroy(void* cls){
	delete (CEGUI::TabControlProperties::TabHeight*)cls;
}
void CEGUI__TabControlProperties__TabHeight_set(void* cls, void* a, void* b){
	((CEGUI::TabControlProperties::TabHeight*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TabControlProperties__TabHeight_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TabControlProperties::TabHeight*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::TabControlProperties::TabTextPadding'
//
void CEGUI__TabControlProperties__TabTextPadding__Destroy(void* cls){
	delete (CEGUI::TabControlProperties::TabTextPadding*)cls;
}
void CEGUI__TabControlProperties__TabTextPadding_set(void* cls, void* a, void* b){
	((CEGUI::TabControlProperties::TabTextPadding*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__TabControlProperties__TabTextPadding_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::TabControlProperties::TabTextPadding*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::GridLayoutContainerProperties::GridSize'
//
void CEGUI__GridLayoutContainerProperties__GridSize__Destroy(void* cls){
	delete (CEGUI::GridLayoutContainerProperties::GridSize*)cls;
}
void CEGUI__GridLayoutContainerProperties__GridSize_set(void* cls, void* a, void* b){
	((CEGUI::GridLayoutContainerProperties::GridSize*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__GridLayoutContainerProperties__GridSize_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::GridLayoutContainerProperties::GridSize*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::GridLayoutContainerProperties::AutoPositioning'
//
void CEGUI__GridLayoutContainerProperties__AutoPositioning__Destroy(void* cls){
	delete (CEGUI::GridLayoutContainerProperties::AutoPositioning*)cls;
}
void CEGUI__GridLayoutContainerProperties__AutoPositioning_set(void* cls, void* a, void* b){
	((CEGUI::GridLayoutContainerProperties::AutoPositioning*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__GridLayoutContainerProperties__AutoPositioning_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::GridLayoutContainerProperties::AutoPositioning*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}

//
// Begin class 'CEGUI::CheckboxProperties::Selected'
//
void CEGUI__CheckboxProperties__Selected__Destroy(void* cls){
	delete (CEGUI::CheckboxProperties::Selected*)cls;
}
void CEGUI__CheckboxProperties__Selected_set(void* cls, void* a, void* b){
	((CEGUI::CheckboxProperties::Selected*)cls)->set(((CEGUI::PropertyReceiver*)a), *((CEGUI::String*)b));
}
void* CEGUI__CheckboxProperties__Selected_get(void* cls, void* a){
	return new CEGUI::String(((CEGUI::CheckboxProperties::Selected*)cls)->get(((CEGUI::PropertyReceiver*)a)));
}