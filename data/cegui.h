extern "C" {

//
// Begin class 'CEGUI::RenderedStringImageComponent'
//
void CEGUI__RenderedStringImageComponent__Destroy(void*);
void CEGUI__RenderedStringImageComponent_draw(void*, void*, void*, void*, void*, float, float);
void CEGUI__RenderedStringImageComponent_setImage0(void*, void*, void*);
void CEGUI__RenderedStringImageComponent_setImage1(void*, void*);
void* CEGUI__RenderedStringImageComponent_clone(void*);
void* CEGUI__RenderedStringImageComponent_getPixelSize(void*);
bool CEGUI__RenderedStringImageComponent_canSplit(void*);
void* CEGUI__RenderedStringImageComponent_getSize(void*);
void* CEGUI__RenderedStringImageComponent_split(void*, float, bool);
void* CEGUI__RenderedStringImageComponent_getColours(void*);
unsigned int CEGUI__RenderedStringImageComponent_getSpaceCount(void*);
void* CEGUI__RenderedStringImageComponent_getImage(void*);
void CEGUI__RenderedStringImageComponent_setSize(void*, void*);
void CEGUI__RenderedStringImageComponent_setColours0(void*, void*);
void CEGUI__RenderedStringImageComponent_setColours1(void*, void*);

//
// Begin class 'CEGUI::BoolInterpolator'
//
void CEGUI__BoolInterpolator__Destroy(void*);
void* CEGUI__BoolInterpolator_getType(void*);
void* CEGUI__BoolInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__BoolInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__BoolInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::FontDim'
//
void CEGUI__FontDim__Destroy(void*);

//
// Begin class 'CEGUI::MouseCursor'
//
void* CEGUI__MouseCursor__Create();
void CEGUI__MouseCursor__Destroy(void*);
void CEGUI__MouseCursor_invalidate(void*);
void CEGUI__MouseCursor_show(void*);
void CEGUI__MouseCursor_setInitialMousePosition(void*, void*);
void CEGUI__MouseCursor_offsetPosition(void*, void*);
void CEGUI__MouseCursor_setExplicitRenderSize(void*, void*);
void CEGUI__MouseCursor_hide(void*);
void CEGUI__MouseCursor_draw(void*);
void* CEGUI__MouseCursor_getUnifiedConstraintArea(void*);
void CEGUI__MouseCursor_setUnifiedConstraintArea(void*, void*);
void* CEGUI__MouseCursor_getDisplayIndependantPosition(void*);
void CEGUI__MouseCursor_notifyDisplaySizeChanged(void*, void*);
void CEGUI__MouseCursor_setPosition(void*, void*);
void* CEGUI__MouseCursor_getPosition(void*);
void CEGUI__MouseCursor_setConstraintArea(void*, void*);
void* CEGUI__MouseCursor_getConstraintArea(void*);
void* CEGUI__MouseCursor_getSingletonPtr(void*);
void CEGUI__MouseCursor_setImage0(void*, void*, void*);
void CEGUI__MouseCursor_setImage1(void*, void*);
void* CEGUI__MouseCursor_getSingleton(void*);
bool CEGUI__MouseCursor_isVisible(void*);
void* CEGUI__MouseCursor_getImage(void*);
void CEGUI__MouseCursor_setVisible(void*, bool);
void* CEGUI__MouseCursor_getExplicitRenderSize(void*);

//
// Begin class 'CEGUI::ImagesetManager'
//
void* CEGUI__ImagesetManager__Create();
void CEGUI__ImagesetManager__Destroy(void*);
void* CEGUI__ImagesetManager_create(void*, void*, void*, unsigned int);
void CEGUI__ImagesetManager_notifyDisplaySizeChanged(void*, void*);
void* CEGUI__ImagesetManager_createFromImageFile(void*, void*, void*, void*, unsigned int);

//
// Begin class 'CEGUI::Menubar'
//
void CEGUI__Menubar__Destroy(void*);

//
// Begin class 'CEGUI::NamedArea'
//
void* CEGUI__NamedArea__Create0();
void* CEGUI__NamedArea__Create1(void*);
void CEGUI__NamedArea__Destroy(void*);
void* CEGUI__NamedArea_getArea(void*);
void* CEGUI__NamedArea_getName(void*);
void CEGUI__NamedArea_setArea(void*, void*);
void CEGUI__NamedArea_writeXMLToStream(void*, void*);

//
// Begin class 'CEGUI::PropertyDefinition'
//
void CEGUI__PropertyDefinition__Destroy(void*);
void CEGUI__PropertyDefinition_set(void*, void*, void*);
void* CEGUI__PropertyDefinition_get(void*, void*);

//
// Begin class 'CEGUI::colour'
//
void* CEGUI__colour__Create0();
void* CEGUI__colour__Create1(void*);
void* CEGUI__colour__Create2(float, float, float, float);
void* CEGUI__colour__Create3(unsigned int);
void CEGUI__colour__Destroy(void*);
void CEGUI__colour_invertColourWithAlpha(void*);
void CEGUI__colour_setBlue(void*, float);
float CEGUI__colour_getHue(void*);
float CEGUI__colour_getLumination(void*);
void CEGUI__colour_setARGB(void*, unsigned int);
unsigned int CEGUI__colour_getARGB(void*);
void CEGUI__colour_setRGB0(void*, float, float, float);
void CEGUI__colour_setRGB1(void*, void*);
void CEGUI__colour_setGreen(void*, float);
void CEGUI__colour_set(void*, float, float, float, float);
void CEGUI__colour_setAlpha(void*, float);
float CEGUI__colour_getGreen(void*);
float CEGUI__colour_getBlue(void*);
float CEGUI__colour_getAlpha(void*);
float CEGUI__colour_getSaturation(void*);
void CEGUI__colour_setRed(void*, float);
void CEGUI__colour_invertColour(void*);
void CEGUI__colour_setHSL(void*, float, float, float, float);
float CEGUI__colour_getRed(void*);

//
// Begin class 'CEGUI::DragContainer'
//
void* CEGUI__DragContainer__Create(void*, void*);
void CEGUI__DragContainer__Destroy(void*);
void* CEGUI__DragContainer_getDragCursorImage(void*);
void* CEGUI__DragContainer_getFixedDragOffset(void*);
void CEGUI__DragContainer_setDraggingEnabled(void*, bool);
bool CEGUI__DragContainer_pickUp(void*, bool);
bool CEGUI__DragContainer_isUsingFixedDragOffset(void*);
void CEGUI__DragContainer_setDragCursorImage0(void*, void*);
void CEGUI__DragContainer_setDragCursorImage1(void*, unsigned int);
void CEGUI__DragContainer_setDragCursorImage2(void*, void*, void*);
void CEGUI__DragContainer_setUsingFixedDragOffset(void*, bool);
bool CEGUI__DragContainer_isBeingDragged(void*);
bool CEGUI__DragContainer_isStickyModeEnabled(void*);
float CEGUI__DragContainer_getDragAlpha(void*);
void CEGUI__DragContainer_setFixedDragOffset(void*, void*);
void CEGUI__DragContainer_setPixelDragThreshold(void*, float);
float CEGUI__DragContainer_getPixelDragThreshold(void*);
void* CEGUI__DragContainer_getCurrentDropTarget(void*);
bool CEGUI__DragContainer_isDraggingEnabled(void*);
void CEGUI__DragContainer_setStickyModeEnabled(void*, bool);
void CEGUI__DragContainer_setDragAlpha(void*, float);
void CEGUI__DragContainer_getRenderingContext_impl(void*, void*);

//
// Begin class 'CEGUI::DragDropEventArgs'
//
void* CEGUI__DragDropEventArgs__Create(void*);
void CEGUI__DragDropEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::TextComponent'
//
void CEGUI__TextComponent__Destroy(void*);
void* CEGUI__TextComponent_getTextPropertySource(void*);
unsigned int CEGUI__TextComponent_getVerticalFormatting(void*);
void* CEGUI__TextComponent_getFont(void*);
bool CEGUI__TextComponent_isFontFetchedFromProperty(void*);
void CEGUI__TextComponent_setText(void*, void*);
void CEGUI__TextComponent_setTextPropertySource(void*, void*);
void* CEGUI__TextComponent_getText(void*);
void* CEGUI__TextComponent_getTextVisual(void*);
void CEGUI__TextComponent_setFontPropertySource(void*, void*);
void* CEGUI__TextComponent_getFontPropertySource(void*);
void CEGUI__TextComponent_setVerticalFormatting(void*, unsigned int);
void CEGUI__TextComponent_writeXMLToStream(void*, void*);
void CEGUI__TextComponent_setFont(void*, void*);
bool CEGUI__TextComponent_isTextFetchedFromProperty(void*);
unsigned int CEGUI__TextComponent_getHorizontalFormatting(void*);
void CEGUI__TextComponent_setHorizontalFormatting(void*, unsigned int);

//
// Begin class 'CEGUI::LayerSpecification'
//
void* CEGUI__LayerSpecification__Create(unsigned int);
void CEGUI__LayerSpecification__Destroy(void*);
void CEGUI__LayerSpecification_clearSectionSpecifications(void*);
void CEGUI__LayerSpecification_addSectionSpecification(void*, void*);
void CEGUI__LayerSpecification_writeXMLToStream(void*, void*);
void CEGUI__LayerSpecification_render0(void*, void*, void*, void*, bool);
void CEGUI__LayerSpecification_render1(void*, void*, void*, void*, void*, bool);
unsigned int CEGUI__LayerSpecification_getLayerPriority(void*);

//
// Begin class 'CEGUI::GroupBox'
//
void* CEGUI__GroupBox__Create(void*, void*);
void CEGUI__GroupBox__Destroy(void*);
bool CEGUI__GroupBox_drawAroundWidget0(void*, void*);
bool CEGUI__GroupBox_drawAroundWidget1(void*, void*);
void* CEGUI__GroupBox_getContentPane(void*);
bool CEGUI__GroupBox_testClassName_impl(void*, void*);

//
// Begin class 'CEGUI::PropertySet'
//
void* CEGUI__PropertySet__Create();
void CEGUI__PropertySet__Destroy(void*);
bool CEGUI__PropertySet_isPropertyPresent(void*, void*);
void CEGUI__PropertySet_clearProperties(void*);
void* CEGUI__PropertySet_getProperty(void*, void*);
void CEGUI__PropertySet_addProperty(void*, void*);
bool CEGUI__PropertySet_isPropertyDefault(void*, void*);
void* CEGUI__PropertySet_getPropertyHelp(void*, void*);
void* CEGUI__PropertySet_getPropertyDefault(void*, void*);
void CEGUI__PropertySet_removeProperty(void*, void*);
void CEGUI__PropertySet_setProperty(void*, void*, void*);

//
// Begin class 'CEGUI::PropertyDefinitionBase'
//
void CEGUI__PropertyDefinitionBase__Destroy(void*);
void CEGUI__PropertyDefinitionBase_set(void*, void*, void*);
void CEGUI__PropertyDefinitionBase_writeXMLToStream(void*, void*);

//
// Begin class 'CEGUI::UVector2Interpolator'
//
void CEGUI__UVector2Interpolator__Destroy(void*);
void* CEGUI__UVector2Interpolator_getType(void*);
void* CEGUI__UVector2Interpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__UVector2Interpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__UVector2Interpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::ImageDim'
//
void CEGUI__ImageDim__Destroy(void*);
void CEGUI__ImageDim_setSourceDimension(void*, unsigned int);
void CEGUI__ImageDim_setSourceImage(void*, void*, void*);

//
// Begin class 'CEGUI::WindowManager'
//
void* CEGUI__WindowManager__Create();
void CEGUI__WindowManager__Destroy(void*);
bool CEGUI__WindowManager_isWindowPresent(void*, void*);
void* CEGUI__WindowManager_createWindow(void*, void*, void*);
void CEGUI__WindowManager_saveWindowLayout0(void*, void*, void*, bool);
void CEGUI__WindowManager_saveWindowLayout1(void*, void*, void*, bool);
void CEGUI__WindowManager_cleanDeadPool(void*);
bool CEGUI__WindowManager_isLocked(void*);
void CEGUI__WindowManager_lock(void*);
void CEGUI__WindowManager_setDefaultResourceGroup(void*, void*);
void CEGUI__WindowManager_renameWindow0(void*, void*, void*);
void CEGUI__WindowManager_renameWindow1(void*, void*, void*);
void* CEGUI__WindowManager_getDefaultResourceGroup(void*);
bool CEGUI__WindowManager_isDeadPoolEmpty(void*);
void CEGUI__WindowManager_unlock(void*);
void CEGUI__WindowManager_destroyAllWindows(void*);
void* CEGUI__WindowManager_getWindow(void*, void*);
void CEGUI__WindowManager_DEBUG_dumpWindowNames(void*, void*);
void CEGUI__WindowManager_destroyWindow0(void*, void*);
void CEGUI__WindowManager_destroyWindow1(void*, void*);

//
// Begin class 'CEGUI::XMLHandler'
//
void* CEGUI__XMLHandler__Create();
void CEGUI__XMLHandler__Destroy(void*);
void CEGUI__XMLHandler_elementStart(void*, void*, void*);
void CEGUI__XMLHandler_text(void*, void*);
void CEGUI__XMLHandler_elementEnd(void*, void*);

//
// Begin class 'CEGUI::String::const_iterator'
//
void* CEGUI__String__const_iterator__Create0();
void* CEGUI__String__const_iterator__Create1(unsigned int*);
void* CEGUI__String__const_iterator__Create2(void*);
void* CEGUI__String__const_iterator__Create3(void*);
void CEGUI__String__const_iterator__Destroy(void*);

//
// Begin class 'CEGUI::String::iterator'
//
void* CEGUI__String__iterator__Create0();
void* CEGUI__String__iterator__Create1(unsigned int*);
void* CEGUI__String__iterator__Create2(void*);
void CEGUI__String__iterator__Destroy(void*);

//
// Begin class 'CEGUI::ListHeaderSegment'
//
void* CEGUI__ListHeaderSegment__Create(void*, void*);
void CEGUI__ListHeaderSegment__Destroy(void*);
unsigned int CEGUI__ListHeaderSegment_getSortDirection(void*);
void* CEGUI__ListHeaderSegment_getMovingCursorImage(void*);
bool CEGUI__ListHeaderSegment_isSegmentHovering(void*);
void* CEGUI__ListHeaderSegment_getSizingCursorImage(void*);
void CEGUI__ListHeaderSegment_setSortDirection(void*, unsigned int);
void CEGUI__ListHeaderSegment_setDragMovingEnabled(void*, bool);
void CEGUI__ListHeaderSegment_setClickable(void*, bool);
void CEGUI__ListHeaderSegment_setMovingCursorImage0(void*, void*);
void CEGUI__ListHeaderSegment_setMovingCursorImage1(void*, void*, void*);
bool CEGUI__ListHeaderSegment_isSegmentPushed(void*);
bool CEGUI__ListHeaderSegment_isClickable(void*);
bool CEGUI__ListHeaderSegment_isSizingEnabled(void*);
void CEGUI__ListHeaderSegment_setSizingEnabled(void*, bool);
bool CEGUI__ListHeaderSegment_isDragMovingEnabled(void*);
void* CEGUI__ListHeaderSegment_getDragMoveOffset(void*);
void CEGUI__ListHeaderSegment_setSizingCursorImage0(void*, void*);
void CEGUI__ListHeaderSegment_setSizingCursorImage1(void*, void*, void*);
bool CEGUI__ListHeaderSegment_isBeingDragSized(void*);
bool CEGUI__ListHeaderSegment_isBeingDragMoved(void*);
bool CEGUI__ListHeaderSegment_isSplitterHovering(void*);

//
// Begin class 'CEGUI::XMLSerializer'
//
void CEGUI__XMLSerializer__Destroy(void*);
void* CEGUI__XMLSerializer_attribute(void*, void*, void*);
void* CEGUI__XMLSerializer_closeTag(void*);
unsigned int CEGUI__XMLSerializer_getTagCount(void*);
void* CEGUI__XMLSerializer_text(void*, void*);
void* CEGUI__XMLSerializer_openTag(void*, void*);

//
// Begin class 'CEGUI::BaseDim'
//
void CEGUI__BaseDim__Destroy(void*);
void* CEGUI__BaseDim_clone(void*);
float CEGUI__BaseDim_getValue0(void*, void*);
float CEGUI__BaseDim_getValue1(void*, void*, void*);
void CEGUI__BaseDim_setDimensionOperator(void*, unsigned int);
void* CEGUI__BaseDim_getOperand(void*);
unsigned int CEGUI__BaseDim_getDimensionOperator(void*);
void CEGUI__BaseDim_setOperand(void*, void*);
void CEGUI__BaseDim_writeXMLToStream(void*, void*);

//
// Begin class 'CEGUI::UDimInterpolator'
//
void CEGUI__UDimInterpolator__Destroy(void*);
void* CEGUI__UDimInterpolator_getType(void*);
void* CEGUI__UDimInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__UDimInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__UDimInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::TabControlWindowRenderer'
//
void CEGUI__TabControlWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::TabControl'
//
void* CEGUI__TabControl__Create(void*, void*);
void CEGUI__TabControl__Destroy(void*);
void* CEGUI__TabControl_getTabContents0(void*, void*);
void* CEGUI__TabControl_getTabContents1(void*, unsigned int);
void CEGUI__TabControl_setSelectedTab0(void*, void*);
void CEGUI__TabControl_setSelectedTab1(void*, unsigned int);
void CEGUI__TabControl_initialiseComponents(void*);
void* CEGUI__TabControl_getTabHeight(void*);
unsigned int CEGUI__TabControl_getTabCount(void*);
void CEGUI__TabControl_makeTabVisible0(void*, void*);
void CEGUI__TabControl_makeTabVisible1(void*, unsigned int);
void CEGUI__TabControl_setSelectedTabAtIndex(void*, unsigned int);
void CEGUI__TabControl_makeTabVisibleAtIndex(void*, unsigned int);
void CEGUI__TabControl_setTabTextPadding(void*, void*);
void CEGUI__TabControl_removeTab0(void*, void*);
void CEGUI__TabControl_removeTab1(void*, unsigned int);
bool CEGUI__TabControl_isTabContentsSelected(void*, void*);
void* CEGUI__TabControl_getTabContentsAtIndex(void*, unsigned int);
unsigned int CEGUI__TabControl_getTabPanePosition(void*);
unsigned int CEGUI__TabControl_getSelectedTabIndex(void*);
void CEGUI__TabControl_setTabHeight(void*, void*);
void CEGUI__TabControl_setTabPanePosition(void*, unsigned int);
void* CEGUI__TabControl_getTabTextPadding(void*);
void CEGUI__TabControl_addTab(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListWindowRenderer'
//
void CEGUI__MultiColumnListWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::SizeInterpolator'
//
void CEGUI__SizeInterpolator__Destroy(void*);
void* CEGUI__SizeInterpolator_getType(void*);
void* CEGUI__SizeInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__SizeInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__SizeInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::PointInterpolator'
//
void CEGUI__PointInterpolator__Destroy(void*);
void* CEGUI__PointInterpolator_getType(void*);
void* CEGUI__PointInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__PointInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__PointInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::Image'
//
void* CEGUI__Image__Create0();
void* CEGUI__Image__Create1(void*, void*, void*, void*, float, float);
void* CEGUI__Image__Create2(void*);
void CEGUI__Image__Destroy(void*);
float CEGUI__Image_getWidth(void*);
void CEGUI__Image_draw0(void*, void*, void*, void*, void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Image_draw1(void*, void*, void*, void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Image_draw2(void*, void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Image_draw3(void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Image_draw4(void*, void*, void*, void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Image_draw5(void*, void*, void*, void*, void*, unsigned int);
void* CEGUI__Image_getName(void*);
void* CEGUI__Image_getImagesetName(void*);
float CEGUI__Image_getHeight(void*);
void* CEGUI__Image_getImageset(void*);
void* CEGUI__Image_getSize(void*);
float CEGUI__Image_getOffsetY(void*);
float CEGUI__Image_getOffsetX(void*);
void CEGUI__Image_writeXMLToStream(void*, void*);
void* CEGUI__Image_getOffsets(void*);
void* CEGUI__Image_getSourceTextureArea(void*);

//
// Begin class 'CEGUI::JustifiedRenderedString'
//
void CEGUI__JustifiedRenderedString__Destroy(void*);
void CEGUI__JustifiedRenderedString_draw(void*, void*, void*, void*, void*);
float CEGUI__JustifiedRenderedString_getHorizontalExtent(void*);
float CEGUI__JustifiedRenderedString_getVerticalExtent(void*);
unsigned int CEGUI__JustifiedRenderedString_getFormattedLineCount(void*);
void CEGUI__JustifiedRenderedString_format(void*, void*);

//
// Begin class 'CEGUI::SubscriberSlot'
//
void* CEGUI__SubscriberSlot__Create0();
void CEGUI__SubscriberSlot__Destroy(void*);
void CEGUI__SubscriberSlot_cleanup(void*);
bool CEGUI__SubscriberSlot_connected(void*);

//
// Begin class 'CEGUI::FormattedRenderedString'
//
void CEGUI__FormattedRenderedString__Destroy(void*);
void* CEGUI__FormattedRenderedString_getRenderedString(void*);
void CEGUI__FormattedRenderedString_setRenderedString(void*, void*);

//
// Begin class 'CEGUI::Logger'
//
void CEGUI__Logger__Destroy(void*);
unsigned int CEGUI__Logger_getLoggingLevel(void*);
void CEGUI__Logger_setLoggingLevel(void*, unsigned int);

//
// Begin class 'CEGUI::SectionSpecification'
//
void* CEGUI__SectionSpecification__Create0(void*, void*, void*, void*, void*);
void* CEGUI__SectionSpecification__Create1(void*, void*, void*, void*, void*, void*);
void CEGUI__SectionSpecification__Destroy(void*);
void CEGUI__SectionSpecification_setOverrideColoursPropertyIsColourRect(void*, bool);
void CEGUI__SectionSpecification_setRenderControlPropertySource(void*, void*);
void* CEGUI__SectionSpecification_getOwnerWidgetLookFeel(void*);
void CEGUI__SectionSpecification_render0(void*, void*, void*, void*, bool);
void CEGUI__SectionSpecification_render1(void*, void*, void*, void*, void*, bool);
void CEGUI__SectionSpecification_setRenderControlValue(void*, void*);
bool CEGUI__SectionSpecification_isUsingOverrideColours(void*);
void* CEGUI__SectionSpecification_getSectionName(void*);
void CEGUI__SectionSpecification_setRenderControlWidget(void*, void*);
void CEGUI__SectionSpecification_setUsingOverrideColours(void*, bool);
void CEGUI__SectionSpecification_setOverrideColours(void*, void*);
void CEGUI__SectionSpecification_writeXMLToStream(void*, void*);
void* CEGUI__SectionSpecification_getOverrideColours(void*);
void CEGUI__SectionSpecification_setOverrideColoursPropertySource(void*, void*);

//
// Begin class 'CEGUI::PropertyInitialiser'
//
void* CEGUI__PropertyInitialiser__Create(void*, void*);
void CEGUI__PropertyInitialiser__Destroy(void*);
void CEGUI__PropertyInitialiser_apply(void*, void*);
void CEGUI__PropertyInitialiser_writeXMLToStream(void*, void*);
void* CEGUI__PropertyInitialiser_getTargetPropertyName(void*);
void* CEGUI__PropertyInitialiser_getInitialiserValue(void*);

//
// Begin class 'CEGUI::PushButton'
//
void* CEGUI__PushButton__Create(void*, void*);
void CEGUI__PushButton__Destroy(void*);

//
// Begin class 'CEGUI::ScrollablePaneWindowRenderer'
//
void CEGUI__ScrollablePaneWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::Checkbox'
//
void* CEGUI__Checkbox__Create(void*, void*);
void CEGUI__Checkbox__Destroy(void*);
void CEGUI__Checkbox_setSelected(void*, bool);
bool CEGUI__Checkbox_isSelected(void*);

//
// Begin class 'CEGUI::WindowFactoryManager::FalagardWindowMapping'
//
void CEGUI__WindowFactoryManager__FalagardWindowMapping__Destroy(void*);

//
// Begin class 'CEGUI::ClippedContainer'
//
void* CEGUI__ClippedContainer__Create(void*, void*);
void CEGUI__ClippedContainer__Destroy(void*);
void* CEGUI__ClippedContainer_getClipperWindow(void*);
void* CEGUI__ClippedContainer_getUnclippedInnerRect_impl(void*);
void CEGUI__ClippedContainer_setClipArea(void*, void*);
void* CEGUI__ClippedContainer_getClipArea(void*);
void CEGUI__ClippedContainer_setClipperWindow(void*, void*);

//
// Begin class 'CEGUI::ScriptModule'
//
void CEGUI__ScriptModule__Destroy(void*);
void CEGUI__ScriptModule_createBindings(void*);
void CEGUI__ScriptModule_setDefaultResourceGroup(void*, void*);
void* CEGUI__ScriptModule_getDefaultResourceGroup(void*);
void CEGUI__ScriptModule_destroyBindings(void*);
void* CEGUI__ScriptModule_getIdentifierString(void*);

//
// Begin class 'CEGUI::URectInterpolator'
//
void CEGUI__URectInterpolator__Destroy(void*);
void* CEGUI__URectInterpolator_getType(void*);
void* CEGUI__URectInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__URectInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__URectInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::ScrollbarWindowRenderer'
//
void CEGUI__ScrollbarWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::RightAlignedRenderedString'
//
void CEGUI__RightAlignedRenderedString__Destroy(void*);
void CEGUI__RightAlignedRenderedString_draw(void*, void*, void*, void*, void*);
float CEGUI__RightAlignedRenderedString_getHorizontalExtent(void*);
float CEGUI__RightAlignedRenderedString_getVerticalExtent(void*);
unsigned int CEGUI__RightAlignedRenderedString_getFormattedLineCount(void*);
void CEGUI__RightAlignedRenderedString_format(void*, void*);

//
// Begin class 'CEGUI::DefaultLogger'
//
void CEGUI__DefaultLogger__Destroy(void*);
void CEGUI__DefaultLogger_logEvent(void*, void*, unsigned int);
void CEGUI__DefaultLogger_setLogFilename(void*, void*, bool);

//
// Begin class 'CEGUI::WRFactoryRegisterer'
//
void CEGUI__WRFactoryRegisterer__Destroy(void*);
void CEGUI__WRFactoryRegisterer_unregisterFactory(void*);
void CEGUI__WRFactoryRegisterer_registerFactory(void*);

//
// Begin class 'CEGUI::Imageset'
//
void* CEGUI__Imageset__Create0(void*, void*);
void* CEGUI__Imageset__Create1(void*, void*, void*);
void CEGUI__Imageset__Destroy(void*);
void* CEGUI__Imageset_getTexture(void*);
void CEGUI__Imageset_undefineImage(void*, void*);
void CEGUI__Imageset_defineImage0(void*, void*, void*, void*, void*);
void CEGUI__Imageset_defineImage1(void*, void*, void*, void*);
void* CEGUI__Imageset_getImageOffset(void*, void*);
void* CEGUI__Imageset_getName(void*);
void* CEGUI__Imageset_getNativeResolution(void*);
void CEGUI__Imageset_writeXMLToStream(void*, void*);
float CEGUI__Imageset_getImageHeight(void*, void*);
float CEGUI__Imageset_getImageWidth(void*, void*);
void CEGUI__Imageset_draw0(void*, void*, void*, void*, void*, void*, unsigned int);
void CEGUI__Imageset_draw1(void*, void*, void*, void*, void*, void*, void*, void*, void*, unsigned int);
void* CEGUI__Imageset_getDefaultResourceGroup(void*);
bool CEGUI__Imageset_isImageDefined(void*, void*);
void CEGUI__Imageset_setAutoScalingEnabled(void*, bool);
float CEGUI__Imageset_getImageOffsetY(void*, void*);
float CEGUI__Imageset_getImageOffsetX(void*, void*);
void CEGUI__Imageset_undefineAllImages(void*);
void CEGUI__Imageset_notifyDisplaySizeChanged(void*, void*);
bool CEGUI__Imageset_isAutoScaled(void*);
void CEGUI__Imageset_setDefaultResourceGroup(void*, void*);
void* CEGUI__Imageset_getImageSize(void*, void*);
void CEGUI__Imageset_setNativeResolution(void*, void*);
void* CEGUI__Imageset_getImage(void*, void*);
unsigned int CEGUI__Imageset_getImageCount(void*);

//
// Begin class 'CEGUI::Vector3'
//
void* CEGUI__Vector3__Create0();
void* CEGUI__Vector3__Create1(float, float, float);
void* CEGUI__Vector3__Create2(void*);
void CEGUI__Vector3__Destroy(void*);

//
// Begin class 'CEGUI::ColourRectInterpolator'
//
void CEGUI__ColourRectInterpolator__Destroy(void*);
void* CEGUI__ColourRectInterpolator_getType(void*);
void* CEGUI__ColourRectInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__ColourRectInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__ColourRectInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::RenderingContext'
//
void CEGUI__RenderingContext__Destroy(void*);

//
// Begin class 'CEGUI::ImageCodec'
//
void CEGUI__ImageCodec__Destroy(void*);
void* CEGUI__ImageCodec_getSupportedFormat(void*);
void* CEGUI__ImageCodec_getIdentifierString(void*);

//
// Begin class 'CEGUI::Combobox'
//
void* CEGUI__Combobox__Create(void*, void*);
void CEGUI__Combobox__Destroy(void*);
void CEGUI__Combobox_initialiseComponents(void*);
void CEGUI__Combobox_setItemSelectState0(void*, void*, bool);
void CEGUI__Combobox_setItemSelectState1(void*, unsigned int, bool);
void* CEGUI__Combobox_getSelectedItem(void*);
void CEGUI__Combobox_hideDropList(void*);
void CEGUI__Combobox_clearAllSelections(void*);
bool CEGUI__Combobox_isItemSelected(void*, unsigned int);
void CEGUI__Combobox_insertItem(void*, void*, void*);
unsigned int CEGUI__Combobox_getSelectionStartIndex(void*);
bool CEGUI__Combobox_isHorzScrollbarAlwaysShown(void*);
void CEGUI__Combobox_removeItem(void*, void*);
void* CEGUI__Combobox_getListboxItemFromIndex(void*, unsigned int);
unsigned int CEGUI__Combobox_getSelectionEndIndex(void*);
void CEGUI__Combobox_setValidationString(void*, void*);
void CEGUI__Combobox_setSingleClickEnabled(void*, bool);
void CEGUI__Combobox_resetList(void*);
bool CEGUI__Combobox_hasInputFocus(void*);
bool CEGUI__Combobox_isSortEnabled(void*);
void CEGUI__Combobox_addItem(void*, void*);
unsigned int CEGUI__Combobox_getCaratIndex(void*);
void CEGUI__Combobox_setMaxTextLength(void*, unsigned int);
void CEGUI__Combobox_setShowVertScrollbar(void*, bool);
bool CEGUI__Combobox_isHit(void*, void*, bool);
unsigned int CEGUI__Combobox_getItemCount(void*);
void CEGUI__Combobox_setShowHorzScrollbar(void*, bool);
bool CEGUI__Combobox_isReadOnly(void*);
void* CEGUI__Combobox_getPushButton(void*);
void CEGUI__Combobox_handleUpdatedListItemData(void*);
bool CEGUI__Combobox_isDropDownListVisible(void*);
void CEGUI__Combobox_setCaratIndex(void*, unsigned int);
void CEGUI__Combobox_setSortingEnabled(void*, bool);
unsigned int CEGUI__Combobox_getItemIndex(void*, void*);
unsigned int CEGUI__Combobox_getSelectionLength(void*);
void* CEGUI__Combobox_getEditbox(void*);
bool CEGUI__Combobox_isTextValid(void*);
void* CEGUI__Combobox_getDropList(void*);
void CEGUI__Combobox_showDropList(void*);
bool CEGUI__Combobox_getSingleClickEnabled(void*);
void* CEGUI__Combobox_getValidationString(void*);
unsigned int CEGUI__Combobox_getMaxTextLength(void*);
void* CEGUI__Combobox_findItemWithText(void*, void*, void*);
bool CEGUI__Combobox_isVertScrollbarAlwaysShown(void*);
void CEGUI__Combobox_activateEditbox(void*);
bool CEGUI__Combobox_isListboxItemInList(void*, void*);
void CEGUI__Combobox_setSelection(void*, unsigned int, unsigned int);
void CEGUI__Combobox_setReadOnly(void*, bool);

//
// Begin class 'CEGUI::ListboxTextItem'
//
void CEGUI__ListboxTextItem__Destroy(void*);
void CEGUI__ListboxTextItem_draw(void*, void*, void*, float, void*);
void* CEGUI__ListboxTextItem_getFont(void*);
void CEGUI__ListboxTextItem_setText(void*, void*);
void* CEGUI__ListboxTextItem_getPixelSize(void*);
bool CEGUI__ListboxTextItem_isTextParsingEnabled(void*);
void* CEGUI__ListboxTextItem_getTextColours(void*);
void CEGUI__ListboxTextItem_setTextParsingEnabled(void*, bool);
void CEGUI__ListboxTextItem_setFont0(void*, void*);
void CEGUI__ListboxTextItem_setFont1(void*, void*);
void CEGUI__ListboxTextItem_setTextColours0(void*, void*);
void CEGUI__ListboxTextItem_setTextColours1(void*, void*, void*, void*, void*);
void CEGUI__ListboxTextItem_setTextColours2(void*, void*);

//
// Begin class 'CEGUI::StateImagery'
//
void* CEGUI__StateImagery__Create0();
void* CEGUI__StateImagery__Create1(void*);
void CEGUI__StateImagery__Destroy(void*);
void CEGUI__StateImagery_render0(void*, void*, void*, void*);
void CEGUI__StateImagery_render1(void*, void*, void*, void*, void*);
void CEGUI__StateImagery_setClippedToDisplay(void*, bool);
void* CEGUI__StateImagery_getName(void*);
bool CEGUI__StateImagery_isClippedToDisplay(void*);
void CEGUI__StateImagery_clearLayers(void*);
void CEGUI__StateImagery_writeXMLToStream(void*, void*);
void CEGUI__StateImagery_addLayer(void*, void*);

//
// Begin class 'CEGUI::KeyEventArgs'
//
void* CEGUI__KeyEventArgs__Create(void*);
void CEGUI__KeyEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::RenderingRoot'
//
void* CEGUI__RenderingRoot__Create(void*);
void CEGUI__RenderingRoot__Destroy(void*);

//
// Begin class 'CEGUI::UBox'
//
void* CEGUI__UBox__Create0();
void* CEGUI__UBox__Create1(void*);
void* CEGUI__UBox__Create2(void*, void*, void*, void*);
void* CEGUI__UBox__Create3(void*);
void CEGUI__UBox__Destroy(void*);

//
// Begin class 'CEGUI::HeaderSequenceEventArgs'
//
void* CEGUI__HeaderSequenceEventArgs__Create(void*, unsigned int, unsigned int);
void CEGUI__HeaderSequenceEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::SequentialLayoutContainer'
//
void CEGUI__SequentialLayoutContainer__Destroy(void*);
void CEGUI__SequentialLayoutContainer_swapChildWindows0(void*, void*, void*);
void CEGUI__SequentialLayoutContainer_swapChildWindows1(void*, void*, void*);
void CEGUI__SequentialLayoutContainer_swapChildWindows2(void*, void*, void*);
void CEGUI__SequentialLayoutContainer_swapChildWindows3(void*, void*, void*);
void CEGUI__SequentialLayoutContainer_moveChildWindow(void*, void*, int);
unsigned int CEGUI__SequentialLayoutContainer_getPositionOfChildWindow0(void*, void*);
unsigned int CEGUI__SequentialLayoutContainer_getPositionOfChildWindow1(void*, void*);
void* CEGUI__SequentialLayoutContainer_getChildWindowAtPosition(void*, unsigned int);
void CEGUI__SequentialLayoutContainer_swapChildWindowPositions(void*, unsigned int, unsigned int);
void CEGUI__SequentialLayoutContainer_moveChildWindowToPosition0(void*, void*, unsigned int);
void CEGUI__SequentialLayoutContainer_moveChildWindowToPosition1(void*, void*, unsigned int);
void CEGUI__SequentialLayoutContainer_removeChildWindowFromPosition(void*, unsigned int);
void CEGUI__SequentialLayoutContainer_addChildWindowToPosition0(void*, void*, unsigned int);
void CEGUI__SequentialLayoutContainer_addChildWindowToPosition1(void*, void*, unsigned int);

//
// Begin class 'CEGUI::RawDataContainer'
//
void* CEGUI__RawDataContainer__Create();
void CEGUI__RawDataContainer__Destroy(void*);
unsigned char* CEGUI__RawDataContainer_getDataPtr0(void*);
unsigned char* CEGUI__RawDataContainer_getDataPtr1(void*);
unsigned int CEGUI__RawDataContainer_getSize(void*);
void CEGUI__RawDataContainer_setSize(void*, unsigned int);
void CEGUI__RawDataContainer_release(void*);
void CEGUI__RawDataContainer_setData(void*, unsigned char*);

//
// Begin class 'CEGUI::ItemListBase'
//
void CEGUI__ItemListBase__Destroy(void*);
bool CEGUI__ItemListBase_isAutoResizeEnabled(void*);
void CEGUI__ItemListBase_initialiseComponents(void*);
void CEGUI__ItemListBase_setSortMode(void*, unsigned int);
unsigned int CEGUI__ItemListBase_getItemCount(void*);
bool CEGUI__ItemListBase_isItemInList(void*, void*);
void CEGUI__ItemListBase_resetList(void*);
bool CEGUI__ItemListBase_isSortEnabled(void*);
void* CEGUI__ItemListBase_getContentPane(void*);
void* CEGUI__ItemListBase_findItemWithText(void*, void*, void*);
void CEGUI__ItemListBase_endInitialisation(void*);
void CEGUI__ItemListBase_setAutoResizeEnabled(void*, bool);
void CEGUI__ItemListBase_sizeToContent(void*);
void CEGUI__ItemListBase_performChildWindowLayout(void*);
void* CEGUI__ItemListBase_getItemFromIndex(void*, unsigned int);
void CEGUI__ItemListBase_insertItem(void*, void*, void*);
void CEGUI__ItemListBase_addItem(void*, void*);
void CEGUI__ItemListBase_removeItem(void*, void*);
void* CEGUI__ItemListBase_getItemRenderArea(void*);
void CEGUI__ItemListBase_notifyItemSelectState(void*, void*, bool);
unsigned int CEGUI__ItemListBase_getSortMode(void*);
void CEGUI__ItemListBase_sortList(void*, bool);
void CEGUI__ItemListBase_setSortEnabled(void*, bool);
void CEGUI__ItemListBase_handleUpdatedItemData(void*, bool);
unsigned int CEGUI__ItemListBase_getItemIndex(void*, void*);
void CEGUI__ItemListBase_notifyItemClicked(void*, void*);

//
// Begin class 'CEGUI::Scrollbar'
//
void* CEGUI__Scrollbar__Create(void*, void*);
void CEGUI__Scrollbar__Destroy(void*);
bool CEGUI__Scrollbar_isEndLockEnabled(void*);
void CEGUI__Scrollbar_setOverlapSize(void*, float);
void CEGUI__Scrollbar_initialiseComponents(void*);
void CEGUI__Scrollbar_setScrollPosition(void*, float);
void CEGUI__Scrollbar_setPageSize(void*, float);
void* CEGUI__Scrollbar_getIncreaseButton(void*);
float CEGUI__Scrollbar_getScrollPosition(void*);
float CEGUI__Scrollbar_getStepSize(void*);
float CEGUI__Scrollbar_getPageSize(void*);
float CEGUI__Scrollbar_getOverlapSize(void*);
void CEGUI__Scrollbar_setStepSize(void*, float);
void CEGUI__Scrollbar_setDocumentSize(void*, float);
void* CEGUI__Scrollbar_getThumb(void*);
float CEGUI__Scrollbar_getDocumentSize(void*);
void CEGUI__Scrollbar_setEndLockEnabled(void*, bool);
void CEGUI__Scrollbar_setConfig(void*, float*, float*, float*, float*, float*);
void* CEGUI__Scrollbar_getDecreaseButton(void*);

//
// Begin class 'CEGUI::Size'
//
void* CEGUI__Size__Create0();
void* CEGUI__Size__Create1(float, float);
void* CEGUI__Size__Create2(void*);
void CEGUI__Size__Destroy(void*);

//
// Begin class 'CEGUI::UBoxInterpolator'
//
void CEGUI__UBoxInterpolator__Destroy(void*);
void* CEGUI__UBoxInterpolator_getType(void*);
void* CEGUI__UBoxInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__UBoxInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__UBoxInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::PropertyDim'
//
void CEGUI__PropertyDim__Destroy(void*);

//
// Begin class 'CEGUI::SlotFunctorBase'
//
void CEGUI__SlotFunctorBase__Destroy(void*);

//
// Begin class 'CEGUI::ScrollablePane'
//
void* CEGUI__ScrollablePane__Create(void*, void*);
void CEGUI__ScrollablePane__Destroy(void*);
void* CEGUI__ScrollablePane_getHorzScrollbar(void*);
void CEGUI__ScrollablePane_setVerticalScrollPosition(void*, float);
bool CEGUI__ScrollablePane_isContentPaneAutoSized(void*);
void CEGUI__ScrollablePane_initialiseComponents(void*);
float CEGUI__ScrollablePane_getHorizontalOverlapSize(void*);
void CEGUI__ScrollablePane_setHorizontalOverlapSize(void*, float);
float CEGUI__ScrollablePane_getVerticalStepSize(void*);
void CEGUI__ScrollablePane_setVerticalStepSize(void*, float);
void CEGUI__ScrollablePane_setShowHorzScrollbar(void*, bool);
void* CEGUI__ScrollablePane_getContentPane(void*);
float CEGUI__ScrollablePane_getHorizontalScrollPosition(void*);
void CEGUI__ScrollablePane_destroy(void*);
void CEGUI__ScrollablePane_setHorizontalStepSize(void*, float);
float CEGUI__ScrollablePane_getVerticalOverlapSize(void*);
void CEGUI__ScrollablePane_setVerticalOverlapSize(void*, float);
bool CEGUI__ScrollablePane_isVertScrollbarAlwaysShown(void*);
void CEGUI__ScrollablePane_setHorizontalScrollPosition(void*, float);
void* CEGUI__ScrollablePane_getContentPaneArea(void*);
bool CEGUI__ScrollablePane_isHorzScrollbarAlwaysShown(void*);
float CEGUI__ScrollablePane_getHorizontalStepSize(void*);
void* CEGUI__ScrollablePane_getViewableArea(void*);
float CEGUI__ScrollablePane_getVerticalScrollPosition(void*);
void CEGUI__ScrollablePane_setContentPaneAutoSized(void*, bool);
void CEGUI__ScrollablePane_setContentPaneArea(void*, void*);
void CEGUI__ScrollablePane_setShowVertScrollbar(void*, bool);
void* CEGUI__ScrollablePane_getVertScrollbar(void*);

//
// Begin class 'CEGUI::ItemListBaseWindowRenderer'
//
void CEGUI__ItemListBaseWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::Scheme_xmlHandler'
//
void* CEGUI__Scheme_xmlHandler__Create(void*, void*);
void CEGUI__Scheme_xmlHandler__Destroy(void*);
void CEGUI__Scheme_xmlHandler_elementStart(void*, void*, void*);
void CEGUI__Scheme_xmlHandler_elementEnd(void*, void*);
void* CEGUI__Scheme_xmlHandler_getObject(void*);
void* CEGUI__Scheme_xmlHandler_getObjectName(void*);

//
// Begin class 'CEGUI::ColourInterpolator'
//
void CEGUI__ColourInterpolator__Destroy(void*);
void* CEGUI__ColourInterpolator_getType(void*);
void* CEGUI__ColourInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__ColourInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__ColourInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::FloatInterpolator'
//
void CEGUI__FloatInterpolator__Destroy(void*);
void* CEGUI__FloatInterpolator_getType(void*);
void* CEGUI__FloatInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__FloatInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__FloatInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::WindowEventArgs'
//
void* CEGUI__WindowEventArgs__Create0(void*);
void* CEGUI__WindowEventArgs__Create1(void*);
void CEGUI__WindowEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::ProgressBar'
//
void* CEGUI__ProgressBar__Create(void*, void*);
void CEGUI__ProgressBar__Destroy(void*);
void CEGUI__ProgressBar_setStepSize(void*, float);
float CEGUI__ProgressBar_getStep(void*);
void CEGUI__ProgressBar_step(void*);
float CEGUI__ProgressBar_getProgress(void*);
void CEGUI__ProgressBar_setProgress(void*, float);
void CEGUI__ProgressBar_adjustProgress(void*, float);

//
// Begin class 'CEGUI::RenderingWindow'
//
void* CEGUI__RenderingWindow__Create(void*, void*);
void CEGUI__RenderingWindow__Destroy(void*);
void CEGUI__RenderingWindow_invalidate(void*);
void CEGUI__RenderingWindow_unprojectPoint(void*, void*, void*);
void* CEGUI__RenderingWindow_getSize(void*);
void* CEGUI__RenderingWindow_getRotation(void*);
void CEGUI__RenderingWindow_realiseGeometry(void*);
void CEGUI__RenderingWindow_invalidateGeometry(void*);
void CEGUI__RenderingWindow_setRotation(void*, void*);
void* CEGUI__RenderingWindow_getTextureTarget0(void*);
void* CEGUI__RenderingWindow_getTextureTarget1(void*);
void CEGUI__RenderingWindow_setClippingRegion(void*, void*);
void CEGUI__RenderingWindow_draw(void*);
void CEGUI__RenderingWindow_setRenderEffect(void*, void*);
bool CEGUI__RenderingWindow_isRenderingWindow(void*);
void CEGUI__RenderingWindow_update(void*, float);
void* CEGUI__RenderingWindow_getPivot(void*);
void CEGUI__RenderingWindow_setPosition(void*, void*);
void* CEGUI__RenderingWindow_getPosition(void*);
void* CEGUI__RenderingWindow_getOwner0(void*);
void* CEGUI__RenderingWindow_getOwner1(void*);
void CEGUI__RenderingWindow_setPivot(void*, void*);
void* CEGUI__RenderingWindow_getRenderEffect(void*);
void CEGUI__RenderingWindow_setSize(void*, void*);

//
// Begin class 'CEGUI::WindowRendererModule'
//
void CEGUI__WindowRendererModule__Destroy(void*);
void CEGUI__WindowRendererModule_unregisterFactory(void*, void*);
void CEGUI__WindowRendererModule_registerFactory(void*, void*);
unsigned int CEGUI__WindowRendererModule_unregisterAllFactories(void*);
unsigned int CEGUI__WindowRendererModule_registerAllFactories(void*);

//
// Begin class 'CEGUI::GlobalEventSet'
//
void* CEGUI__GlobalEventSet__Create();
void CEGUI__GlobalEventSet__Destroy(void*);
void* CEGUI__GlobalEventSet_getSingleton(void*);
void* CEGUI__GlobalEventSet_getSingletonPtr(void*);
void CEGUI__GlobalEventSet_fireEvent(void*, void*, void*, void*);

//
// Begin class 'CEGUI::LeftAlignedRenderedString'
//
void CEGUI__LeftAlignedRenderedString__Destroy(void*);
void CEGUI__LeftAlignedRenderedString_draw(void*, void*, void*, void*, void*);
float CEGUI__LeftAlignedRenderedString_getHorizontalExtent(void*);
float CEGUI__LeftAlignedRenderedString_getVerticalExtent(void*);
unsigned int CEGUI__LeftAlignedRenderedString_getFormattedLineCount(void*);
void CEGUI__LeftAlignedRenderedString_format(void*, void*);

//
// Begin class 'CEGUI::Key'
//
void CEGUI__Key__Destroy(void*);

//
// Begin class 'CEGUI::BoundSlot'
//
void* CEGUI__BoundSlot__Create0(unsigned int, void*, void*);
void* CEGUI__BoundSlot__Create1(void*);
void CEGUI__BoundSlot__Destroy(void*);
void CEGUI__BoundSlot_disconnect(void*);
bool CEGUI__BoundSlot_connected(void*);

//
// Begin class 'CEGUI::XMLAttributes'
//
void* CEGUI__XMLAttributes__Create();
void CEGUI__XMLAttributes__Destroy(void*);
float CEGUI__XMLAttributes_getValueAsFloat(void*, void*, float);
bool CEGUI__XMLAttributes_exists(void*, void*);
void* CEGUI__XMLAttributes_getName(void*, unsigned int);
void CEGUI__XMLAttributes_remove(void*, void*);
void* CEGUI__XMLAttributes_getValue0(void*, unsigned int);
void* CEGUI__XMLAttributes_getValue1(void*, void*);
void* CEGUI__XMLAttributes_getValueAsString(void*, void*, void*);
void CEGUI__XMLAttributes_add(void*, void*, void*);
bool CEGUI__XMLAttributes_getValueAsBool(void*, void*, bool);
unsigned int CEGUI__XMLAttributes_getCount(void*);
int CEGUI__XMLAttributes_getValueAsInteger(void*, void*, int);

//
// Begin class 'CEGUI::WindowFactory'
//
void CEGUI__WindowFactory__Destroy(void*);
void* CEGUI__WindowFactory_getTypeName(void*);

//
// Begin class 'CEGUI::TextureTarget'
//
void CEGUI__TextureTarget__Destroy(void*);

//
// Begin class 'CEGUI::RenderEffectManager'
//
void* CEGUI__RenderEffectManager__Create();
void CEGUI__RenderEffectManager__Destroy(void*);
void CEGUI__RenderEffectManager_destroy(void*, void*);
void* CEGUI__RenderEffectManager_create(void*, void*);
bool CEGUI__RenderEffectManager_isEffectAvailable(void*, void*);
void CEGUI__RenderEffectManager_removeEffect(void*, void*);

//
// Begin class 'CEGUI::DisplayEventArgs'
//
void* CEGUI__DisplayEventArgs__Create(void*);
void CEGUI__DisplayEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::RadioButton'
//
void* CEGUI__RadioButton__Create(void*, void*);
void CEGUI__RadioButton__Destroy(void*);
void CEGUI__RadioButton_setSelected(void*, bool);
unsigned long CEGUI__RadioButton_getGroupID(void*);
void CEGUI__RadioButton_setGroupID(void*, unsigned long);
bool CEGUI__RadioButton_isSelected(void*);
void* CEGUI__RadioButton_getSelectedButtonInGroup(void*);

//
// Begin class 'CEGUI::RenderedString'
//
void* CEGUI__RenderedString__Create0();
void* CEGUI__RenderedString__Create1(void*);
void CEGUI__RenderedString__Destroy(void*);
void CEGUI__RenderedString_draw(void*, unsigned int, void*, void*, void*, void*, float);
unsigned int CEGUI__RenderedString_getLineCount(void*);
void CEGUI__RenderedString_clearComponents(void*);
void* CEGUI__RenderedString_getPixelSize(void*, unsigned int);
unsigned int CEGUI__RenderedString_getSpaceCount(void*, unsigned int);
void CEGUI__RenderedString_appendComponent(void*, void*);
void CEGUI__RenderedString_split(void*, unsigned int, float, void*);
void CEGUI__RenderedString_appendLineBreak(void*);
unsigned int CEGUI__RenderedString_getComponentCount(void*);

//
// Begin class 'CEGUI::Vector3Interpolator'
//
void CEGUI__Vector3Interpolator__Destroy(void*);
void* CEGUI__Vector3Interpolator_getType(void*);
void* CEGUI__Vector3Interpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__Vector3Interpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__Vector3Interpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::PropertyReceiver'
//
void* CEGUI__PropertyReceiver__Create();
void CEGUI__PropertyReceiver__Destroy(void*);

//
// Begin class 'CEGUI::GridLayoutContainer'
//
void CEGUI__GridLayoutContainer__Destroy(void*);
unsigned int CEGUI__GridLayoutContainer_getNextAutoPositioningIdx(void*);
unsigned int CEGUI__GridLayoutContainer_getGridWidth(void*);
void CEGUI__GridLayoutContainer_swapChildWindowPositions0(void*, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_swapChildWindowPositions1(void*, unsigned int, unsigned int, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_moveChildWindowToPosition0(void*, void*, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_moveChildWindowToPosition1(void*, void*, unsigned int, unsigned int);
unsigned int CEGUI__GridLayoutContainer_getAutoPositioning(void*);
void CEGUI__GridLayoutContainer_swapChildWindows0(void*, void*, void*);
void CEGUI__GridLayoutContainer_swapChildWindows1(void*, void*, void*);
void CEGUI__GridLayoutContainer_swapChildWindows2(void*, void*, void*);
void CEGUI__GridLayoutContainer_layout(void*);
void CEGUI__GridLayoutContainer_setNextAutoPositioningIdx(void*, unsigned int);
void CEGUI__GridLayoutContainer_setAutoPositioning(void*, unsigned int);
void* CEGUI__GridLayoutContainer_getChildWindowAtPosition(void*, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_removeChildWindowFromPosition(void*, unsigned int, unsigned int);
unsigned int CEGUI__GridLayoutContainer_getGridHeight(void*);
void CEGUI__GridLayoutContainer_addChildWindowToPosition0(void*, void*, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_addChildWindowToPosition1(void*, void*, unsigned int, unsigned int);
void CEGUI__GridLayoutContainer_autoPositioningSkipCells(void*, unsigned int);
void CEGUI__GridLayoutContainer_setGridDimensions(void*, unsigned int, unsigned int);

//
// Begin class 'CEGUI::MenuItem'
//
void* CEGUI__MenuItem__Create(void*, void*);
void CEGUI__MenuItem__Destroy(void*);
bool CEGUI__MenuItem_isOpened(void*);
bool CEGUI__MenuItem_isPushed(void*);
bool CEGUI__MenuItem_isHovering(void*);
void CEGUI__MenuItem_setPopupMenu(void*, void*);
void* CEGUI__MenuItem_getPopupMenu(void*);
void CEGUI__MenuItem_openPopupMenu(void*, bool);
void CEGUI__MenuItem_closePopupMenu(void*, bool);
bool CEGUI__MenuItem_togglePopupMenu(void*);

//
// Begin class 'CEGUI::UDim'
//
void* CEGUI__UDim__Create0();
void* CEGUI__UDim__Create1(float, float);
void* CEGUI__UDim__Create2(void*);
void CEGUI__UDim__Destroy(void*);
float CEGUI__UDim_asRelative(void*, float);
float CEGUI__UDim_asAbsolute(void*, float);

//
// Begin class 'CEGUI::Renderer'
//
void CEGUI__Renderer__Destroy(void*);

//
// Begin class 'CEGUI::FalagardComponentBase'
//
void CEGUI__FalagardComponentBase__Destroy(void*);
void CEGUI__FalagardComponentBase_render0(void*, void*, void*, void*, bool);
void CEGUI__FalagardComponentBase_render1(void*, void*, void*, void*, void*, bool);
void CEGUI__FalagardComponentBase_setColoursPropertyIsColourRect(void*, bool);
void CEGUI__FalagardComponentBase_setHorzFormattingPropertySource(void*, void*);
void* CEGUI__FalagardComponentBase_getComponentArea(void*);
void CEGUI__FalagardComponentBase_setVertFormattingPropertySource(void*, void*);
void CEGUI__FalagardComponentBase_setComponentArea(void*, void*);
void CEGUI__FalagardComponentBase_setColoursPropertySource(void*, void*);
void* CEGUI__FalagardComponentBase_getColours(void*);
void CEGUI__FalagardComponentBase_setColours(void*, void*);

//
// Begin class 'CEGUI::WindowRenderer'
//
void CEGUI__WindowRenderer__Destroy(void*);
void* CEGUI__WindowRenderer_getClass(void*);
void CEGUI__WindowRenderer_performChildWindowLayout(void*);
void* CEGUI__WindowRenderer_getName(void*);
void* CEGUI__WindowRenderer_getUnclippedInnerRect(void*);
void CEGUI__WindowRenderer_update(void*, float);
void CEGUI__WindowRenderer_getRenderingContext(void*, void*);
void* CEGUI__WindowRenderer_getLookNFeel(void*);
void* CEGUI__WindowRenderer_getWindow(void*);

//
// Begin class 'CEGUI::Vertex'
//
void CEGUI__Vertex__Destroy(void*);

//
// Begin class 'CEGUI::Font'
//
void CEGUI__Font__Destroy(void*);
void CEGUI__Font_setDefaultResourceGroup(void*, void*);
float CEGUI__Font_getFontHeight(void*, float);
bool CEGUI__Font_isCodepointAvailable(void*, unsigned int);
void* CEGUI__Font_getName(void*);
void CEGUI__Font_drawText(void*, void*, void*, void*, void*, void*, float, float, float);
void* CEGUI__Font_getNativeResolution(void*);
void CEGUI__Font_writeXMLToStream(void*, void*);
float CEGUI__Font_getTextExtent(void*, void*, float);
void* CEGUI__Font_getTypeName(void*);
float CEGUI__Font_getLineSpacing(void*, float);
void* CEGUI__Font_getDefaultResourceGroup(void*);
void CEGUI__Font_notifyDisplaySizeChanged(void*, void*);
bool CEGUI__Font_isAutoScaled(void*);
void* CEGUI__Font_getGlyphData(void*, unsigned int);
unsigned int CEGUI__Font_getCharAtPixel0(void*, void*, float, float);
unsigned int CEGUI__Font_getCharAtPixel1(void*, void*, unsigned int, float, float);
void CEGUI__Font_setAutoScaled(void*, bool);
void CEGUI__Font_setNativeResolution(void*, void*);
float CEGUI__Font_getBaseline(void*, float);

//
// Begin class 'CEGUI::ItemEntryWindowRenderer'
//
void CEGUI__ItemEntryWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::MCLGridRef'
//
void* CEGUI__MCLGridRef__Create(unsigned int, unsigned int);
void CEGUI__MCLGridRef__Destroy(void*);

//
// Begin class 'CEGUI::StringInterpolator'
//
void CEGUI__StringInterpolator__Destroy(void*);
void* CEGUI__StringInterpolator_getType(void*);
void* CEGUI__StringInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__StringInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__StringInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::ItemEntry'
//
void* CEGUI__ItemEntry__Create(void*, void*);
void CEGUI__ItemEntry__Destroy(void*);
void* CEGUI__ItemEntry_getItemPixelSize(void*);
void CEGUI__ItemEntry_deselect(void*);
void CEGUI__ItemEntry_setSelected_impl(void*, bool, bool);
void CEGUI__ItemEntry_setSelected(void*, bool);
void* CEGUI__ItemEntry_getOwnerList(void*);
bool CEGUI__ItemEntry_isSelected(void*);
bool CEGUI__ItemEntry_isSelectable(void*);
void CEGUI__ItemEntry_setSelectable(void*, bool);
void CEGUI__ItemEntry_select(void*);

//
// Begin class 'CEGUI::String::FastLessCompare'
//
void CEGUI__String__FastLessCompare__Destroy(void*);

//
// Begin class 'CEGUI::PopupMenu'
//
void CEGUI__PopupMenu__Destroy(void*);
float CEGUI__PopupMenu_getFadeOutTime(void*);
float CEGUI__PopupMenu_getFadeInTime(void*);
void CEGUI__PopupMenu_openPopupMenu(void*, bool);
bool CEGUI__PopupMenu_isPopupMenuOpen(void*);
void CEGUI__PopupMenu_closePopupMenu(void*, bool);
void CEGUI__PopupMenu_setFadeOutTime(void*, float);
void CEGUI__PopupMenu_setFadeInTime(void*, float);

//
// Begin class 'CEGUI::ListboxItem'
//
void CEGUI__ListboxItem__Destroy(void*);
void CEGUI__ListboxItem_setSelected(void*, bool);
void CEGUI__ListboxItem_setAutoDeleted(void*, bool);
bool CEGUI__ListboxItem_isAutoDeleted(void*);
void* CEGUI__ListboxItem_getSelectionColours(void*);
void CEGUI__ListboxItem_setTooltipText(void*, void*);
void* CEGUI__ListboxItem_getUserData(void*);
void CEGUI__ListboxItem_setSelectionBrushImage0(void*, void*);
void CEGUI__ListboxItem_setSelectionBrushImage1(void*, void*, void*);
bool CEGUI__ListboxItem_isDisabled(void*);
void* CEGUI__ListboxItem_getTextVisual(void*);
bool CEGUI__ListboxItem_isSelected(void*);
void* CEGUI__ListboxItem_getTooltipText(void*);
void* CEGUI__ListboxItem_getOwnerWindow(void*);
unsigned int CEGUI__ListboxItem_getID(void*);
void* CEGUI__ListboxItem_getSelectionBrushImage(void*);
void* CEGUI__ListboxItem_getText(void*);
void CEGUI__ListboxItem_setID(void*, unsigned int);
void CEGUI__ListboxItem_setUserData(void*, void*);
void CEGUI__ListboxItem_setOwnerWindow(void*, void*);
void CEGUI__ListboxItem_setText(void*, void*);
void CEGUI__ListboxItem_setSelectionColours0(void*, void*);
void CEGUI__ListboxItem_setSelectionColours1(void*, void*, void*, void*, void*);
void CEGUI__ListboxItem_setSelectionColours2(void*, void*);
void CEGUI__ListboxItem_setDisabled(void*, bool);

//
// Begin class 'CEGUI::BiDiVisualMapping'
//
void CEGUI__BiDiVisualMapping__Destroy(void*);
void* CEGUI__BiDiVisualMapping_getTextVisual(void*);
bool CEGUI__BiDiVisualMapping_updateVisual(void*, void*);

//
// Begin class 'CEGUI::RenderedStringTextComponent'
//
void CEGUI__RenderedStringTextComponent__Destroy(void*);
void* CEGUI__RenderedStringTextComponent_clone(void*);
void CEGUI__RenderedStringTextComponent_draw(void*, void*, void*, void*, void*, float, float);
void* CEGUI__RenderedStringTextComponent_getFont(void*);
void CEGUI__RenderedStringTextComponent_setText(void*, void*);
void* CEGUI__RenderedStringTextComponent_getPixelSize(void*);
void* CEGUI__RenderedStringTextComponent_getText(void*);
bool CEGUI__RenderedStringTextComponent_canSplit(void*);
void CEGUI__RenderedStringTextComponent_setFont0(void*, void*);
void CEGUI__RenderedStringTextComponent_setFont1(void*, void*);
void* CEGUI__RenderedStringTextComponent_getColours(void*);
unsigned int CEGUI__RenderedStringTextComponent_getSpaceCount(void*);
void CEGUI__RenderedStringTextComponent_setColours0(void*, void*);
void CEGUI__RenderedStringTextComponent_setColours1(void*, void*);
void* CEGUI__RenderedStringTextComponent_split(void*, float, bool);

//
// Begin class 'CEGUI::Event::ScopedConnection'
//
void* CEGUI__Event__ScopedConnection__Create0();
void CEGUI__Event__ScopedConnection__Destroy(void*);
void CEGUI__Event__ScopedConnection_disconnect(void*);
bool CEGUI__Event__ScopedConnection_connected(void*);

//
// Begin class 'CEGUI::EditboxWindowRenderer'
//
void CEGUI__EditboxWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::ResourceEventArgs'
//
void* CEGUI__ResourceEventArgs__Create(void*, void*);
void CEGUI__ResourceEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::FontManager'
//
void* CEGUI__FontManager__Create();
void CEGUI__FontManager__Destroy(void*);
void CEGUI__FontManager_notifyDisplaySizeChanged(void*, void*);
void* CEGUI__FontManager_createFreeTypeFont(void*, void*, float, bool, void*, void*, bool, float, float, unsigned int);
void* CEGUI__FontManager_createPixmapFont(void*, void*, void*, void*, bool, float, float, unsigned int);

//
// Begin class 'CEGUI::RenderingSurface'
//
void* CEGUI__RenderingSurface__Create(void*);
void CEGUI__RenderingSurface__Destroy(void*);
void CEGUI__RenderingSurface_invalidate(void*);
void CEGUI__RenderingSurface_draw0(void*);
bool CEGUI__RenderingSurface_isRenderingWindow(void*);
void* CEGUI__RenderingSurface_getRenderTarget0(void*);
void* CEGUI__RenderingSurface_getRenderTarget1(void*);
void CEGUI__RenderingSurface_addGeometryBuffer(void*, unsigned int, void*);
void CEGUI__RenderingSurface_transferRenderingWindow(void*, void*);
bool CEGUI__RenderingSurface_isInvalidated(void*);
void CEGUI__RenderingSurface_removeGeometryBuffer(void*, unsigned int, void*);
void CEGUI__RenderingSurface_destroyRenderingWindow(void*, void*);
void* CEGUI__RenderingSurface_createRenderingWindow(void*, void*);
void CEGUI__RenderingSurface_clearGeometry0(void*, unsigned int);
void CEGUI__RenderingSurface_clearGeometry1(void*);

//
// Begin class 'CEGUI::ColourRect'
//
void* CEGUI__ColourRect__Create0();
void* CEGUI__ColourRect__Create1(void*);
void* CEGUI__ColourRect__Create2(void*, void*, void*, void*);
void* CEGUI__ColourRect__Create3(void*);
void CEGUI__ColourRect__Destroy(void*);
void CEGUI__ColourRect_setLeftAlpha(void*, float);
void* CEGUI__ColourRect_getSubRectangle(void*, float, float, float, float);
void CEGUI__ColourRect_setRightAlpha(void*, float);
void CEGUI__ColourRect_setBottomAlpha(void*, float);
bool CEGUI__ColourRect_isMonochromatic(void*);
void* CEGUI__ColourRect_getColourAtPoint(void*, float, float);
void CEGUI__ColourRect_setTopAlpha(void*, float);
void CEGUI__ColourRect_modulateAlpha(void*, float);
void CEGUI__ColourRect_setAlpha(void*, float);
void CEGUI__ColourRect_setColours(void*, void*);

//
// Begin class 'CEGUI::ComponentArea'
//
void CEGUI__ComponentArea__Destroy(void*);
void* CEGUI__ComponentArea_getPixelRect0(void*, void*);
void* CEGUI__ComponentArea_getPixelRect1(void*, void*, void*);
bool CEGUI__ComponentArea_isAreaFetchedFromProperty(void*);
void* CEGUI__ComponentArea_getAreaPropertySource(void*);
void CEGUI__ComponentArea_setAreaPropertySource(void*, void*);
void CEGUI__ComponentArea_writeXMLToStream(void*, void*);

//
// Begin class 'CEGUI::Affector'
//
void* CEGUI__Affector__Create(void*);
void CEGUI__Affector__Destroy(void*);
unsigned int CEGUI__Affector_getApplicationMethod(void*);
void CEGUI__Affector_savePropertyValues(void*, void*);
void CEGUI__Affector_setApplicationMethod(void*, unsigned int);
void* CEGUI__Affector_createKeyFrame0(void*, float);
void* CEGUI__Affector_createKeyFrame1(void*, float, void*, unsigned int, void*);
void CEGUI__Affector_moveKeyFrameToPosition0(void*, void*, float);
void CEGUI__Affector_moveKeyFrameToPosition1(void*, float, float);
void* CEGUI__Affector_getTargetProperty(void*);
void CEGUI__Affector_setTargetProperty(void*, void*);
void CEGUI__Affector_setInterpolator0(void*, void*);
void CEGUI__Affector_setInterpolator1(void*, void*);
void* CEGUI__Affector_getInterpolator(void*);
void CEGUI__Affector_destroyKeyFrame(void*, void*);
void* CEGUI__Affector_getKeyFrameAtIdx(void*, unsigned int);
void CEGUI__Affector_apply(void*, void*);
void* CEGUI__Affector_getKeyFrameAtPosition(void*, float);
unsigned int CEGUI__Affector_getNumKeyFrames(void*);

//
// Begin class 'CEGUI::Interpolator'
//
void CEGUI__Interpolator__Destroy(void*);

//
// Begin class 'CEGUI::SchemeManager'
//
void* CEGUI__SchemeManager__Create();
void CEGUI__SchemeManager__Destroy(void*);

//
// Begin class 'CEGUI::GeometryBuffer'
//
void CEGUI__GeometryBuffer__Destroy(void*);
unsigned int CEGUI__GeometryBuffer_getBlendMode(void*);
void CEGUI__GeometryBuffer_setBlendMode(void*, unsigned int);

//
// Begin class 'CEGUI::FrameComponent'
//
void CEGUI__FrameComponent__Destroy(void*);
unsigned int CEGUI__FrameComponent_getBackgroundHorizontalFormatting(void*);
void CEGUI__FrameComponent_setBackgroundHorizontalFormatting(void*, unsigned int);
void CEGUI__FrameComponent_setImage0(void*, unsigned int, void*);
void CEGUI__FrameComponent_setImage1(void*, unsigned int, void*, void*);
unsigned int CEGUI__FrameComponent_getBackgroundVerticalFormatting(void*);
void CEGUI__FrameComponent_setBackgroundVerticalFormatting(void*, unsigned int);
void CEGUI__FrameComponent_writeXMLToStream(void*, void*);
void* CEGUI__FrameComponent_getImage(void*, unsigned int);

//
// Begin class 'CEGUI::ListHeader'
//
void* CEGUI__ListHeader__Create(void*, void*);
void CEGUI__ListHeader__Destroy(void*);
void CEGUI__ListHeader_setColumnSizingEnabled(void*, bool);
unsigned int CEGUI__ListHeader_getSortDirection(void*);
void CEGUI__ListHeader_moveSegment0(void*, void*, unsigned int);
void CEGUI__ListHeader_moveSegment1(void*, void*, void*);
unsigned int CEGUI__ListHeader_getColumnWithText(void*, void*);
void CEGUI__ListHeader_setColumnWidth(void*, unsigned int, void*);
void* CEGUI__ListHeader_getSortSegment(void*);
float CEGUI__ListHeader_getSegmentOffset(void*);
unsigned int CEGUI__ListHeader_getColumnCount(void*);
bool CEGUI__ListHeader_isColumnDraggingEnabled(void*);
unsigned int CEGUI__ListHeader_getColumnFromSegment(void*, void*);
void CEGUI__ListHeader_setSortColumn(void*, unsigned int);
void CEGUI__ListHeader_moveColumn0(void*, unsigned int, unsigned int);
void CEGUI__ListHeader_moveColumn1(void*, unsigned int, void*);
void CEGUI__ListHeader_setSortDirection(void*, unsigned int);
float CEGUI__ListHeader_getTotalSegmentsPixelExtent(void*);
void* CEGUI__ListHeader_getSegmentFromColumn(void*, unsigned int);
void CEGUI__ListHeader_setSegmentOffset(void*, float);
void CEGUI__ListHeader_setSortColumnFromID(void*, unsigned int);
void* CEGUI__ListHeader_getColumnWidth(void*, unsigned int);
unsigned int CEGUI__ListHeader_getColumnFromID(void*, unsigned int);
float CEGUI__ListHeader_getPixelOffsetToSegment(void*, void*);
bool CEGUI__ListHeader_isSortingEnabled(void*);
void CEGUI__ListHeader_setSortSegment(void*, void*);
void CEGUI__ListHeader_removeColumn(void*, unsigned int);
void CEGUI__ListHeader_addColumn(void*, void*, unsigned int, void*);
void CEGUI__ListHeader_insertColumn0(void*, void*, unsigned int, void*, unsigned int);
void CEGUI__ListHeader_insertColumn1(void*, void*, unsigned int, void*, void*);
unsigned int CEGUI__ListHeader_getSortColumn(void*);
void CEGUI__ListHeader_setColumnDraggingEnabled(void*, bool);
void CEGUI__ListHeader_setSortingEnabled(void*, bool);
void* CEGUI__ListHeader_getSegmentFromID(void*, unsigned int);
void CEGUI__ListHeader_removeSegment(void*, void*);
float CEGUI__ListHeader_getPixelOffsetToColumn(void*, unsigned int);
bool CEGUI__ListHeader_isColumnSizingEnabled(void*);

//
// Begin class 'CEGUI::Tooltip'
//
void* CEGUI__Tooltip__Create(void*, void*);
void CEGUI__Tooltip__Destroy(void*);
void* CEGUI__Tooltip_getTextSize(void*);
void CEGUI__Tooltip_setHoverTime(void*, float);
float CEGUI__Tooltip_getDisplayTime(void*);
void CEGUI__Tooltip_setDisplayTime(void*, float);
void CEGUI__Tooltip_setFadeTime(void*, float);
float CEGUI__Tooltip_getFadeTime(void*);
void CEGUI__Tooltip_setTargetWindow(void*, void*);
void CEGUI__Tooltip_sizeSelf(void*);
void* CEGUI__Tooltip_getTargetWindow(void*);
float CEGUI__Tooltip_getHoverTime(void*);
void CEGUI__Tooltip_positionSelf(void*);
void CEGUI__Tooltip_resetTimer(void*);
void* CEGUI__Tooltip_getTextSize_impl(void*);

//
// Begin class 'CEGUI::FontGlyph'
//
void* CEGUI__FontGlyph__Create(float, void*);
void CEGUI__FontGlyph__Destroy(void*);
float CEGUI__FontGlyph_getWidth(void*, float);
float CEGUI__FontGlyph_getRenderedAdvance(void*, float);
void CEGUI__FontGlyph_setImage(void*, void*);
float CEGUI__FontGlyph_getAdvance(void*, float);
void CEGUI__FontGlyph_setAdvance(void*, float);
float CEGUI__FontGlyph_getHeight(void*, float);
void* CEGUI__FontGlyph_getImageset(void*);
void* CEGUI__FontGlyph_getSize(void*, float, float);
void* CEGUI__FontGlyph_getImage(void*);

//
// Begin class 'CEGUI::ButtonBase'
//
void* CEGUI__ButtonBase__Create(void*, void*);
void CEGUI__ButtonBase__Destroy(void*);
bool CEGUI__ButtonBase_isPushed(void*);
bool CEGUI__ButtonBase_isHovering(void*);

//
// Begin class 'CEGUI::RenderEffect'
//
void CEGUI__RenderEffect__Destroy(void*);

//
// Begin class 'CEGUI::ItemListbox'
//
void CEGUI__ItemListbox__Destroy(void*);
void* CEGUI__ItemListbox_getFirstSelectedItem(void*, unsigned int);
void* CEGUI__ItemListbox_getLastSelectedItem(void*);
void CEGUI__ItemListbox_selectRange(void*, unsigned int, unsigned int);
void CEGUI__ItemListbox_initialiseComponents(void*);
void CEGUI__ItemListbox_layoutItemWidgets(void*);
unsigned int CEGUI__ItemListbox_getSelectedCount(void*);
void CEGUI__ItemListbox_clearAllSelections(void*);
void CEGUI__ItemListbox_setMultiSelectEnabled(void*, bool);
void* CEGUI__ItemListbox_getNextSelectedItem(void*);
void CEGUI__ItemListbox_selectAllItems(void*);
void* CEGUI__ItemListbox_getContentSize(void*);
bool CEGUI__ItemListbox_isItemSelected(void*, unsigned int);
bool CEGUI__ItemListbox_testClassName_impl(void*, void*);
void* CEGUI__ItemListbox_getNextSelectedItemAfter(void*, void*);
void CEGUI__ItemListbox_notifyItemSelectState(void*, void*, bool);
bool CEGUI__ItemListbox_isMultiSelectEnabled(void*);
void CEGUI__ItemListbox_notifyItemClicked(void*, void*);

//
// Begin class 'CEGUI::FreeFunctionSlot'
//
void CEGUI__FreeFunctionSlot__Destroy(void*);

//
// Begin class 'CEGUI::Dimension'
//
void* CEGUI__Dimension__Create0();
void* CEGUI__Dimension__Create1(void*, unsigned int);
void* CEGUI__Dimension__Create2(void*);
void CEGUI__Dimension__Destroy(void*);
unsigned int CEGUI__Dimension_getDimensionType(void*);
void CEGUI__Dimension_setBaseDimension(void*, void*);
void CEGUI__Dimension_setDimensionType(void*, unsigned int);
void* CEGUI__Dimension_getBaseDimension(void*);
void CEGUI__Dimension_writeXMLToStream(void*, void*);

//
// Begin class 'CEGUI::MouseEventArgs'
//
void* CEGUI__MouseEventArgs__Create(void*);
void CEGUI__MouseEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::Font_xmlHandler'
//
void* CEGUI__Font_xmlHandler__Create(void*, void*);
void CEGUI__Font_xmlHandler__Destroy(void*);
void CEGUI__Font_xmlHandler_elementStart(void*, void*, void*);
void* CEGUI__Font_xmlHandler_getObject(void*);
void* CEGUI__Font_xmlHandler_getObjectName(void*);
void CEGUI__Font_xmlHandler_elementEnd(void*, void*);

//
// Begin class 'CEGUI::TreeEventArgs'
//
void* CEGUI__TreeEventArgs__Create(void*);
void CEGUI__TreeEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::RegexMatcher'
//
void CEGUI__RegexMatcher__Destroy(void*);

//
// Begin class 'CEGUI::EventSet'
//
void* CEGUI__EventSet__Create0();
void CEGUI__EventSet__Destroy(void*);
void CEGUI__EventSet_removeEvent(void*, void*);
bool CEGUI__EventSet_isMuted(void*);
void CEGUI__EventSet_addEvent(void*, void*);
void CEGUI__EventSet_removeAllEvents(void*);
bool CEGUI__EventSet_isEventPresent(void*, void*);
void CEGUI__EventSet_fireEvent(void*, void*, void*, void*);
void CEGUI__EventSet_setMutedState(void*, bool);

//
// Begin class 'CEGUI::RenderedStringParser'
//
void CEGUI__RenderedStringParser__Destroy(void*);

//
// Begin class 'CEGUI::AnimationEventArgs'
//
void* CEGUI__AnimationEventArgs__Create(void*);
void CEGUI__AnimationEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::TooltipWindowRenderer'
//
void CEGUI__TooltipWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::PropertyHelper'
//
void CEGUI__PropertyHelper__Destroy(void*);
void* CEGUI__PropertyHelper_boolToString(void*, bool);
void* CEGUI__PropertyHelper_stringToVector3(void*, void*);
void* CEGUI__PropertyHelper_urectToString(void*, void*);
void* CEGUI__PropertyHelper_stringToUVector2(void*, void*);
int CEGUI__PropertyHelper_stringToInt(void*, void*);
float CEGUI__PropertyHelper_stringToFloat(void*, void*);
void* CEGUI__PropertyHelper_udimToString(void*, void*);
void* CEGUI__PropertyHelper_uintToString(void*, unsigned int);
void* CEGUI__PropertyHelper_floatToString(void*, float);
unsigned int CEGUI__PropertyHelper_stringToUint(void*, void*);
void* CEGUI__PropertyHelper_stringToColourRect(void*, void*);
void* CEGUI__PropertyHelper_uvector2ToString(void*, void*);
void* CEGUI__PropertyHelper_stringToUDim(void*, void*);
void* CEGUI__PropertyHelper_pointToString(void*, void*);
void* CEGUI__PropertyHelper_stringToImage(void*, void*);
void* CEGUI__PropertyHelper_colourToString(void*, void*);
void* CEGUI__PropertyHelper_stringToSize(void*, void*);
void* CEGUI__PropertyHelper_uboxToString(void*, void*);
void* CEGUI__PropertyHelper_imageToString(void*, void*);
void* CEGUI__PropertyHelper_stringToURect(void*, void*);
void* CEGUI__PropertyHelper_sizeToString(void*, void*);
void* CEGUI__PropertyHelper_colourRectToString(void*, void*);
void* CEGUI__PropertyHelper_rectToString(void*, void*);
void* CEGUI__PropertyHelper_stringToUBox(void*, void*);
void* CEGUI__PropertyHelper_stringToColour(void*, void*);
bool CEGUI__PropertyHelper_stringToBool(void*, void*);
void* CEGUI__PropertyHelper_stringToPoint(void*, void*);
void* CEGUI__PropertyHelper_intToString(void*, int);
void* CEGUI__PropertyHelper_stringToRect(void*, void*);
void* CEGUI__PropertyHelper_vector3ToString(void*, void*);

//
// Begin class 'CEGUI::Slider'
//
void* CEGUI__Slider__Create(void*, void*);
void CEGUI__Slider__Destroy(void*);
void CEGUI__Slider_setClickStep(void*, float);
void CEGUI__Slider_initialiseComponents(void*);
void CEGUI__Slider_setCurrentValue(void*, float);
float CEGUI__Slider_getMaxValue(void*);
float CEGUI__Slider_getClickStep(void*);
void* CEGUI__Slider_getThumb(void*);
float CEGUI__Slider_getCurrentValue(void*);
void CEGUI__Slider_setMaxValue(void*, float);

//
// Begin class 'CEGUI::HorizontalLayoutContainer'
//
void CEGUI__HorizontalLayoutContainer__Destroy(void*);
void CEGUI__HorizontalLayoutContainer_layout(void*);

//
// Begin class 'CEGUI::Thumb'
//
void* CEGUI__Thumb__Create(void*, void*);
void CEGUI__Thumb__Destroy(void*);
void CEGUI__Thumb_setHorzRange(void*, float, float);
void CEGUI__Thumb_setVertFree(void*, bool);
void CEGUI__Thumb_setVertRange(void*, float, float);
bool CEGUI__Thumb_isHotTracked(void*);
void CEGUI__Thumb_setHorzFree(void*, bool);
bool CEGUI__Thumb_isVertFree(void*);
bool CEGUI__Thumb_isHorzFree(void*);
void CEGUI__Thumb_setHotTracked(void*, bool);

//
// Begin class 'CEGUI::Animation'
//
void* CEGUI__Animation__Create(void*);
void CEGUI__Animation__Destroy(void*);
void CEGUI__Animation_undefineAllAutoSubscriptions(void*);
void CEGUI__Animation_setReplayMode(void*, unsigned int);
void* CEGUI__Animation_getAffectorAtIdx(void*, unsigned int);
void* CEGUI__Animation_getName(void*);
void CEGUI__Animation_apply(void*, void*);
unsigned int CEGUI__Animation_getNumAffectors(void*);
bool CEGUI__Animation_getAutoStart(void*);
void CEGUI__Animation_savePropertyValues(void*, void*);
unsigned int CEGUI__Animation_getReplayMode(void*);
void CEGUI__Animation_setAutoStart(void*, bool);
void CEGUI__Animation_defineAutoSubscription(void*, void*, void*);
void* CEGUI__Animation_createAffector0(void*);
void* CEGUI__Animation_createAffector1(void*, void*, void*);
float CEGUI__Animation_getDuration(void*);
void CEGUI__Animation_destroyAffector(void*, void*);
void CEGUI__Animation_setDuration(void*, float);
void CEGUI__Animation_autoSubscribe(void*, void*);
void CEGUI__Animation_undefineAutoSubscription(void*, void*, void*);
void CEGUI__Animation_autoUnsubscribe(void*, void*);

//
// Begin class 'CEGUI::Spinner'
//
void* CEGUI__Spinner__Create(void*, void*);
void CEGUI__Spinner__Destroy(void*);
void CEGUI__Spinner_initialiseComponents(void*);
void CEGUI__Spinner_setTextInputMode(void*, unsigned int);
void CEGUI__Spinner_setCurrentValue(void*, double);
double CEGUI__Spinner_getMinimumValue(void*);
unsigned int CEGUI__Spinner_getTextInputMode(void*);
void CEGUI__Spinner_setMinimumValue(void*, double);
double CEGUI__Spinner_getStepSize(void*);
void CEGUI__Spinner_setMaximumValue(void*, double);
void CEGUI__Spinner_setStepSize(void*, double);
double CEGUI__Spinner_getCurrentValue(void*);
double CEGUI__Spinner_getMaximumValue(void*);

//
// Begin class 'CEGUI::CoordConverter'
//
void CEGUI__CoordConverter__Destroy(void*);
float CEGUI__CoordConverter_windowToScreenX0(void*, void*, void*);
float CEGUI__CoordConverter_windowToScreenX1(void*, void*, float);
float CEGUI__CoordConverter_windowToScreenY0(void*, void*, void*);
float CEGUI__CoordConverter_windowToScreenY1(void*, void*, float);
float CEGUI__CoordConverter_screenToWindowX0(void*, void*, void*);
float CEGUI__CoordConverter_screenToWindowX1(void*, void*, float);
float CEGUI__CoordConverter_screenToWindowY0(void*, void*, void*);
float CEGUI__CoordConverter_screenToWindowY1(void*, void*, float);
void* CEGUI__CoordConverter_windowToScreen0(void*, void*, void*);
void* CEGUI__CoordConverter_windowToScreen1(void*, void*, void*);
void* CEGUI__CoordConverter_windowToScreen2(void*, void*, void*);
void* CEGUI__CoordConverter_windowToScreen3(void*, void*, void*);
void* CEGUI__CoordConverter_screenToWindow0(void*, void*, void*);
void* CEGUI__CoordConverter_screenToWindow1(void*, void*, void*);
void* CEGUI__CoordConverter_screenToWindow2(void*, void*, void*);
void* CEGUI__CoordConverter_screenToWindow3(void*, void*, void*);

//
// Begin class 'CEGUI::TreeItem'
//
void* CEGUI__TreeItem__Create(void*, unsigned int, void*, bool, bool);
void CEGUI__TreeItem__Destroy(void*);
void CEGUI__TreeItem_addItem(void*, void*);
void CEGUI__TreeItem_setSelected(void*, bool);
void* CEGUI__TreeItem_getPixelSize(void*);
void CEGUI__TreeItem_setAutoDeleted(void*, bool);
void CEGUI__TreeItem_setTextColours0(void*, void*);
void CEGUI__TreeItem_setTextColours1(void*, void*, void*, void*, void*);
void CEGUI__TreeItem_setTextColours2(void*, void*);
bool CEGUI__TreeItem_isAutoDeleted(void*);
void* CEGUI__TreeItem_getSelectionColours(void*);
unsigned int CEGUI__TreeItem_getItemCount(void*);
void CEGUI__TreeItem_setID(void*, unsigned int);
void CEGUI__TreeItem_toggleIsOpen(void*);
void CEGUI__TreeItem_setButtonLocation(void*, void*);
void* CEGUI__TreeItem_getUserData(void*);
void CEGUI__TreeItem_setSelectionBrushImage0(void*, void*);
void CEGUI__TreeItem_setSelectionBrushImage1(void*, void*, void*);
bool CEGUI__TreeItem_isDisabled(void*);
void* CEGUI__TreeItem_getTextVisual(void*);
bool CEGUI__TreeItem_isSelected(void*);
void CEGUI__TreeItem_setIcon(void*, void*);
void* CEGUI__TreeItem_getTooltipText(void*);
void* CEGUI__TreeItem_getOwnerWindow(void*);
void CEGUI__TreeItem_draw(void*, void*, void*, float, void*);
void* CEGUI__TreeItem_getTreeItemFromIndex(void*, unsigned int);
void* CEGUI__TreeItem_getFont(void*);
unsigned int CEGUI__TreeItem_getID(void*);
void* CEGUI__TreeItem_getSelectionBrushImage(void*);
void* CEGUI__TreeItem_getText(void*);
void* CEGUI__TreeItem_getTextColours(void*);
void CEGUI__TreeItem_removeItem(void*, void*);
void CEGUI__TreeItem_setTooltipText(void*, void*);
void CEGUI__TreeItem_setUserData(void*, void*);
void CEGUI__TreeItem_setOwnerWindow(void*, void*);
void* CEGUI__TreeItem_getButtonLocation(void*);
void CEGUI__TreeItem_setText(void*, void*);
void CEGUI__TreeItem_setSelectionColours0(void*, void*);
void CEGUI__TreeItem_setSelectionColours1(void*, void*, void*, void*, void*);
void CEGUI__TreeItem_setSelectionColours2(void*, void*);
void CEGUI__TreeItem_setDisabled(void*, bool);
void CEGUI__TreeItem_setFont0(void*, void*);
void CEGUI__TreeItem_setFont1(void*, void*);
bool CEGUI__TreeItem_getIsOpen(void*);

//
// Begin class 'CEGUI::Titlebar'
//
void* CEGUI__Titlebar__Create(void*, void*);
void CEGUI__Titlebar__Destroy(void*);
void CEGUI__Titlebar_setDraggingEnabled(void*, bool);
bool CEGUI__Titlebar_isDraggingEnabled(void*);

//
// Begin class 'CEGUI::WidgetComponent'
//
void* CEGUI__WidgetComponent__Create0();
void* CEGUI__WidgetComponent__Create1(void*, void*, void*, void*);
void CEGUI__WidgetComponent__Destroy(void*);
void* CEGUI__WidgetComponent_getWindowRendererType(void*);
void* CEGUI__WidgetComponent_getWidgetNameSuffix(void*);
void* CEGUI__WidgetComponent_getBaseWidgetType(void*);
void CEGUI__WidgetComponent_setWindowRendererType(void*, void*);
void CEGUI__WidgetComponent_setWidgetNameSuffix(void*, void*);
void CEGUI__WidgetComponent_clearPropertyInitialisers(void*);
void CEGUI__WidgetComponent_create(void*, void*);
unsigned int CEGUI__WidgetComponent_getHorizontalWidgetAlignment(void*);
unsigned int CEGUI__WidgetComponent_getVerticalWidgetAlignment(void*);
void* CEGUI__WidgetComponent_findPropertyInitialiser(void*, void*);
void* CEGUI__WidgetComponent_getComponentArea(void*);
void CEGUI__WidgetComponent_setVerticalWidgetAlignment(void*, unsigned int);
void CEGUI__WidgetComponent_writeXMLToStream(void*, void*);
void CEGUI__WidgetComponent_setComponentArea(void*, void*);
void CEGUI__WidgetComponent_setHorizontalWidgetAlignment(void*, unsigned int);
void* CEGUI__WidgetComponent_getWidgetLookName(void*);
void CEGUI__WidgetComponent_addPropertyInitialiser(void*, void*);
void CEGUI__WidgetComponent_setWidgetLookName(void*, void*);
void CEGUI__WidgetComponent_setBaseWidgetType(void*, void*);
void CEGUI__WidgetComponent_layout(void*, void*);

//
// Begin class 'CEGUI::WindowRendererManager'
//
void* CEGUI__WindowRendererManager__Create();
void CEGUI__WindowRendererManager__Destroy(void*);
void* CEGUI__WindowRendererManager_createWindowRenderer(void*, void*);
bool CEGUI__WindowRendererManager_isFactoryPresent(void*, void*);
void* CEGUI__WindowRendererManager_getFactory(void*, void*);
void CEGUI__WindowRendererManager_destroyWindowRenderer(void*, void*);
void CEGUI__WindowRendererManager_removeFactory(void*, void*);
void* CEGUI__WindowRendererManager_getSingleton(void*);
void* CEGUI__WindowRendererManager_getSingletonPtr(void*);
void CEGUI__WindowRendererManager_addFactory(void*, void*);

//
// Begin class 'CEGUI::Property'
//
void CEGUI__Property__Destroy(void*);
void* CEGUI__Property_getName(void*);
void* CEGUI__Property_getDefault(void*, void*);
void* CEGUI__Property_getHelp(void*);
void CEGUI__Property_writeXMLToStream(void*, void*, void*);
bool CEGUI__Property_isDefault(void*, void*);

//
// Begin class 'CEGUI::WindowRendererFactory'
//
void CEGUI__WindowRendererFactory__Destroy(void*);
void* CEGUI__WindowRendererFactory_getName(void*);

//
// Begin class 'CEGUI::FactoryModule'
//
void* CEGUI__FactoryModule__Create(void*);
void CEGUI__FactoryModule__Destroy(void*);
void CEGUI__FactoryModule_registerFactory(void*, void*);
unsigned int CEGUI__FactoryModule_registerAllFactories(void*);

//
// Begin class 'CEGUI::ScrolledItemListBase'
//
void CEGUI__ScrolledItemListBase__Destroy(void*);
bool CEGUI__ScrolledItemListBase_isVertScrollbarAlwaysShown(void*);
void CEGUI__ScrolledItemListBase_ensureItemIsVisibleVert(void*, void*);
void CEGUI__ScrolledItemListBase_setShowHorzScrollbar(void*, bool);
void* CEGUI__ScrolledItemListBase_getHorzScrollbar(void*);
void CEGUI__ScrolledItemListBase_initialiseComponents(void*);
void CEGUI__ScrolledItemListBase_setShowVertScrollbar(void*, bool);
bool CEGUI__ScrolledItemListBase_isHorzScrollbarAlwaysShown(void*);
void CEGUI__ScrolledItemListBase_ensureItemIsVisibleHorz(void*, void*);
void* CEGUI__ScrolledItemListBase_getVertScrollbar(void*);

//
// Begin class 'CEGUI::ActivationEventArgs'
//
void* CEGUI__ActivationEventArgs__Create(void*);
void CEGUI__ActivationEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::ListboxWindowRenderer'
//
void CEGUI__ListboxWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::ScrolledContainer'
//
void* CEGUI__ScrolledContainer__Create(void*, void*);
void CEGUI__ScrolledContainer__Destroy(void*);
void* CEGUI__ScrolledContainer_getChildExtentsArea(void*);
bool CEGUI__ScrolledContainer_isContentPaneAutoSized(void*);
void CEGUI__ScrolledContainer_setContentArea(void*, void*);
void* CEGUI__ScrolledContainer_getContentArea(void*);
void CEGUI__ScrolledContainer_setContentPaneAutoSized(void*, bool);
void* CEGUI__ScrolledContainer_getUnclippedInnerRect_impl(void*);

//
// Begin class 'CEGUI::ImageryComponent'
//
void CEGUI__ImageryComponent__Destroy(void*);
void CEGUI__ImageryComponent_setImagePropertySource(void*, void*);
unsigned int CEGUI__ImageryComponent_getVerticalFormatting(void*);
void CEGUI__ImageryComponent_setImage0(void*, void*);
void CEGUI__ImageryComponent_setImage1(void*, void*, void*);
unsigned int CEGUI__ImageryComponent_getHorizontalFormatting(void*);
bool CEGUI__ImageryComponent_isImageFetchedFromProperty(void*);
void CEGUI__ImageryComponent_setVerticalFormatting(void*, unsigned int);
void CEGUI__ImageryComponent_writeXMLToStream(void*, void*);
void* CEGUI__ImageryComponent_getImage(void*);
void* CEGUI__ImageryComponent_getImagePropertySource(void*);
void CEGUI__ImageryComponent_setHorizontalFormatting(void*, unsigned int);

//
// Begin class 'CEGUI::Listbox'
//
void* CEGUI__Listbox__Create(void*, void*);
void CEGUI__Listbox__Destroy(void*);
void* CEGUI__Listbox_getFirstSelectedItem(void*);
void CEGUI__Listbox_setMultiselectEnabled(void*, bool);
bool CEGUI__Listbox_isItemTooltipsEnabled(void*);
bool CEGUI__Listbox_isMultiselectEnabled(void*);
void CEGUI__Listbox_initialiseComponents(void*);
void CEGUI__Listbox_setItemSelectState0(void*, void*, bool);
void CEGUI__Listbox_setItemSelectState1(void*, unsigned int, bool);
unsigned int CEGUI__Listbox_getItemCount(void*);
unsigned int CEGUI__Listbox_getSelectedCount(void*);
void CEGUI__Listbox_clearAllSelections(void*);
void CEGUI__Listbox_resetList(void*);
void CEGUI__Listbox_setShowHorzScrollbar(void*, bool);
bool CEGUI__Listbox_isSortEnabled(void*);
void* CEGUI__Listbox_getHorzScrollbar(void*);
void* CEGUI__Listbox_findItemWithText(void*, void*, void*);
void* CEGUI__Listbox_getListRenderArea(void*);
bool CEGUI__Listbox_isItemSelected(void*, unsigned int);
float CEGUI__Listbox_getTotalItemsHeight(void*);
bool CEGUI__Listbox_isVertScrollbarAlwaysShown(void*);
float CEGUI__Listbox_getWidestItemWidth(void*);
void CEGUI__Listbox_insertItem(void*, void*, void*);
void CEGUI__Listbox_addItem(void*, void*);
bool CEGUI__Listbox_isHorzScrollbarAlwaysShown(void*);
void CEGUI__Listbox_removeItem(void*, void*);
bool CEGUI__Listbox_isListboxItemInList(void*, void*);
void* CEGUI__Listbox_getNextSelected(void*, void*);
void CEGUI__Listbox_ensureItemIsVisible0(void*, unsigned int);
void CEGUI__Listbox_ensureItemIsVisible1(void*, void*);
void CEGUI__Listbox_handleUpdatedItemData(void*);
void* CEGUI__Listbox_getListboxItemFromIndex(void*, unsigned int);
void CEGUI__Listbox_setSortingEnabled(void*, bool);
unsigned int CEGUI__Listbox_getItemIndex(void*, void*);
void CEGUI__Listbox_setItemTooltipsEnabled(void*, bool);
void CEGUI__Listbox_setShowVertScrollbar(void*, bool);
void* CEGUI__Listbox_getItemAtPoint(void*, void*);
void* CEGUI__Listbox_getVertScrollbar(void*);

//
// Begin class 'CEGUI::RenderEffectFactory'
//
void CEGUI__RenderEffectFactory__Destroy(void*);

//
// Begin class 'CEGUI::AnimationInstance'
//
void* CEGUI__AnimationInstance__Create(void*);
void CEGUI__AnimationInstance__Destroy(void*);
float CEGUI__AnimationInstance_getMaxStepDeltaClamp(void*);
bool CEGUI__AnimationInstance_getSkipNextStep(void*);
void* CEGUI__AnimationInstance_getTarget(void*);
void CEGUI__AnimationInstance_purgeSavedPropertyValues(void*);
void CEGUI__AnimationInstance_unsubscribeAutoConnections(void*);
float CEGUI__AnimationInstance_getMaxStepDeltaSkip(void*);
void CEGUI__AnimationInstance_setMaxStepDeltaSkip(void*, float);
bool CEGUI__AnimationInstance_handlePause(void*, void*);
void CEGUI__AnimationInstance_pause(void*);
void CEGUI__AnimationInstance_setMaxStepDeltaClamp(void*, float);
bool CEGUI__AnimationInstance_handleStart(void*, void*);
void* CEGUI__AnimationInstance_getEventReceiver(void*);
void CEGUI__AnimationInstance_start(void*, bool);
bool CEGUI__AnimationInstance_handleUnpause(void*, void*);
bool CEGUI__AnimationInstance_handleTogglePause(void*, void*);
void CEGUI__AnimationInstance_setTargetWindow(void*, void*);
void CEGUI__AnimationInstance_savePropertyValue(void*, void*);
void CEGUI__AnimationInstance_unpause(void*, bool);
void CEGUI__AnimationInstance_setSkipNextStep(void*, bool);
void CEGUI__AnimationInstance_setEventSender(void*, void*);
void* CEGUI__AnimationInstance_getSavedPropertyValue(void*, void*);
void CEGUI__AnimationInstance_setTarget(void*, void*);
void CEGUI__AnimationInstance_stop(void*);
bool CEGUI__AnimationInstance_handleStop(void*, void*);
void* CEGUI__AnimationInstance_getEventSender(void*);
void CEGUI__AnimationInstance_step(void*, float);
void CEGUI__AnimationInstance_togglePause(void*, bool);
void CEGUI__AnimationInstance_setPosition(void*, float);
float CEGUI__AnimationInstance_getPosition(void*);
bool CEGUI__AnimationInstance_isRunning(void*);
float CEGUI__AnimationInstance_getSpeed(void*);
void* CEGUI__AnimationInstance_getDefinition(void*);
void CEGUI__AnimationInstance_setSpeed(void*, float);
void CEGUI__AnimationInstance_setEventReceiver(void*, void*);

//
// Begin class 'CEGUI::Window'
//
void* CEGUI__Window__Create0(void*, void*);
void CEGUI__Window__Destroy(void*);
bool CEGUI__Window_testClassName(void*, void*);
void* CEGUI__Window_getMaxSize(void*);
void CEGUI__Window_show(void*);
void* CEGUI__Window_getYPosition(void*);
void* CEGUI__Window_getChildAtIdx(void*, unsigned int);
void CEGUI__Window_cloneChildWidgetsTo(void*, void*);
void CEGUI__Window_addChildWindow0(void*, void*);
void CEGUI__Window_addChildWindow1(void*, void*);
void* CEGUI__Window_getSize(void*);
bool CEGUI__Window_isUsingDefaultTooltip(void*);
void CEGUI__Window_getRenderingContext(void*, void*);
bool CEGUI__Window_inheritsAlpha(void*);
void* CEGUI__Window_getRenderingSurface(void*);
void* CEGUI__Window_getUserString(void*, void*);
void CEGUI__Window_setYPosition(void*, void*);
void* CEGUI__Window_getBiDiVisualMapping(void*);
void CEGUI__Window_setWritingXMLAllowed(void*, bool);
bool CEGUI__Window_wantsMultiClickEvents(void*);
void* CEGUI__Window_getUnprojectedPosition(void*, void*);
void CEGUI__Window_setModalState(void*, bool);
void* CEGUI__Window_getActiveSibling(void*);
void CEGUI__Window_setXPosition(void*, void*);
void CEGUI__Window_notifyDragDropItemDropped(void*, void*);
void* CEGUI__Window_getWindowRendererName(void*);
void CEGUI__Window_appendText(void*, void*);
void* CEGUI__Window_getRenderedString(void*);
float CEGUI__Window_getEffectiveAlpha(void*);
void* CEGUI__Window_getChildAtPosition(void*, void*);
bool CEGUI__Window_isNonClientWindow(void*);
void CEGUI__Window_setWindowRenderer(void*, void*);
bool CEGUI__Window_isAutoWindow(void*);
void* CEGUI__Window_getMargin(void*);
bool CEGUI__Window_isAlwaysOnTop(void*);
void* CEGUI__Window_getUnclippedInnerRect_impl(void*);
bool CEGUI__Window_isDragDropTarget(void*);
void CEGUI__Window_setMinSize(void*, void*);
void CEGUI__Window_initialiseComponents(void*);
void CEGUI__Window_moveToBack(void*);
void CEGUI__Window_releaseInput(void*);
void CEGUI__Window_moveInFront(void*, void*);
void CEGUI__Window_setHorizontalAlignment(void*, unsigned int);
void* CEGUI__Window_getClipRect(void*, bool);
float CEGUI__Window_getAlpha(void*);
void CEGUI__Window_setSize(void*, void*);
void CEGUI__Window_insertText(void*, void*, unsigned int);
void CEGUI__Window_activate(void*);
void CEGUI__Window_setArea0(void*, void*, void*, void*, void*);
void CEGUI__Window_setArea1(void*, void*, void*);
void CEGUI__Window_setArea2(void*, void*);
bool CEGUI__Window_isWritingXMLAllowed(void*);
bool CEGUI__Window_restoresOldCapture(void*);
bool CEGUI__Window_isTextParsingEnabled(void*);
void CEGUI__Window_setDestroyedByParent(void*, bool);
void CEGUI__Window_setTextParsingEnabled(void*, bool);
bool CEGUI__Window_isCapturedByThis(void*);
void CEGUI__Window_setMouseCursor0(void*, void*);
void CEGUI__Window_setMouseCursor1(void*, unsigned int);
void CEGUI__Window_setMouseCursor2(void*, void*, void*);
void CEGUI__Window_hide(void*);
void* CEGUI__Window_getUserData(void*);
void CEGUI__Window_setAutoRepeatRate(void*, float);
void CEGUI__Window_deactivate(void*);
void* CEGUI__Window_getName(void*);
void CEGUI__Window_notifyDragDropItemLeaves(void*, void*);
bool CEGUI__Window_getModalState(void*);
void CEGUI__Window_setNonClientWindow(void*, bool);
void* CEGUI__Window_getChildRecursive0(void*, void*);
void* CEGUI__Window_getChildRecursive1(void*, unsigned int);
void CEGUI__Window_setRotation(void*, void*);
void CEGUI__Window_notifyDragDropItemEnters(void*, void*);
void CEGUI__Window_setUserString(void*, void*, void*);
void* CEGUI__Window_getMouseCursor(void*, bool);
void CEGUI__Window_setRenderingSurface(void*, void*);
void CEGUI__Window_setLookNFeel(void*, void*);
void* CEGUI__Window_getCustomRenderedStringParser(void*);
void* CEGUI__Window_getActiveChild0(void*);
void* CEGUI__Window_getActiveChild1(void*);
bool CEGUI__Window_isMouseAutoRepeatEnabled(void*);
void CEGUI__Window_setVerticalAlignment(void*, unsigned int);
void CEGUI__Window_setMargin(void*, void*);
bool CEGUI__Window_isZOrderingEnabled(void*);
void* CEGUI__Window_getLookNFeel(void*);
void CEGUI__Window_setPosition(void*, void*);
float CEGUI__Window_getAutoRepeatRate(void*);
bool CEGUI__Window_isChild0(void*, void*);
bool CEGUI__Window_isChild1(void*, unsigned int);
bool CEGUI__Window_isChild2(void*, void*);
bool CEGUI__Window_isActive(void*);
void CEGUI__Window_setAlwaysOnTop(void*, bool);
void CEGUI__Window_banPropertyFromXML0(void*, void*);
void CEGUI__Window_banPropertyFromXML1(void*, void*);
void* CEGUI__Window_getTooltip(void*);
bool CEGUI__Window_isMouseInputPropagationEnabled(void*);
bool CEGUI__Window_isAncestor0(void*, void*);
bool CEGUI__Window_isAncestor1(void*, unsigned int);
bool CEGUI__Window_isAncestor2(void*, void*);
void* CEGUI__Window_getInnerRectClipper(void*);
float CEGUI__Window_getParentPixelWidth(void*);
bool CEGUI__Window_isPropertyBannedFromXML0(void*, void*);
bool CEGUI__Window_isPropertyBannedFromXML1(void*, void*);
bool CEGUI__Window_isVisible(void*, bool);
bool CEGUI__Window_isCapturedByChild(void*);
bool CEGUI__Window_isHit(void*, void*, bool);
void* CEGUI__Window_getWindowRenderer(void*);
void* CEGUI__Window_getRootWindow0(void*);
void* CEGUI__Window_getRootWindow1(void*);
void CEGUI__Window_invalidate0(void*);
void CEGUI__Window_invalidate1(void*, bool);
void CEGUI__Window_setTooltip(void*, void*);
void CEGUI__Window_setMouseAutoRepeatEnabled(void*, bool);
void CEGUI__Window_render(void*);
void* CEGUI__Window_getUnclippedRect(void*, bool);
void* CEGUI__Window_getUnclippedInnerRect(void*);
void* CEGUI__Window_getText(void*);
void CEGUI__Window_setTooltipType(void*, void*);
void* CEGUI__Window_getWidth(void*);
unsigned int CEGUI__Window_getUpdateMode(void*);
void* CEGUI__Window_getRotation(void*);
float CEGUI__Window_getParentPixelHeight(void*);
void CEGUI__Window_setWidth(void*, void*);
void CEGUI__Window_setTooltipText(void*, void*);
void CEGUI__Window_notifyScreenAreaChanged(void*, bool);
void CEGUI__Window_setCustomRenderedStringParser(void*, void*);
void* CEGUI__Window_getGeometryBuffer(void*);
void CEGUI__Window_setInheritsAlpha(void*, bool);
void CEGUI__Window_setMouseInputPropagationEnabled(void*, bool);
void* CEGUI__Window_getArea(void*);
bool CEGUI__Window_isDisabled(void*, bool);
void* CEGUI__Window_getUnclippedOuterRect(void*);
void CEGUI__Window_setDragDropTarget(void*, bool);
void* CEGUI__Window_getTextVisual(void*);
void* CEGUI__Window_getChild0(void*, void*);
void* CEGUI__Window_getChild1(void*, unsigned int);
void CEGUI__Window_setUsingAutoRenderingSurface(void*, bool);
bool CEGUI__Window_isUsingAutoRenderingSurface(void*);
void CEGUI__Window_setRiseOnClickEnabled(void*, bool);
void CEGUI__Window_setEnabled(void*, bool);
void* CEGUI__Window_getTargetRenderingSurface(void*);
void* CEGUI__Window_getChildWindowContentArea(void*, bool);
bool CEGUI__Window_isDestroyedByParent(void*);
void* CEGUI__Window_getType(void*);
bool CEGUI__Window_distributesCapturedInputs(void*);
void* CEGUI__Window_getCaptureWindow(void*);
void* CEGUI__Window_getHitTestRect(void*);
unsigned int CEGUI__Window_getVerticalAlignment(void*);
void* CEGUI__Window_getPosition(void*);
void* CEGUI__Window_getOuterRectClipper(void*);
bool CEGUI__Window_isClippedByParent(void*);
void* CEGUI__Window_getParent(void*);
bool CEGUI__Window_isRiseOnClickEnabled(void*);
void* CEGUI__Window_getTargetChildAtPosition(void*, void*, bool);
void CEGUI__Window_setInheritsTooltipText(void*, bool);
void CEGUI__Window_setUpdateMode(void*, unsigned int);
void* CEGUI__Window_getMinSize(void*);
void CEGUI__Window_setZOrderingEnabled(void*, bool);
void CEGUI__Window_getRenderingContext_impl(void*, void*);
void* CEGUI__Window_getRenderedStringParser(void*);
void CEGUI__Window_setVisible(void*, bool);
void CEGUI__Window_rename(void*, void*);
void CEGUI__Window_unbanPropertyFromXML0(void*, void*);
void CEGUI__Window_unbanPropertyFromXML1(void*, void*);
void CEGUI__Window_moveBehind(void*, void*);
void* CEGUI__Window_getXPosition(void*);
void* CEGUI__Window_getPixelSize(void*);
unsigned int CEGUI__Window_getID(void*);
bool CEGUI__Window_inheritsTooltipText(void*);
void CEGUI__Window_enable(void*);
void CEGUI__Window_beginInitialisation(void*);
void* CEGUI__Window_getFont(void*, bool);
float CEGUI__Window_getAutoRepeatDelay(void*);
bool CEGUI__Window_isChildRecursive(void*, unsigned int);
void CEGUI__Window_setRestoreCapture(void*, bool);
unsigned int CEGUI__Window_getHorizontalAlignment(void*);
void CEGUI__Window_setDistributesCapturedInputs(void*, bool);
void CEGUI__Window_setAutoRepeatDelay(void*, float);
void* CEGUI__Window_getHeight(void*);
bool CEGUI__Window_isMousePassThroughEnabled(void*);
void CEGUI__Window_setFalagardType(void*, void*, void*);
void CEGUI__Window_setAlpha(void*, float);
void CEGUI__Window_endInitialisation(void*);
unsigned int CEGUI__Window_getChildCount(void*);
void CEGUI__Window_writeXMLToStream(void*, void*);
void CEGUI__Window_destroy(void*);
void* CEGUI__Window_getTooltipText(void*);
void CEGUI__Window_setMaxSize(void*, void*);
void CEGUI__Window_setWantsMultiClickEvents(void*, bool);
void CEGUI__Window_performChildWindowLayout(void*);
void* CEGUI__Window_clone(void*, void*, bool);
void CEGUI__Window_update(void*, float);
void CEGUI__Window_disable(void*);
void CEGUI__Window_setMousePassThroughEnabled(void*, bool);
void CEGUI__Window_removeChildWindow0(void*, void*);
void CEGUI__Window_removeChildWindow1(void*, void*);
void CEGUI__Window_removeChildWindow2(void*, unsigned int);
void CEGUI__Window_setID(void*, unsigned int);
void CEGUI__Window_setHeight(void*, void*);
void CEGUI__Window_setUserData(void*, void*);
bool CEGUI__Window_isUserStringDefined(void*, void*);
void CEGUI__Window_invalidateRenderingSurface(void*);
void CEGUI__Window_setText(void*, void*);
bool CEGUI__Window_captureInput(void*);
void CEGUI__Window_clonePropertiesTo(void*, void*);
void* CEGUI__Window_getParentPixelSize(void*);
void CEGUI__Window_setClippedByParent(void*, bool);
void CEGUI__Window_moveToFront(void*);
void CEGUI__Window_setFont0(void*, void*);
void CEGUI__Window_setFont1(void*, void*);
bool CEGUI__Window_isCapturedByAncestor(void*);
void* CEGUI__Window_getTooltipType(void*);

//
// Begin class 'CEGUI::Tree'
//
void* CEGUI__Tree__Create(void*, void*);
void CEGUI__Tree__Destroy(void*);
void* CEGUI__Tree_getFirstSelectedItem(void*);
void* CEGUI__Tree_getLastSelectedItem(void*);
void* CEGUI__Tree_findNextItemWithText(void*, void*, void*);
void* CEGUI__Tree_getHorzScrollbar(void*);
bool CEGUI__Tree_isItemTooltipsEnabled(void*);
void* CEGUI__Tree_findNextItemWithID(void*, unsigned int, void*);
bool CEGUI__Tree_isMultiselectEnabled(void*);
void CEGUI__Tree_setItemSelectState0(void*, void*, bool);
void CEGUI__Tree_setItemSelectState1(void*, unsigned int, bool);
unsigned int CEGUI__Tree_getItemCount(void*);
unsigned int CEGUI__Tree_getSelectedCount(void*);
void CEGUI__Tree_doTreeRender(void*);
void CEGUI__Tree_clearAllSelections(void*);
void CEGUI__Tree_resetList(void*);
void CEGUI__Tree_setShowHorzScrollbar(void*, bool);
bool CEGUI__Tree_isSortEnabled(void*);
void CEGUI__Tree_setMultiselectEnabled(void*, bool);
void CEGUI__Tree_doScrollbars(void*);
void CEGUI__Tree_initialise(void*);
bool CEGUI__Tree_isTreeItemInList(void*, void*);
bool CEGUI__Tree_isVertScrollbarAlwaysShown(void*);
void CEGUI__Tree_setLookNFeel(void*, void*);
void CEGUI__Tree_insertItem(void*, void*, void*);
void CEGUI__Tree_addItem(void*, void*);
void* CEGUI__Tree_getVertScrollbar(void*);
void CEGUI__Tree_removeItem(void*, void*);
void* CEGUI__Tree_findFirstItemWithText(void*, void*);
void CEGUI__Tree_setItemRenderArea(void*, void*);
void* CEGUI__Tree_getNextSelected(void*, void*);
void CEGUI__Tree_ensureItemIsVisible(void*, void*);
void CEGUI__Tree_handleUpdatedItemData(void*);
void* CEGUI__Tree_findFirstItemWithID(void*, unsigned int);
void CEGUI__Tree_setSortingEnabled(void*, bool);
void CEGUI__Tree_setItemTooltipsEnabled(void*, bool);
void CEGUI__Tree_setShowVertScrollbar(void*, bool);
bool CEGUI__Tree_isHorzScrollbarAlwaysShown(void*);

//
// Begin class 'CEGUI::Editbox'
//
void* CEGUI__Editbox__Create(void*, void*);
void CEGUI__Editbox__Destroy(void*);
void CEGUI__Editbox_setValidationString(void*, void*);
bool CEGUI__Editbox_isTextMasked(void*);
void* CEGUI__Editbox_getValidationString(void*);
unsigned int CEGUI__Editbox_getMaxTextLength(void*);
bool CEGUI__Editbox_hasInputFocus(void*);
bool CEGUI__Editbox_isReadOnly(void*);
unsigned int CEGUI__Editbox_getSelectionEndIndex(void*);
unsigned int CEGUI__Editbox_getSelectionStartIndex(void*);
unsigned int CEGUI__Editbox_getCaratIndex(void*);
void CEGUI__Editbox_setCaratIndex(void*, unsigned int);
unsigned int CEGUI__Editbox_getMaskCodePoint(void*);
void CEGUI__Editbox_setTextMasked(void*, bool);
void CEGUI__Editbox_setMaxTextLength(void*, unsigned int);
void CEGUI__Editbox_setSelection(void*, unsigned int, unsigned int);
unsigned int CEGUI__Editbox_getSelectionLength(void*);
void CEGUI__Editbox_setReadOnly(void*, bool);
bool CEGUI__Editbox_isTextValid(void*);
void CEGUI__Editbox_setMaskCodePoint(void*, unsigned int);

//
// Begin class 'CEGUI::ListHeaderWindowRenderer'
//
void CEGUI__ListHeaderWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::TabButton'
//
void* CEGUI__TabButton__Create(void*, void*);
void CEGUI__TabButton__Destroy(void*);
void* CEGUI__TabButton_getTargetWindow(void*);
void CEGUI__TabButton_setSelected(void*, bool);
void CEGUI__TabButton_setTargetWindow(void*, void*);
bool CEGUI__TabButton_isSelected(void*);

//
// Begin class 'CEGUI::WidgetLookManager'
//
void* CEGUI__WidgetLookManager__Create();
void CEGUI__WidgetLookManager__Destroy(void*);
void* CEGUI__WidgetLookManager_getSingletonPtr(void*);
void CEGUI__WidgetLookManager_setDefaultResourceGroup(void*, void*);
void CEGUI__WidgetLookManager_addWidgetLook(void*, void*);
void* CEGUI__WidgetLookManager_getDefaultResourceGroup(void*);
void* CEGUI__WidgetLookManager_getSingleton(void*);
void CEGUI__WidgetLookManager_parseLookNFeelSpecification(void*, void*, void*);
void CEGUI__WidgetLookManager_eraseWidgetLook(void*, void*);
void* CEGUI__WidgetLookManager_getWidgetLook(void*, void*);
bool CEGUI__WidgetLookManager_isWidgetLookAvailable(void*, void*);

//
// Begin class 'CEGUI::RenderedStringComponent'
//
void CEGUI__RenderedStringComponent__Destroy(void*);
void CEGUI__RenderedStringComponent_setLeftPadding(void*, float);
unsigned int CEGUI__RenderedStringComponent_getVerticalFormatting(void*);
float CEGUI__RenderedStringComponent_getLeftPadding(void*);
void CEGUI__RenderedStringComponent_setBottomPadding(void*, float);
void* CEGUI__RenderedStringComponent_getPadding(void*);
bool CEGUI__RenderedStringComponent_getAspectLock(void*);
float CEGUI__RenderedStringComponent_getRightPadding(void*);
void CEGUI__RenderedStringComponent_setVerticalFormatting(void*, unsigned int);
void CEGUI__RenderedStringComponent_setTopPadding(void*, float);
void CEGUI__RenderedStringComponent_setAspectLock(void*, bool);
void CEGUI__RenderedStringComponent_setRightPadding(void*, float);
float CEGUI__RenderedStringComponent_getTopPadding(void*);
float CEGUI__RenderedStringComponent_getBottomPadding(void*);
void CEGUI__RenderedStringComponent_setPadding(void*, void*);

//
// Begin class 'CEGUI::WidgetLookFeel'
//
void* CEGUI__WidgetLookFeel__Create0(void*);
void* CEGUI__WidgetLookFeel__Create1();
void CEGUI__WidgetLookFeel__Destroy(void*);
void CEGUI__WidgetLookFeel_addPropertyLinkDefinition(void*, void*);
void CEGUI__WidgetLookFeel_addNamedArea(void*, void*);
void CEGUI__WidgetLookFeel_cleanUpWidget(void*, void*);
void CEGUI__WidgetLookFeel_clearNamedAreas(void*);
bool CEGUI__WidgetLookFeel_isNamedAreaDefined(void*, void*);
void* CEGUI__WidgetLookFeel_getNamedArea(void*, void*);
void CEGUI__WidgetLookFeel_clearPropertyLinkDefinitions(void*);
void* CEGUI__WidgetLookFeel_getName(void*);
void CEGUI__WidgetLookFeel_addAnimationName(void*, void*);
void CEGUI__WidgetLookFeel_writeXMLToStream(void*, void*);
void CEGUI__WidgetLookFeel_initialiseWidget(void*, void*);
void CEGUI__WidgetLookFeel_addStateSpecification(void*, void*);
bool CEGUI__WidgetLookFeel_isStateImageryPresent(void*, void*);
void CEGUI__WidgetLookFeel_renameChildren(void*, void*, void*);
void CEGUI__WidgetLookFeel_addImagerySection(void*, void*);
void CEGUI__WidgetLookFeel_clearImagerySections(void*);
void CEGUI__WidgetLookFeel_layoutChildWidgets(void*, void*);
void CEGUI__WidgetLookFeel_clearPropertyInitialisers(void*);
void* CEGUI__WidgetLookFeel_findWidgetComponent(void*, void*);
void CEGUI__WidgetLookFeel_clearStateSpecifications(void*);
void CEGUI__WidgetLookFeel_clearPropertyDefinitions(void*);
void CEGUI__WidgetLookFeel_clearWidgetComponents(void*);
void* CEGUI__WidgetLookFeel_findPropertyInitialiser(void*, void*);
void* CEGUI__WidgetLookFeel_getImagerySection(void*, void*);
void CEGUI__WidgetLookFeel_addWidgetComponent(void*, void*);
void CEGUI__WidgetLookFeel_addPropertyInitialiser(void*, void*);
void* CEGUI__WidgetLookFeel_getStateImagery(void*, void*);
void CEGUI__WidgetLookFeel_addPropertyDefinition(void*, void*);

//
// Begin class 'CEGUI::CentredRenderedString'
//
void CEGUI__CentredRenderedString__Destroy(void*);
void CEGUI__CentredRenderedString_draw(void*, void*, void*, void*, void*);
float CEGUI__CentredRenderedString_getHorizontalExtent(void*);
float CEGUI__CentredRenderedString_getVerticalExtent(void*);
unsigned int CEGUI__CentredRenderedString_getFormattedLineCount(void*);
void CEGUI__CentredRenderedString_format(void*, void*);

//
// Begin class 'CEGUI::DynamicModule'
//
void* CEGUI__DynamicModule__Create(void*);
void CEGUI__DynamicModule__Destroy(void*);
void* CEGUI__DynamicModule_getModuleName(void*);
void* CEGUI__DynamicModule_getSymbolAddress(void*, void*);

//
// Begin class 'CEGUI::RenderTarget'
//
void CEGUI__RenderTarget__Destroy(void*);

//
// Begin class 'CEGUI::Imageset_xmlHandler'
//
void* CEGUI__Imageset_xmlHandler__Create(void*, void*);
void CEGUI__Imageset_xmlHandler__Destroy(void*);
void CEGUI__Imageset_xmlHandler_elementStart(void*, void*, void*);
void CEGUI__Imageset_xmlHandler_elementEnd(void*, void*);
void* CEGUI__Imageset_xmlHandler_getObject(void*);
void* CEGUI__Imageset_xmlHandler_getObjectName(void*);

//
// Begin class 'CEGUI::RenderQueue'
//
void CEGUI__RenderQueue__Destroy(void*);
void CEGUI__RenderQueue_reset(void*);
void CEGUI__RenderQueue_draw(void*);
void CEGUI__RenderQueue_addGeometryBuffer(void*, void*);
void CEGUI__RenderQueue_removeGeometryBuffer(void*, void*);

//
// Begin class 'CEGUI::MenuBase'
//
void CEGUI__MenuBase__Destroy(void*);
float CEGUI__MenuBase_getItemSpacing(void*);
void CEGUI__MenuBase_changePopupMenuItem(void*, void*);
bool CEGUI__MenuBase_isMultiplePopupsAllowed(void*);
void* CEGUI__MenuBase_getPopupMenuItem(void*);
void CEGUI__MenuBase_setAllowMultiplePopups(void*, bool);
void CEGUI__MenuBase_setItemSpacing(void*, float);

//
// Begin class 'CEGUI::MultiLineEditboxWindowRenderer'
//
void CEGUI__MultiLineEditboxWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::IntInterpolator'
//
void CEGUI__IntInterpolator__Destroy(void*);
void* CEGUI__IntInterpolator_getType(void*);
void* CEGUI__IntInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__IntInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__IntInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::BasicRenderedStringParser'
//
void CEGUI__BasicRenderedStringParser__Destroy(void*);
void CEGUI__BasicRenderedStringParser_setInitialColours(void*, void*);
void* CEGUI__BasicRenderedStringParser_parse(void*, void*, void*, void*);
void CEGUI__BasicRenderedStringParser_setInitialFontName(void*, void*);
void* CEGUI__BasicRenderedStringParser_getInitialColours(void*);
void* CEGUI__BasicRenderedStringParser_getInitialFontName(void*);

//
// Begin class 'CEGUI::RectInterpolator'
//
void CEGUI__RectInterpolator__Destroy(void*);
void* CEGUI__RectInterpolator_getType(void*);
void* CEGUI__RectInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__RectInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__RectInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::ResourceEventSet'
//
void CEGUI__ResourceEventSet__Destroy(void*);

//
// Begin class 'CEGUI::TextUtils'
//
unsigned int CEGUI__TextUtils_getNextWordStartIdx(void*, void*, unsigned int);
unsigned int CEGUI__TextUtils_getWordStartIdx(void*, void*, unsigned int);
void* CEGUI__TextUtils_getNextWord(void*, void*, unsigned int, void*);
void CEGUI__TextUtils_trimTrailingChars(void*, void*, void*);
void CEGUI__TextUtils_trimLeadingChars(void*, void*, void*);

//
// Begin class 'CEGUI::RenderedStringWidgetComponent'
//
void CEGUI__RenderedStringWidgetComponent__Destroy(void*);
void CEGUI__RenderedStringWidgetComponent_draw(void*, void*, void*, void*, void*, float, float);
void* CEGUI__RenderedStringWidgetComponent_clone(void*);
void* CEGUI__RenderedStringWidgetComponent_getPixelSize(void*);
bool CEGUI__RenderedStringWidgetComponent_canSplit(void*);
void* CEGUI__RenderedStringWidgetComponent_split(void*, float, bool);
void* CEGUI__RenderedStringWidgetComponent_getWindow(void*);
unsigned int CEGUI__RenderedStringWidgetComponent_getSpaceCount(void*);
void CEGUI__RenderedStringWidgetComponent_setWindow0(void*, void*);
void CEGUI__RenderedStringWidgetComponent_setWindow1(void*, void*);

//
// Begin class 'CEGUI::UintInterpolator'
//
void CEGUI__UintInterpolator__Destroy(void*);
void* CEGUI__UintInterpolator_getType(void*);
void* CEGUI__UintInterpolator_interpolateAbsolute(void*, void*, void*, float);
void* CEGUI__UintInterpolator_interpolateRelative(void*, void*, void*, void*, float);
void* CEGUI__UintInterpolator_interpolateRelativeMultiply(void*, void*, void*, void*, float);

//
// Begin class 'CEGUI::DefaultRenderedStringParser'
//
void CEGUI__DefaultRenderedStringParser__Destroy(void*);
void* CEGUI__DefaultRenderedStringParser_parse(void*, void*, void*, void*);

//
// Begin class 'CEGUI::WidgetDim'
//
void CEGUI__WidgetDim__Destroy(void*);
void CEGUI__WidgetDim_setWidgetName(void*, void*);
void CEGUI__WidgetDim_setSourceDimension(void*, unsigned int);

//
// Begin class 'CEGUI::URect'
//
void* CEGUI__URect__Create0();
void* CEGUI__URect__Create1(void*, void*);
void* CEGUI__URect__Create2(void*, void*, void*, void*);
void* CEGUI__URect__Create3(void*);
void CEGUI__URect__Destroy(void*);
void CEGUI__URect_setHeight(void*, void*);
void* CEGUI__URect_getWidth(void*);
void* CEGUI__URect_asRelative(void*, void*);
void CEGUI__URect_setWidth(void*, void*);
void* CEGUI__URect_getHeight(void*);
void* CEGUI__URect_asAbsolute(void*, void*);
void* CEGUI__URect_getSize(void*);
void CEGUI__URect_offset(void*, void*);
void CEGUI__URect_setPosition(void*, void*);
void CEGUI__URect_setSize(void*, void*);
void* CEGUI__URect_getPosition(void*);

//
// Begin class 'CEGUI::EventArgs'
//
void* CEGUI__EventArgs__Create();
void CEGUI__EventArgs__Destroy(void*);

//
// Begin class 'CEGUI::KeyFrame'
//
void* CEGUI__KeyFrame__Create(void*, float);
void CEGUI__KeyFrame__Destroy(void*);
void CEGUI__KeyFrame_setValue(void*, void*);
void* CEGUI__KeyFrame_getParent(void*);
void CEGUI__KeyFrame_savePropertyValue(void*, void*);
void CEGUI__KeyFrame_notifyPositionChanged(void*, float);
void* CEGUI__KeyFrame_getValue(void*);
void CEGUI__KeyFrame_setProgression(void*, unsigned int);
void* CEGUI__KeyFrame_getValueForAnimation(void*, void*);
float CEGUI__KeyFrame_alterInterpolationPosition(void*, float);
void CEGUI__KeyFrame_setSourceProperty(void*, void*);
void CEGUI__KeyFrame_moveToPosition(void*, float);
void* CEGUI__KeyFrame_getSourceProperty(void*);
float CEGUI__KeyFrame_getPosition(void*);
unsigned int CEGUI__KeyFrame_getProgression(void*);

//
// Begin class 'CEGUI::FrameWindow'
//
void* CEGUI__FrameWindow__Create(void*, void*);
void CEGUI__FrameWindow__Destroy(void*);
void CEGUI__FrameWindow_setEWSizingCursorImage0(void*, void*);
void CEGUI__FrameWindow_setEWSizingCursorImage1(void*, void*, void*);
float CEGUI__FrameWindow_getSizingBorderThickness(void*);
void CEGUI__FrameWindow_setSizingBorderThickness(void*, float);
void CEGUI__FrameWindow_setNWSESizingCursorImage0(void*, void*);
void CEGUI__FrameWindow_setNWSESizingCursorImage1(void*, void*, void*);
void* CEGUI__FrameWindow_getEWSizingCursorImage(void*);
void CEGUI__FrameWindow_initialiseComponents(void*);
void CEGUI__FrameWindow_setNSSizingCursorImage0(void*, void*);
void CEGUI__FrameWindow_setNSSizingCursorImage1(void*, void*, void*);
bool CEGUI__FrameWindow_isFrameEnabled(void*);
void CEGUI__FrameWindow_setRollupEnabled(void*, bool);
void CEGUI__FrameWindow_setNESWSizingCursorImage0(void*, void*);
void CEGUI__FrameWindow_setNESWSizingCursorImage1(void*, void*, void*);
void* CEGUI__FrameWindow_getTitlebar(void*);
bool CEGUI__FrameWindow_isTitleBarEnabled(void*);
void* CEGUI__FrameWindow_getCloseButton(void*);
void CEGUI__FrameWindow_setTitleBarEnabled(void*, bool);
bool CEGUI__FrameWindow_isRolledup(void*);
void CEGUI__FrameWindow_toggleRollup(void*);
void* CEGUI__FrameWindow_getNSSizingCursorImage(void*);
void CEGUI__FrameWindow_setDragMovingEnabled(void*, bool);
void CEGUI__FrameWindow_offsetPixelPosition(void*, void*);
bool CEGUI__FrameWindow_isCloseButtonEnabled(void*);
void* CEGUI__FrameWindow_getNWSESizingCursorImage(void*);
void CEGUI__FrameWindow_setFrameEnabled(void*, bool);
bool CEGUI__FrameWindow_isRollupEnabled(void*);
bool CEGUI__FrameWindow_isSizingEnabled(void*);
void CEGUI__FrameWindow_setSizingEnabled(void*, bool);
bool CEGUI__FrameWindow_isDragMovingEnabled(void*);
bool CEGUI__FrameWindow_isHit(void*, void*, bool);
void* CEGUI__FrameWindow_getNESWSizingCursorImage(void*);
void CEGUI__FrameWindow_setCloseButtonEnabled(void*, bool);

//
// Begin class 'CEGUI::AnimationManager'
//
void* CEGUI__AnimationManager__Create();
void CEGUI__AnimationManager__Destroy(void*);
void* CEGUI__AnimationManager_getAnimation(void*, void*);
void CEGUI__AnimationManager_removeInterpolator(void*, void*);
void* CEGUI__AnimationManager_createAnimation(void*, void*);
void CEGUI__AnimationManager_setDefaultResourceGroup(void*, void*);
void* CEGUI__AnimationManager_instantiateAnimation0(void*, void*);
void* CEGUI__AnimationManager_instantiateAnimation1(void*, void*);
void* CEGUI__AnimationManager_getDefaultResourceGroup(void*);
void CEGUI__AnimationManager_stepInstances(void*, float);
void* CEGUI__AnimationManager_getInterpolator(void*, void*);
void CEGUI__AnimationManager_addInterpolator(void*, void*);
void CEGUI__AnimationManager_destroyAllInstancesOfAnimation(void*, void*);
void CEGUI__AnimationManager_destroyAnimationInstance(void*, void*);
void CEGUI__AnimationManager_destroyAnimation0(void*, void*);
void CEGUI__AnimationManager_destroyAnimation1(void*, void*);
unsigned int CEGUI__AnimationManager_getNumAnimations(void*);
void* CEGUI__AnimationManager_getAnimationInstanceAtIdx(void*, unsigned int);
void* CEGUI__AnimationManager_getAnimationAtIdx(void*, unsigned int);
void CEGUI__AnimationManager_loadAnimationsFromXML(void*, void*, void*);
unsigned int CEGUI__AnimationManager_getNumAnimationInstances(void*);

//
// Begin class 'CEGUI::Rect'
//
void* CEGUI__Rect__Create0();
void* CEGUI__Rect__Create1(float, float, float, float);
void* CEGUI__Rect__Create2(void*, void*);
void* CEGUI__Rect__Create3(void*);
void CEGUI__Rect__Destroy(void*);
void CEGUI__Rect_setHeight(void*, float);
void* CEGUI__Rect_getSize(void*);
void* CEGUI__Rect_constrainSizeMax(void*, void*);
void CEGUI__Rect_setSize(void*, void*);
bool CEGUI__Rect_isPointInRect(void*, void*);
float CEGUI__Rect_getHeight(void*);
void* CEGUI__Rect_getIntersection(void*, void*);
float CEGUI__Rect_getWidth(void*);
void* CEGUI__Rect_constrainSize(void*, void*, void*);
void* CEGUI__Rect_offset(void*, void*);
void* CEGUI__Rect_constrainSizeMin(void*, void*);
void CEGUI__Rect_setPosition(void*, void*);
void CEGUI__Rect_setWidth(void*, float);
void* CEGUI__Rect_getPosition(void*);

//
// Begin class 'CEGUI::MouseCursorEventArgs'
//
void* CEGUI__MouseCursorEventArgs__Create(void*);
void CEGUI__MouseCursorEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::UpdateEventArgs'
//
void* CEGUI__UpdateEventArgs__Create(void*, float);
void CEGUI__UpdateEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::Texture'
//
void CEGUI__Texture__Destroy(void*);

//
// Begin class 'CEGUI::LayoutContainer'
//
void CEGUI__LayoutContainer__Destroy(void*);
void CEGUI__LayoutContainer_layoutIfNecessary(void*);
void CEGUI__LayoutContainer_update(void*, float);
void CEGUI__LayoutContainer_markNeedsLayouting(void*);
void* CEGUI__LayoutContainer_getUnclippedInnerRect_impl(void*);
bool CEGUI__LayoutContainer_needsLayouting(void*);

//
// Begin class 'CEGUI::ScriptFunctor'
//
void* CEGUI__ScriptFunctor__Create0(void*);
void* CEGUI__ScriptFunctor__Create1(void*);
void CEGUI__ScriptFunctor__Destroy(void*);

//
// Begin class 'CEGUI::MultiLineEditbox::LineInfo'
//
void CEGUI__MultiLineEditbox__LineInfo__Destroy(void*);

//
// Begin class 'CEGUI::System'
//
bool CEGUI__System_injectMouseMove(void*, float, float);
bool CEGUI__System_injectKeyUp(void*, unsigned int);
void CEGUI__System_setModalTarget(void*, void*);
void CEGUI__System_invalidateAllCachedRendering(void*);
bool CEGUI__System_injectMouseButtonDown(void*, unsigned int);
int CEGUI__System_executeScriptGlobal(void*, void*);
void CEGUI__System_setXMLParser0(void*, void*);
void CEGUI__System_setXMLParser1(void*, void*);
void CEGUI__System_setMultiClickToleranceAreaSize(void*, void*);
bool CEGUI__System_injectKeyDown(void*, unsigned int);
void* CEGUI__System_getModalTarget(void*);
void* CEGUI__System_getDefaultCustomRenderedStringParser(void*);
unsigned int CEGUI__System_getSystemKeys(void*);
double CEGUI__System_getSingleClickTimeout(void*);
void CEGUI__System_setDefaultImageCodecName(void*, void*);
bool CEGUI__System_injectMousePosition(void*, float, float);
void CEGUI__System_setDefaultTooltip0(void*, void*);
void CEGUI__System_setDefaultTooltip1(void*, void*);
void CEGUI__System_setMouseMoveScaling(void*, float);
void CEGUI__System_executeScriptString(void*, void*);
void* CEGUI__System_getImageCodec(void*);
void* CEGUI__System_getDefaultFont(void*);
void CEGUI__System_setDefaultFont0(void*, void*);
void CEGUI__System_setDefaultFont1(void*, void*);
bool CEGUI__System_isRedrawRequested(void*);
void* CEGUI__System_getScriptingModule(void*);
bool CEGUI__System_updateWindowContainingMouse(void*);
void* CEGUI__System_getWindowContainingMouse(void*);
void CEGUI__System_setMultiClickTimeout(void*, double);
void CEGUI__System_setDefaultCustomRenderedStringParser(void*, void*);
void* CEGUI__System_getMultiClickToleranceAreaSize(void*);
bool CEGUI__System_injectMouseButtonDoubleClick(void*, unsigned int);
void* CEGUI__System_getXMLParser(void*);
void CEGUI__System_executeScriptFile(void*, void*, void*);
bool CEGUI__System_injectMouseLeaves(void*);
void* CEGUI__System_getDefaultXMLParserName(void*);
void CEGUI__System_renderGUI(void*);
bool CEGUI__System_injectChar(void*, unsigned int);
void* CEGUI__System_getDefaultMouseCursor(void*);
void* CEGUI__System_getResourceProvider(void*);
bool CEGUI__System_injectMouseButtonTripleClick(void*, unsigned int);
bool CEGUI__System_injectMouseButtonClick(void*, unsigned int);
void* CEGUI__System_create(void*, void*, void*, void*, void*, void*, void*, void*);
void CEGUI__System_setDefaultMouseCursor0(void*, void*);
void CEGUI__System_setDefaultMouseCursor1(void*, unsigned int);
void CEGUI__System_setDefaultMouseCursor2(void*, void*, void*);
void* CEGUI__System_getDefaultTooltip(void*);
void* CEGUI__System_setGUISheet(void*, void*);
void CEGUI__System_signalRedraw(void*);
void* CEGUI__System_getDefaultImageCodecName(void*);
void CEGUI__System_notifyDisplaySizeChanged(void*, void*);
void CEGUI__System_setDefaultXMLParserName(void*, void*);
void* CEGUI__System_getSingleton(void*);
bool CEGUI__System_injectMouseWheelChange(void*, float);
void CEGUI__System_setMouseClickEventGenerationEnabled(void*, bool);
void CEGUI__System_setImageCodec0(void*, void*);
void CEGUI__System_setImageCodec1(void*, void*);
bool CEGUI__System_isMouseClickEventGenerationEnabled(void*);
float CEGUI__System_getMouseMoveScaling(void*);
void* CEGUI__System_getGUISheet(void*);
bool CEGUI__System_injectMouseButtonUp(void*, unsigned int);
void CEGUI__System_setScriptingModule(void*, void*);
double CEGUI__System_getMultiClickTimeout(void*);
void CEGUI__System_setSingleClickTimeout(void*, double);
void* CEGUI__System_getRenderer(void*);
void CEGUI__System_destroy(void*);
bool CEGUI__System_injectTimePulse(void*, float);
void* CEGUI__System_getSingletonPtr(void*);
void CEGUI__System_notifyWindowDestroyed(void*, void*);

//
// Begin class 'CEGUI::UVector2'
//
void* CEGUI__UVector2__Create0();
void* CEGUI__UVector2__Create1(void*, void*);
void* CEGUI__UVector2__Create2(void*);
void CEGUI__UVector2__Destroy(void*);
void* CEGUI__UVector2_asRelative(void*, void*);
void* CEGUI__UVector2_asAbsolute(void*, void*);

//
// Begin class 'CEGUI::SliderWindowRenderer'
//
void CEGUI__SliderWindowRenderer__Destroy(void*);

//
// Begin class 'CEGUI::ImagerySection'
//
void* CEGUI__ImagerySection__Create0();
void* CEGUI__ImagerySection__Create1(void*);
void CEGUI__ImagerySection__Destroy(void*);
void* CEGUI__ImagerySection_getBoundingRect0(void*, void*);
void* CEGUI__ImagerySection_getBoundingRect1(void*, void*, void*);
void CEGUI__ImagerySection_addImageryComponent(void*, void*);
void CEGUI__ImagerySection_render0(void*, void*, void*, void*, bool);
void CEGUI__ImagerySection_render1(void*, void*, void*, void*, void*, bool);
void CEGUI__ImagerySection_clearFrameComponents(void*);
void CEGUI__ImagerySection_addFrameComponent(void*, void*);
void* CEGUI__ImagerySection_getMasterColours(void*);
void CEGUI__ImagerySection_addTextComponent(void*, void*);
void CEGUI__ImagerySection_clearImageryComponents(void*);
void CEGUI__ImagerySection_clearTextComponents(void*);
void CEGUI__ImagerySection_writeXMLToStream(void*, void*);
void CEGUI__ImagerySection_setMasterColours(void*, void*);
void CEGUI__ImagerySection_setMasterColoursPropertySource(void*, void*);
void CEGUI__ImagerySection_setMasterColoursPropertyIsColourRect(void*, bool);
void* CEGUI__ImagerySection_getName(void*);

//
// Begin class 'CEGUI::RenderQueueEventArgs'
//
void* CEGUI__RenderQueueEventArgs__Create(unsigned int);
void CEGUI__RenderQueueEventArgs__Destroy(void*);

//
// Begin class 'CEGUI::XMLParser'
//
void CEGUI__XMLParser__Destroy(void*);
void* CEGUI__XMLParser_getIdentifierString(void*);
bool CEGUI__XMLParser_initialise(void*);
void CEGUI__XMLParser_cleanup(void*);

//
// Begin class 'CEGUI::ResourceProvider'
//
void CEGUI__ResourceProvider__Destroy(void*);
void* CEGUI__ResourceProvider_getDefaultResourceGroup(void*);
void CEGUI__ResourceProvider_unloadRawDataContainer(void*, void*);
void CEGUI__ResourceProvider_setDefaultResourceGroup(void*, void*);

//
// Begin class 'CEGUI::UnifiedDim'
//
void CEGUI__UnifiedDim__Destroy(void*);

//
// Begin class 'CEGUI::ComboDropList'
//
void* CEGUI__ComboDropList__Create(void*, void*);
void CEGUI__ComboDropList__Destroy(void*);
bool CEGUI__ComboDropList_isArmed(void*);
void CEGUI__ComboDropList_setArmed(void*, bool);
void CEGUI__ComboDropList_initialiseComponents(void*);
void CEGUI__ComboDropList_setAutoArmEnabled(void*, bool);
bool CEGUI__ComboDropList_isAutoArmEnabled(void*);

//
// Begin class 'CEGUI::GUISheet'
//
void* CEGUI__GUISheet__Create(void*, void*);
void CEGUI__GUISheet__Destroy(void*);

//
// Begin class 'CEGUI::AbsoluteDim'
//
void CEGUI__AbsoluteDim__Destroy(void*);
void CEGUI__AbsoluteDim_setValue(void*, float);

//
// Begin class 'CEGUI::Vector2'
//
void* CEGUI__Vector2__Create0();
void* CEGUI__Vector2__Create1(float, float);
void* CEGUI__Vector2__Create2(void*);
void CEGUI__Vector2__Destroy(void*);
void* CEGUI__Vector2_asSize(void*);

//
// Begin class 'CEGUI::WindowFactoryManager::AliasTargetStack'
//
void* CEGUI__WindowFactoryManager__AliasTargetStack__Create();
void CEGUI__WindowFactoryManager__AliasTargetStack__Destroy(void*);
unsigned int CEGUI__WindowFactoryManager__AliasTargetStack_getStackedTargetCount(void*);
void* CEGUI__WindowFactoryManager__AliasTargetStack_getActiveTarget(void*);

//
// Begin class 'CEGUI::DefaultResourceProvider'
//
void CEGUI__DefaultResourceProvider__Destroy(void*);
void CEGUI__DefaultResourceProvider_setResourceGroupDirectory(void*, void*, void*);
void CEGUI__DefaultResourceProvider_unloadRawDataContainer(void*, void*);
void* CEGUI__DefaultResourceProvider_getResourceGroupDirectory(void*, void*);
void CEGUI__DefaultResourceProvider_clearResourceGroupDirectory(void*, void*);
void CEGUI__DefaultResourceProvider_loadRawDataContainer(void*, void*, void*, void*);

//
// Begin class 'CEGUI::SpinnerProperties::CurrentValue'
//
void CEGUI__SpinnerProperties__CurrentValue__Destroy(void*);
void CEGUI__SpinnerProperties__CurrentValue_set(void*, void*, void*);
void* CEGUI__SpinnerProperties__CurrentValue_get(void*, void*);

//
// Begin class 'CEGUI::SpinnerProperties::MaximumValue'
//
void CEGUI__SpinnerProperties__MaximumValue__Destroy(void*);
void CEGUI__SpinnerProperties__MaximumValue_set(void*, void*, void*);
void* CEGUI__SpinnerProperties__MaximumValue_get(void*, void*);

//
// Begin class 'CEGUI::SpinnerProperties::MinimumValue'
//
void CEGUI__SpinnerProperties__MinimumValue__Destroy(void*);
void CEGUI__SpinnerProperties__MinimumValue_set(void*, void*, void*);
void* CEGUI__SpinnerProperties__MinimumValue_get(void*, void*);

//
// Begin class 'CEGUI::SpinnerProperties::TextInputMode'
//
void CEGUI__SpinnerProperties__TextInputMode__Destroy(void*);
void CEGUI__SpinnerProperties__TextInputMode_set(void*, void*, void*);
void* CEGUI__SpinnerProperties__TextInputMode_get(void*, void*);

//
// Begin class 'CEGUI::SpinnerProperties::StepSize'
//
void CEGUI__SpinnerProperties__StepSize__Destroy(void*);
void CEGUI__SpinnerProperties__StepSize_set(void*, void*, void*);
void* CEGUI__SpinnerProperties__StepSize_get(void*, void*);

//
// Begin class 'CEGUI::ThumbProperties::HorzFree'
//
void CEGUI__ThumbProperties__HorzFree__Destroy(void*);
void CEGUI__ThumbProperties__HorzFree_set(void*, void*, void*);
void* CEGUI__ThumbProperties__HorzFree_get(void*, void*);

//
// Begin class 'CEGUI::ThumbProperties::HorzRange'
//
void CEGUI__ThumbProperties__HorzRange__Destroy(void*);
void CEGUI__ThumbProperties__HorzRange_set(void*, void*, void*);
void* CEGUI__ThumbProperties__HorzRange_get(void*, void*);

//
// Begin class 'CEGUI::ThumbProperties::VertFree'
//
void CEGUI__ThumbProperties__VertFree__Destroy(void*);
void CEGUI__ThumbProperties__VertFree_set(void*, void*, void*);
void* CEGUI__ThumbProperties__VertFree_get(void*, void*);

//
// Begin class 'CEGUI::ThumbProperties::VertRange'
//
void CEGUI__ThumbProperties__VertRange__Destroy(void*);
void CEGUI__ThumbProperties__VertRange_set(void*, void*, void*);
void* CEGUI__ThumbProperties__VertRange_get(void*, void*);

//
// Begin class 'CEGUI::ThumbProperties::HotTracked'
//
void CEGUI__ThumbProperties__HotTracked__Destroy(void*);
void CEGUI__ThumbProperties__HotTracked_set(void*, void*, void*);
void* CEGUI__ThumbProperties__HotTracked_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertStepSize'
//
void CEGUI__ScrollablePaneProperties__VertStepSize__Destroy(void*);
void CEGUI__ScrollablePaneProperties__VertStepSize_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__VertStepSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::ForceHorzScrollbar'
//
void CEGUI__ScrollablePaneProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__ScrollablePaneProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::ContentPaneAutoSized'
//
void CEGUI__ScrollablePaneProperties__ContentPaneAutoSized__Destroy(void*);
void CEGUI__ScrollablePaneProperties__ContentPaneAutoSized_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__ContentPaneAutoSized_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzScrollPosition'
//
void CEGUI__ScrollablePaneProperties__HorzScrollPosition__Destroy(void*);
void CEGUI__ScrollablePaneProperties__HorzScrollPosition_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__HorzScrollPosition_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertScrollPosition'
//
void CEGUI__ScrollablePaneProperties__VertScrollPosition__Destroy(void*);
void CEGUI__ScrollablePaneProperties__VertScrollPosition_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__VertScrollPosition_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::VertOverlapSize'
//
void CEGUI__ScrollablePaneProperties__VertOverlapSize__Destroy(void*);
void CEGUI__ScrollablePaneProperties__VertOverlapSize_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__VertOverlapSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzOverlapSize'
//
void CEGUI__ScrollablePaneProperties__HorzOverlapSize__Destroy(void*);
void CEGUI__ScrollablePaneProperties__HorzOverlapSize_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__HorzOverlapSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::HorzStepSize'
//
void CEGUI__ScrollablePaneProperties__HorzStepSize__Destroy(void*);
void CEGUI__ScrollablePaneProperties__HorzStepSize_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__HorzStepSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::ContentArea'
//
void CEGUI__ScrollablePaneProperties__ContentArea__Destroy(void*);
void CEGUI__ScrollablePaneProperties__ContentArea_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__ContentArea_get(void*, void*);

//
// Begin class 'CEGUI::ScrollablePaneProperties::ForceVertScrollbar'
//
void CEGUI__ScrollablePaneProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__ScrollablePaneProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__ScrollablePaneProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::PopupMenuProperties::FadeInTime'
//
void CEGUI__PopupMenuProperties__FadeInTime__Destroy(void*);
void CEGUI__PopupMenuProperties__FadeInTime_set(void*, void*, void*);
void* CEGUI__PopupMenuProperties__FadeInTime_get(void*, void*);

//
// Begin class 'CEGUI::PopupMenuProperties::FadeOutTime'
//
void CEGUI__PopupMenuProperties__FadeOutTime__Destroy(void*);
void CEGUI__PopupMenuProperties__FadeOutTime_set(void*, void*, void*);
void* CEGUI__PopupMenuProperties__FadeOutTime_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::ScrollPosition'
//
void CEGUI__ScrollbarProperties__ScrollPosition__Destroy(void*);
void CEGUI__ScrollbarProperties__ScrollPosition_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__ScrollPosition_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::OverlapSize'
//
void CEGUI__ScrollbarProperties__OverlapSize__Destroy(void*);
void CEGUI__ScrollbarProperties__OverlapSize_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__OverlapSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::DocumentSize'
//
void CEGUI__ScrollbarProperties__DocumentSize__Destroy(void*);
void CEGUI__ScrollbarProperties__DocumentSize_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__DocumentSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::StepSize'
//
void CEGUI__ScrollbarProperties__StepSize__Destroy(void*);
void CEGUI__ScrollbarProperties__StepSize_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__StepSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::PageSize'
//
void CEGUI__ScrollbarProperties__PageSize__Destroy(void*);
void CEGUI__ScrollbarProperties__PageSize_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__PageSize_get(void*, void*);

//
// Begin class 'CEGUI::ScrollbarProperties::EndLockEnabled'
//
void CEGUI__ScrollbarProperties__EndLockEnabled__Destroy(void*);
void CEGUI__ScrollbarProperties__EndLockEnabled_set(void*, void*, void*);
void* CEGUI__ScrollbarProperties__EndLockEnabled_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::NominatedSelectionColumnID'
//
void CEGUI__MultiColumnListProperties__NominatedSelectionColumnID__Destroy(void*);
void CEGUI__MultiColumnListProperties__NominatedSelectionColumnID_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__NominatedSelectionColumnID_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::SortDirection'
//
void CEGUI__MultiColumnListProperties__SortDirection__Destroy(void*);
void CEGUI__MultiColumnListProperties__SortDirection_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__SortDirection_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::SortColumnID'
//
void CEGUI__MultiColumnListProperties__SortColumnID__Destroy(void*);
void CEGUI__MultiColumnListProperties__SortColumnID_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__SortColumnID_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnsSizable'
//
void CEGUI__MultiColumnListProperties__ColumnsSizable__Destroy(void*);
void CEGUI__MultiColumnListProperties__ColumnsSizable_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__ColumnsSizable_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::NominatedSelectionRow'
//
void CEGUI__MultiColumnListProperties__NominatedSelectionRow__Destroy(void*);
void CEGUI__MultiColumnListProperties__NominatedSelectionRow_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__NominatedSelectionRow_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::RowCount'
//
void CEGUI__MultiColumnListProperties__RowCount__Destroy(void*);
void CEGUI__MultiColumnListProperties__RowCount_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__RowCount_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::ForceVertScrollbar'
//
void CEGUI__MultiColumnListProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__MultiColumnListProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::SelectionMode'
//
void CEGUI__MultiColumnListProperties__SelectionMode__Destroy(void*);
void CEGUI__MultiColumnListProperties__SelectionMode_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__SelectionMode_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::SortSettingEnabled'
//
void CEGUI__MultiColumnListProperties__SortSettingEnabled__Destroy(void*);
void CEGUI__MultiColumnListProperties__SortSettingEnabled_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__SortSettingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnHeader'
//
void CEGUI__MultiColumnListProperties__ColumnHeader__Destroy(void*);
void CEGUI__MultiColumnListProperties__ColumnHeader_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__ColumnHeader_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::ForceHorzScrollbar'
//
void CEGUI__MultiColumnListProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__MultiColumnListProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::MultiColumnListProperties::ColumnsMovable'
//
void CEGUI__MultiColumnListProperties__ColumnsMovable__Destroy(void*);
void CEGUI__MultiColumnListProperties__ColumnsMovable_set(void*, void*, void*);
void* CEGUI__MultiColumnListProperties__ColumnsMovable_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::TextParsingEnabled'
//
void CEGUI__WindowProperties__TextParsingEnabled__Destroy(void*);
void CEGUI__WindowProperties__TextParsingEnabled_set(void*, void*, void*);
void* CEGUI__WindowProperties__TextParsingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::MouseCursorImage'
//
void CEGUI__WindowProperties__MouseCursorImage__Destroy(void*);
void CEGUI__WindowProperties__MouseCursorImage_set(void*, void*, void*);
bool CEGUI__WindowProperties__MouseCursorImage_isDefault(void*, void*);
void* CEGUI__WindowProperties__MouseCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::ZOrderChangeEnabled'
//
void CEGUI__WindowProperties__ZOrderChangeEnabled__Destroy(void*);
void CEGUI__WindowProperties__ZOrderChangeEnabled_set(void*, void*, void*);
void* CEGUI__WindowProperties__ZOrderChangeEnabled_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::DistributeCapturedInputs'
//
void CEGUI__WindowProperties__DistributeCapturedInputs__Destroy(void*);
void CEGUI__WindowProperties__DistributeCapturedInputs_set(void*, void*, void*);
void* CEGUI__WindowProperties__DistributeCapturedInputs_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::RiseOnClick'
//
void CEGUI__WindowProperties__RiseOnClick__Destroy(void*);
void CEGUI__WindowProperties__RiseOnClick_set(void*, void*, void*);
void* CEGUI__WindowProperties__RiseOnClick_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::DragDropTarget'
//
void CEGUI__WindowProperties__DragDropTarget__Destroy(void*);
void CEGUI__WindowProperties__DragDropTarget_set(void*, void*, void*);
void* CEGUI__WindowProperties__DragDropTarget_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::AutoRepeatDelay'
//
void CEGUI__WindowProperties__AutoRepeatDelay__Destroy(void*);
void CEGUI__WindowProperties__AutoRepeatDelay_set(void*, void*, void*);
void* CEGUI__WindowProperties__AutoRepeatDelay_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Tooltip'
//
void CEGUI__WindowProperties__Tooltip__Destroy(void*);
void CEGUI__WindowProperties__Tooltip_set(void*, void*, void*);
void* CEGUI__WindowProperties__Tooltip_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedWidth'
//
void CEGUI__WindowProperties__UnifiedWidth__Destroy(void*);
void CEGUI__WindowProperties__UnifiedWidth_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedWidth_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::CustomTooltipType'
//
void CEGUI__WindowProperties__CustomTooltipType__Destroy(void*);
void CEGUI__WindowProperties__CustomTooltipType_set(void*, void*, void*);
void* CEGUI__WindowProperties__CustomTooltipType_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Text'
//
void CEGUI__WindowProperties__Text__Destroy(void*);
void CEGUI__WindowProperties__Text_set(void*, void*, void*);
void* CEGUI__WindowProperties__Text_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::NonClient'
//
void CEGUI__WindowProperties__NonClient__Destroy(void*);
void CEGUI__WindowProperties__NonClient_set(void*, void*, void*);
void* CEGUI__WindowProperties__NonClient_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::YRotation'
//
void CEGUI__WindowProperties__YRotation__Destroy(void*);
void CEGUI__WindowProperties__YRotation_set(void*, void*, void*);
void* CEGUI__WindowProperties__YRotation_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::WantsMultiClickEvents'
//
void CEGUI__WindowProperties__WantsMultiClickEvents__Destroy(void*);
void CEGUI__WindowProperties__WantsMultiClickEvents_set(void*, void*, void*);
void* CEGUI__WindowProperties__WantsMultiClickEvents_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::VerticalAlignment'
//
void CEGUI__WindowProperties__VerticalAlignment__Destroy(void*);
void CEGUI__WindowProperties__VerticalAlignment_set(void*, void*, void*);
void* CEGUI__WindowProperties__VerticalAlignment_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::ID'
//
void CEGUI__WindowProperties__ID__Destroy(void*);
void CEGUI__WindowProperties__ID_set(void*, void*, void*);
void* CEGUI__WindowProperties__ID_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Disabled'
//
void CEGUI__WindowProperties__Disabled__Destroy(void*);
void CEGUI__WindowProperties__Disabled_set(void*, void*, void*);
bool CEGUI__WindowProperties__Disabled_isDefault(void*, void*);
void* CEGUI__WindowProperties__Disabled_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Margin'
//
void CEGUI__WindowProperties__Margin__Destroy(void*);
void CEGUI__WindowProperties__Margin_set(void*, void*, void*);
void* CEGUI__WindowProperties__Margin_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::ClippedByParent'
//
void CEGUI__WindowProperties__ClippedByParent__Destroy(void*);
void CEGUI__WindowProperties__ClippedByParent_set(void*, void*, void*);
void* CEGUI__WindowProperties__ClippedByParent_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::WindowRenderer'
//
void CEGUI__WindowProperties__WindowRenderer__Destroy(void*);
void CEGUI__WindowProperties__WindowRenderer_set(void*, void*, void*);
void CEGUI__WindowProperties__WindowRenderer_writeXMLToStream(void*, void*, void*);
void* CEGUI__WindowProperties__WindowRenderer_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::LookNFeel'
//
void CEGUI__WindowProperties__LookNFeel__Destroy(void*);
void CEGUI__WindowProperties__LookNFeel_set(void*, void*, void*);
void CEGUI__WindowProperties__LookNFeel_writeXMLToStream(void*, void*, void*);
void* CEGUI__WindowProperties__LookNFeel_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedMinSize'
//
void CEGUI__WindowProperties__UnifiedMinSize__Destroy(void*);
void CEGUI__WindowProperties__UnifiedMinSize_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedMinSize_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Rotation'
//
void CEGUI__WindowProperties__Rotation__Destroy(void*);
void CEGUI__WindowProperties__Rotation_set(void*, void*, void*);
void* CEGUI__WindowProperties__Rotation_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedAreaRect'
//
void CEGUI__WindowProperties__UnifiedAreaRect__Destroy(void*);
void CEGUI__WindowProperties__UnifiedAreaRect_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedAreaRect_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::InheritsAlpha'
//
void CEGUI__WindowProperties__InheritsAlpha__Destroy(void*);
void CEGUI__WindowProperties__InheritsAlpha_set(void*, void*, void*);
void* CEGUI__WindowProperties__InheritsAlpha_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Font'
//
void CEGUI__WindowProperties__Font__Destroy(void*);
void CEGUI__WindowProperties__Font_set(void*, void*, void*);
bool CEGUI__WindowProperties__Font_isDefault(void*, void*);
void* CEGUI__WindowProperties__Font_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::AutoRenderingSurface'
//
void CEGUI__WindowProperties__AutoRenderingSurface__Destroy(void*);
void CEGUI__WindowProperties__AutoRenderingSurface_set(void*, void*, void*);
void* CEGUI__WindowProperties__AutoRenderingSurface_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::MouseButtonDownAutoRepeat'
//
void CEGUI__WindowProperties__MouseButtonDownAutoRepeat__Destroy(void*);
void CEGUI__WindowProperties__MouseButtonDownAutoRepeat_set(void*, void*, void*);
void* CEGUI__WindowProperties__MouseButtonDownAutoRepeat_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedPosition'
//
void CEGUI__WindowProperties__UnifiedPosition__Destroy(void*);
void CEGUI__WindowProperties__UnifiedPosition_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedPosition_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedMaxSize'
//
void CEGUI__WindowProperties__UnifiedMaxSize__Destroy(void*);
void CEGUI__WindowProperties__UnifiedMaxSize_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedMaxSize_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::InheritsTooltipText'
//
void CEGUI__WindowProperties__InheritsTooltipText__Destroy(void*);
void CEGUI__WindowProperties__InheritsTooltipText_set(void*, void*, void*);
void* CEGUI__WindowProperties__InheritsTooltipText_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::XRotation'
//
void CEGUI__WindowProperties__XRotation__Destroy(void*);
void CEGUI__WindowProperties__XRotation_set(void*, void*, void*);
void* CEGUI__WindowProperties__XRotation_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::ZRotation'
//
void CEGUI__WindowProperties__ZRotation__Destroy(void*);
void CEGUI__WindowProperties__ZRotation_set(void*, void*, void*);
void* CEGUI__WindowProperties__ZRotation_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::DestroyedByParent'
//
void CEGUI__WindowProperties__DestroyedByParent__Destroy(void*);
void CEGUI__WindowProperties__DestroyedByParent_set(void*, void*, void*);
void* CEGUI__WindowProperties__DestroyedByParent_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::HorizontalAlignment'
//
void CEGUI__WindowProperties__HorizontalAlignment__Destroy(void*);
void CEGUI__WindowProperties__HorizontalAlignment_set(void*, void*, void*);
void* CEGUI__WindowProperties__HorizontalAlignment_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedHeight'
//
void CEGUI__WindowProperties__UnifiedHeight__Destroy(void*);
void CEGUI__WindowProperties__UnifiedHeight_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedHeight_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::RestoreOldCapture'
//
void CEGUI__WindowProperties__RestoreOldCapture__Destroy(void*);
void CEGUI__WindowProperties__RestoreOldCapture_set(void*, void*, void*);
void* CEGUI__WindowProperties__RestoreOldCapture_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Alpha'
//
void CEGUI__WindowProperties__Alpha__Destroy(void*);
void CEGUI__WindowProperties__Alpha_set(void*, void*, void*);
void* CEGUI__WindowProperties__Alpha_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::Visible'
//
void CEGUI__WindowProperties__Visible__Destroy(void*);
void CEGUI__WindowProperties__Visible_set(void*, void*, void*);
bool CEGUI__WindowProperties__Visible_isDefault(void*, void*);
void* CEGUI__WindowProperties__Visible_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::AutoRepeatRate'
//
void CEGUI__WindowProperties__AutoRepeatRate__Destroy(void*);
void CEGUI__WindowProperties__AutoRepeatRate_set(void*, void*, void*);
void* CEGUI__WindowProperties__AutoRepeatRate_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedSize'
//
void CEGUI__WindowProperties__UnifiedSize__Destroy(void*);
void CEGUI__WindowProperties__UnifiedSize_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedSize_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UpdateMode'
//
void CEGUI__WindowProperties__UpdateMode__Destroy(void*);
void CEGUI__WindowProperties__UpdateMode_set(void*, void*, void*);
void* CEGUI__WindowProperties__UpdateMode_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::AlwaysOnTop'
//
void CEGUI__WindowProperties__AlwaysOnTop__Destroy(void*);
void CEGUI__WindowProperties__AlwaysOnTop_set(void*, void*, void*);
void* CEGUI__WindowProperties__AlwaysOnTop_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::MouseInputPropagationEnabled'
//
void CEGUI__WindowProperties__MouseInputPropagationEnabled__Destroy(void*);
void CEGUI__WindowProperties__MouseInputPropagationEnabled_set(void*, void*, void*);
void* CEGUI__WindowProperties__MouseInputPropagationEnabled_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedXPosition'
//
void CEGUI__WindowProperties__UnifiedXPosition__Destroy(void*);
void CEGUI__WindowProperties__UnifiedXPosition_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedXPosition_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::MousePassThroughEnabled'
//
void CEGUI__WindowProperties__MousePassThroughEnabled__Destroy(void*);
void CEGUI__WindowProperties__MousePassThroughEnabled_set(void*, void*, void*);
void* CEGUI__WindowProperties__MousePassThroughEnabled_get(void*, void*);

//
// Begin class 'CEGUI::WindowProperties::UnifiedYPosition'
//
void CEGUI__WindowProperties__UnifiedYPosition__Destroy(void*);
void CEGUI__WindowProperties__UnifiedYPosition_set(void*, void*, void*);
void* CEGUI__WindowProperties__UnifiedYPosition_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::RollUpEnabled'
//
void CEGUI__FrameWindowProperties__RollUpEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__RollUpEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__RollUpEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::CloseButtonEnabled'
//
void CEGUI__FrameWindowProperties__CloseButtonEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__CloseButtonEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__CloseButtonEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::NESWSizingCursorImage'
//
void CEGUI__FrameWindowProperties__NESWSizingCursorImage__Destroy(void*);
void CEGUI__FrameWindowProperties__NESWSizingCursorImage_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__NESWSizingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::RollUpState'
//
void CEGUI__FrameWindowProperties__RollUpState__Destroy(void*);
void CEGUI__FrameWindowProperties__RollUpState_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__RollUpState_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::NWSESizingCursorImage'
//
void CEGUI__FrameWindowProperties__NWSESizingCursorImage__Destroy(void*);
void CEGUI__FrameWindowProperties__NWSESizingCursorImage_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__NWSESizingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::EWSizingCursorImage'
//
void CEGUI__FrameWindowProperties__EWSizingCursorImage__Destroy(void*);
void CEGUI__FrameWindowProperties__EWSizingCursorImage_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__EWSizingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::TitlebarEnabled'
//
void CEGUI__FrameWindowProperties__TitlebarEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__TitlebarEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__TitlebarEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::FrameEnabled'
//
void CEGUI__FrameWindowProperties__FrameEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__FrameEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__FrameEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::DragMovingEnabled'
//
void CEGUI__FrameWindowProperties__DragMovingEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__DragMovingEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__DragMovingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::NSSizingCursorImage'
//
void CEGUI__FrameWindowProperties__NSSizingCursorImage__Destroy(void*);
void CEGUI__FrameWindowProperties__NSSizingCursorImage_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__NSSizingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::SizingEnabled'
//
void CEGUI__FrameWindowProperties__SizingEnabled__Destroy(void*);
void CEGUI__FrameWindowProperties__SizingEnabled_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__SizingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::FrameWindowProperties::SizingBorderThickness'
//
void CEGUI__FrameWindowProperties__SizingBorderThickness__Destroy(void*);
void CEGUI__FrameWindowProperties__SizingBorderThickness_set(void*, void*, void*);
void* CEGUI__FrameWindowProperties__SizingBorderThickness_get(void*, void*);

//
// Begin class 'CEGUI::ScrolledContainerProperties::ContentArea'
//
void CEGUI__ScrolledContainerProperties__ContentArea__Destroy(void*);
void CEGUI__ScrolledContainerProperties__ContentArea_set(void*, void*, void*);
void* CEGUI__ScrolledContainerProperties__ContentArea_get(void*, void*);

//
// Begin class 'CEGUI::ScrolledContainerProperties::ChildExtentsArea'
//
void CEGUI__ScrolledContainerProperties__ChildExtentsArea__Destroy(void*);
void CEGUI__ScrolledContainerProperties__ChildExtentsArea_set(void*, void*, void*);
void* CEGUI__ScrolledContainerProperties__ChildExtentsArea_get(void*, void*);

//
// Begin class 'CEGUI::ScrolledContainerProperties::ContentPaneAutoSized'
//
void CEGUI__ScrolledContainerProperties__ContentPaneAutoSized__Destroy(void*);
void CEGUI__ScrolledContainerProperties__ContentPaneAutoSized_set(void*, void*, void*);
void* CEGUI__ScrolledContainerProperties__ContentPaneAutoSized_get(void*, void*);

//
// Begin class 'CEGUI::ItemListboxProperties::MultiSelect'
//
void CEGUI__ItemListboxProperties__MultiSelect__Destroy(void*);
void CEGUI__ItemListboxProperties__MultiSelect_set(void*, void*, void*);
void* CEGUI__ItemListboxProperties__MultiSelect_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::EditSelectionLength'
//
void CEGUI__ComboboxProperties__EditSelectionLength__Destroy(void*);
void CEGUI__ComboboxProperties__EditSelectionLength_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__EditSelectionLength_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::ForceHorzScrollbar'
//
void CEGUI__ComboboxProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__ComboboxProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::CaratIndex'
//
void CEGUI__ComboboxProperties__CaratIndex__Destroy(void*);
void CEGUI__ComboboxProperties__CaratIndex_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__CaratIndex_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::MaxEditTextLength'
//
void CEGUI__ComboboxProperties__MaxEditTextLength__Destroy(void*);
void CEGUI__ComboboxProperties__MaxEditTextLength_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__MaxEditTextLength_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::ForceVertScrollbar'
//
void CEGUI__ComboboxProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__ComboboxProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::SingleClickMode'
//
void CEGUI__ComboboxProperties__SingleClickMode__Destroy(void*);
void CEGUI__ComboboxProperties__SingleClickMode_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__SingleClickMode_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::SortList'
//
void CEGUI__ComboboxProperties__SortList__Destroy(void*);
void CEGUI__ComboboxProperties__SortList_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__SortList_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::EditSelectionStart'
//
void CEGUI__ComboboxProperties__EditSelectionStart__Destroy(void*);
void CEGUI__ComboboxProperties__EditSelectionStart_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__EditSelectionStart_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::ReadOnly'
//
void CEGUI__ComboboxProperties__ReadOnly__Destroy(void*);
void CEGUI__ComboboxProperties__ReadOnly_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__ReadOnly_get(void*, void*);

//
// Begin class 'CEGUI::ComboboxProperties::ValidationString'
//
void CEGUI__ComboboxProperties__ValidationString__Destroy(void*);
void CEGUI__ComboboxProperties__ValidationString_set(void*, void*, void*);
void* CEGUI__ComboboxProperties__ValidationString_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::DraggingEnabled'
//
void CEGUI__DragContainerProperties__DraggingEnabled__Destroy(void*);
void CEGUI__DragContainerProperties__DraggingEnabled_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__DraggingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::FixedDragOffset'
//
void CEGUI__DragContainerProperties__FixedDragOffset__Destroy(void*);
void CEGUI__DragContainerProperties__FixedDragOffset_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__FixedDragOffset_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::DragThreshold'
//
void CEGUI__DragContainerProperties__DragThreshold__Destroy(void*);
void CEGUI__DragContainerProperties__DragThreshold_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__DragThreshold_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::UseFixedDragOffset'
//
void CEGUI__DragContainerProperties__UseFixedDragOffset__Destroy(void*);
void CEGUI__DragContainerProperties__UseFixedDragOffset_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__UseFixedDragOffset_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::StickyMode'
//
void CEGUI__DragContainerProperties__StickyMode__Destroy(void*);
void CEGUI__DragContainerProperties__StickyMode_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__StickyMode_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::DragCursorImage'
//
void CEGUI__DragContainerProperties__DragCursorImage__Destroy(void*);
void CEGUI__DragContainerProperties__DragCursorImage_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__DragCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::DragContainerProperties::DragAlpha'
//
void CEGUI__DragContainerProperties__DragAlpha__Destroy(void*);
void CEGUI__DragContainerProperties__DragAlpha_set(void*, void*, void*);
void* CEGUI__DragContainerProperties__DragAlpha_get(void*, void*);

//
// Begin class 'CEGUI::ItemEntryProperties::Selected'
//
void CEGUI__ItemEntryProperties__Selected__Destroy(void*);
void CEGUI__ItemEntryProperties__Selected_set(void*, void*, void*);
void* CEGUI__ItemEntryProperties__Selected_get(void*, void*);

//
// Begin class 'CEGUI::ItemEntryProperties::Selectable'
//
void CEGUI__ItemEntryProperties__Selectable__Destroy(void*);
void CEGUI__ItemEntryProperties__Selectable_set(void*, void*, void*);
void* CEGUI__ItemEntryProperties__Selectable_get(void*, void*);

//
// Begin class 'CEGUI::TooltipProperties::HoverTime'
//
void CEGUI__TooltipProperties__HoverTime__Destroy(void*);
void CEGUI__TooltipProperties__HoverTime_set(void*, void*, void*);
void* CEGUI__TooltipProperties__HoverTime_get(void*, void*);

//
// Begin class 'CEGUI::TooltipProperties::DisplayTime'
//
void CEGUI__TooltipProperties__DisplayTime__Destroy(void*);
void CEGUI__TooltipProperties__DisplayTime_set(void*, void*, void*);
void* CEGUI__TooltipProperties__DisplayTime_get(void*, void*);

//
// Begin class 'CEGUI::TooltipProperties::FadeTime'
//
void CEGUI__TooltipProperties__FadeTime__Destroy(void*);
void CEGUI__TooltipProperties__FadeTime_set(void*, void*, void*);
void* CEGUI__TooltipProperties__FadeTime_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderProperties::ColumnsMovable'
//
void CEGUI__ListHeaderProperties__ColumnsMovable__Destroy(void*);
void CEGUI__ListHeaderProperties__ColumnsMovable_set(void*, void*, void*);
void* CEGUI__ListHeaderProperties__ColumnsMovable_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderProperties::ColumnsSizable'
//
void CEGUI__ListHeaderProperties__ColumnsSizable__Destroy(void*);
void CEGUI__ListHeaderProperties__ColumnsSizable_set(void*, void*, void*);
void* CEGUI__ListHeaderProperties__ColumnsSizable_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderProperties::SortDirection'
//
void CEGUI__ListHeaderProperties__SortDirection__Destroy(void*);
void CEGUI__ListHeaderProperties__SortDirection_set(void*, void*, void*);
void* CEGUI__ListHeaderProperties__SortDirection_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderProperties::SortSettingEnabled'
//
void CEGUI__ListHeaderProperties__SortSettingEnabled__Destroy(void*);
void CEGUI__ListHeaderProperties__SortSettingEnabled_set(void*, void*, void*);
void* CEGUI__ListHeaderProperties__SortSettingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderProperties::SortColumnID'
//
void CEGUI__ListHeaderProperties__SortColumnID__Destroy(void*);
void CEGUI__ListHeaderProperties__SortColumnID_set(void*, void*, void*);
void* CEGUI__ListHeaderProperties__SortColumnID_get(void*, void*);

//
// Begin class 'CEGUI::ItemListBaseProperties::SortEnabled'
//
void CEGUI__ItemListBaseProperties__SortEnabled__Destroy(void*);
void CEGUI__ItemListBaseProperties__SortEnabled_set(void*, void*, void*);
void* CEGUI__ItemListBaseProperties__SortEnabled_get(void*, void*);

//
// Begin class 'CEGUI::ItemListBaseProperties::AutoResizeEnabled'
//
void CEGUI__ItemListBaseProperties__AutoResizeEnabled__Destroy(void*);
void CEGUI__ItemListBaseProperties__AutoResizeEnabled_set(void*, void*, void*);
void* CEGUI__ItemListBaseProperties__AutoResizeEnabled_get(void*, void*);

//
// Begin class 'CEGUI::ItemListBaseProperties::SortMode'
//
void CEGUI__ItemListBaseProperties__SortMode__Destroy(void*);
void CEGUI__ItemListBaseProperties__SortMode_set(void*, void*, void*);
void* CEGUI__ItemListBaseProperties__SortMode_get(void*, void*);

//
// Begin class 'CEGUI::TitlebarProperties::DraggingEnabled'
//
void CEGUI__TitlebarProperties__DraggingEnabled__Destroy(void*);
void CEGUI__TitlebarProperties__DraggingEnabled_set(void*, void*, void*);
void* CEGUI__TitlebarProperties__DraggingEnabled_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Dragable'
//
void CEGUI__ListHeaderSegmentProperties__Dragable__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__Dragable_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__Dragable_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::SizingCursorImage'
//
void CEGUI__ListHeaderSegmentProperties__SizingCursorImage__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__SizingCursorImage_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__SizingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Sizable'
//
void CEGUI__ListHeaderSegmentProperties__Sizable__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__Sizable_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__Sizable_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::Clickable'
//
void CEGUI__ListHeaderSegmentProperties__Clickable__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__Clickable_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__Clickable_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::SortDirection'
//
void CEGUI__ListHeaderSegmentProperties__SortDirection__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__SortDirection_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__SortDirection_get(void*, void*);

//
// Begin class 'CEGUI::ListHeaderSegmentProperties::MovingCursorImage'
//
void CEGUI__ListHeaderSegmentProperties__MovingCursorImage__Destroy(void*);
void CEGUI__ListHeaderSegmentProperties__MovingCursorImage_set(void*, void*, void*);
void* CEGUI__ListHeaderSegmentProperties__MovingCursorImage_get(void*, void*);

//
// Begin class 'CEGUI::ProgressBarProperties::CurrentProgress'
//
void CEGUI__ProgressBarProperties__CurrentProgress__Destroy(void*);
void CEGUI__ProgressBarProperties__CurrentProgress_set(void*, void*, void*);
void* CEGUI__ProgressBarProperties__CurrentProgress_get(void*, void*);

//
// Begin class 'CEGUI::ProgressBarProperties::StepSize'
//
void CEGUI__ProgressBarProperties__StepSize__Destroy(void*);
void CEGUI__ProgressBarProperties__StepSize_set(void*, void*, void*);
void* CEGUI__ProgressBarProperties__StepSize_get(void*, void*);

//
// Begin class 'CEGUI::TreeProperties::Sort'
//
void CEGUI__TreeProperties__Sort__Destroy(void*);
void CEGUI__TreeProperties__Sort_set(void*, void*, void*);
void* CEGUI__TreeProperties__Sort_get(void*, void*);

//
// Begin class 'CEGUI::TreeProperties::MultiSelect'
//
void CEGUI__TreeProperties__MultiSelect__Destroy(void*);
void CEGUI__TreeProperties__MultiSelect_set(void*, void*, void*);
void* CEGUI__TreeProperties__MultiSelect_get(void*, void*);

//
// Begin class 'CEGUI::TreeProperties::ItemTooltips'
//
void CEGUI__TreeProperties__ItemTooltips__Destroy(void*);
void CEGUI__TreeProperties__ItemTooltips_set(void*, void*, void*);
void* CEGUI__TreeProperties__ItemTooltips_get(void*, void*);

//
// Begin class 'CEGUI::TreeProperties::ForceVertScrollbar'
//
void CEGUI__TreeProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__TreeProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__TreeProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::TreeProperties::ForceHorzScrollbar'
//
void CEGUI__TreeProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__TreeProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__TreeProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::RadioButtonProperties::Selected'
//
void CEGUI__RadioButtonProperties__Selected__Destroy(void*);
void CEGUI__RadioButtonProperties__Selected_set(void*, void*, void*);
void* CEGUI__RadioButtonProperties__Selected_get(void*, void*);

//
// Begin class 'CEGUI::RadioButtonProperties::GroupID'
//
void CEGUI__RadioButtonProperties__GroupID__Destroy(void*);
void CEGUI__RadioButtonProperties__GroupID_set(void*, void*, void*);
void* CEGUI__RadioButtonProperties__GroupID_get(void*, void*);

//
// Begin class 'CEGUI::ListboxProperties::MultiSelect'
//
void CEGUI__ListboxProperties__MultiSelect__Destroy(void*);
void CEGUI__ListboxProperties__MultiSelect_set(void*, void*, void*);
void* CEGUI__ListboxProperties__MultiSelect_get(void*, void*);

//
// Begin class 'CEGUI::ListboxProperties::ItemTooltips'
//
void CEGUI__ListboxProperties__ItemTooltips__Destroy(void*);
void CEGUI__ListboxProperties__ItemTooltips_set(void*, void*, void*);
void* CEGUI__ListboxProperties__ItemTooltips_get(void*, void*);

//
// Begin class 'CEGUI::ListboxProperties::ForceHorzScrollbar'
//
void CEGUI__ListboxProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__ListboxProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__ListboxProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::ListboxProperties::Sort'
//
void CEGUI__ListboxProperties__Sort__Destroy(void*);
void CEGUI__ListboxProperties__Sort_set(void*, void*, void*);
void* CEGUI__ListboxProperties__Sort_get(void*, void*);

//
// Begin class 'CEGUI::ListboxProperties::ForceVertScrollbar'
//
void CEGUI__ListboxProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__ListboxProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__ListboxProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::SelectionStart'
//
void CEGUI__EditboxProperties__SelectionStart__Destroy(void*);
void CEGUI__EditboxProperties__SelectionStart_set(void*, void*, void*);
void* CEGUI__EditboxProperties__SelectionStart_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::NormalTextColour'
//
void CEGUI__EditboxProperties__NormalTextColour__Destroy(void*);
void CEGUI__EditboxProperties__NormalTextColour_set(void*, void*, void*);
void* CEGUI__EditboxProperties__NormalTextColour_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::MaskText'
//
void CEGUI__EditboxProperties__MaskText__Destroy(void*);
void CEGUI__EditboxProperties__MaskText_set(void*, void*, void*);
void* CEGUI__EditboxProperties__MaskText_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::CaratIndex'
//
void CEGUI__EditboxProperties__CaratIndex__Destroy(void*);
void CEGUI__EditboxProperties__CaratIndex_set(void*, void*, void*);
void* CEGUI__EditboxProperties__CaratIndex_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::MaskCodepoint'
//
void CEGUI__EditboxProperties__MaskCodepoint__Destroy(void*);
void CEGUI__EditboxProperties__MaskCodepoint_set(void*, void*, void*);
void* CEGUI__EditboxProperties__MaskCodepoint_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::ActiveSelectionColour'
//
void CEGUI__EditboxProperties__ActiveSelectionColour__Destroy(void*);
void CEGUI__EditboxProperties__ActiveSelectionColour_set(void*, void*, void*);
void* CEGUI__EditboxProperties__ActiveSelectionColour_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::SelectedTextColour'
//
void CEGUI__EditboxProperties__SelectedTextColour__Destroy(void*);
void CEGUI__EditboxProperties__SelectedTextColour_set(void*, void*, void*);
void* CEGUI__EditboxProperties__SelectedTextColour_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::InactiveSelectionColour'
//
void CEGUI__EditboxProperties__InactiveSelectionColour__Destroy(void*);
void CEGUI__EditboxProperties__InactiveSelectionColour_set(void*, void*, void*);
void* CEGUI__EditboxProperties__InactiveSelectionColour_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::ReadOnly'
//
void CEGUI__EditboxProperties__ReadOnly__Destroy(void*);
void CEGUI__EditboxProperties__ReadOnly_set(void*, void*, void*);
void* CEGUI__EditboxProperties__ReadOnly_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::SelectionLength'
//
void CEGUI__EditboxProperties__SelectionLength__Destroy(void*);
void CEGUI__EditboxProperties__SelectionLength_set(void*, void*, void*);
void* CEGUI__EditboxProperties__SelectionLength_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::ValidationString'
//
void CEGUI__EditboxProperties__ValidationString__Destroy(void*);
void CEGUI__EditboxProperties__ValidationString_set(void*, void*, void*);
void* CEGUI__EditboxProperties__ValidationString_get(void*, void*);

//
// Begin class 'CEGUI::EditboxProperties::MaxTextLength'
//
void CEGUI__EditboxProperties__MaxTextLength__Destroy(void*);
void CEGUI__EditboxProperties__MaxTextLength_set(void*, void*, void*);
void* CEGUI__EditboxProperties__MaxTextLength_get(void*, void*);

//
// Begin class 'CEGUI::ScrolledItemListBaseProperties::ForceHorzScrollbar'
//
void CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar__Destroy(void*);
void CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar_set(void*, void*, void*);
void* CEGUI__ScrolledItemListBaseProperties__ForceHorzScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::ScrolledItemListBaseProperties::ForceVertScrollbar'
//
void CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__ScrolledItemListBaseProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::SliderProperties::MaximumValue'
//
void CEGUI__SliderProperties__MaximumValue__Destroy(void*);
void CEGUI__SliderProperties__MaximumValue_set(void*, void*, void*);
void* CEGUI__SliderProperties__MaximumValue_get(void*, void*);

//
// Begin class 'CEGUI::SliderProperties::CurrentValue'
//
void CEGUI__SliderProperties__CurrentValue__Destroy(void*);
void CEGUI__SliderProperties__CurrentValue_set(void*, void*, void*);
void* CEGUI__SliderProperties__CurrentValue_get(void*, void*);

//
// Begin class 'CEGUI::SliderProperties::ClickStepSize'
//
void CEGUI__SliderProperties__ClickStepSize__Destroy(void*);
void CEGUI__SliderProperties__ClickStepSize_set(void*, void*, void*);
void* CEGUI__SliderProperties__ClickStepSize_get(void*, void*);

//
// Begin class 'CEGUI::MenuBaseProperties::ItemSpacing'
//
void CEGUI__MenuBaseProperties__ItemSpacing__Destroy(void*);
void CEGUI__MenuBaseProperties__ItemSpacing_set(void*, void*, void*);
void* CEGUI__MenuBaseProperties__ItemSpacing_get(void*, void*);

//
// Begin class 'CEGUI::MenuBaseProperties::AllowMultiplePopups'
//
void CEGUI__MenuBaseProperties__AllowMultiplePopups__Destroy(void*);
void CEGUI__MenuBaseProperties__AllowMultiplePopups_set(void*, void*, void*);
void* CEGUI__MenuBaseProperties__AllowMultiplePopups_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::ReadOnly'
//
void CEGUI__MultiLineEditboxProperties__ReadOnly__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__ReadOnly_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__ReadOnly_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::CaratIndex'
//
void CEGUI__MultiLineEditboxProperties__CaratIndex__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__CaratIndex_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__CaratIndex_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionStart'
//
void CEGUI__MultiLineEditboxProperties__SelectionStart__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__SelectionStart_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__SelectionStart_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::ForceVertScrollbar'
//
void CEGUI__MultiLineEditboxProperties__ForceVertScrollbar__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__ForceVertScrollbar_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__ForceVertScrollbar_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionLength'
//
void CEGUI__MultiLineEditboxProperties__SelectionLength__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__SelectionLength_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__SelectionLength_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::MaxTextLength'
//
void CEGUI__MultiLineEditboxProperties__MaxTextLength__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__MaxTextLength_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__MaxTextLength_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::WordWrap'
//
void CEGUI__MultiLineEditboxProperties__WordWrap__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__WordWrap_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__WordWrap_get(void*, void*);

//
// Begin class 'CEGUI::MultiLineEditboxProperties::SelectionBrushImage'
//
void CEGUI__MultiLineEditboxProperties__SelectionBrushImage__Destroy(void*);
void CEGUI__MultiLineEditboxProperties__SelectionBrushImage_set(void*, void*, void*);
void* CEGUI__MultiLineEditboxProperties__SelectionBrushImage_get(void*, void*);

//
// Begin class 'CEGUI::TabControlProperties::TabPanePosition'
//
void CEGUI__TabControlProperties__TabPanePosition__Destroy(void*);
void CEGUI__TabControlProperties__TabPanePosition_set(void*, void*, void*);
void* CEGUI__TabControlProperties__TabPanePosition_get(void*, void*);

//
// Begin class 'CEGUI::TabControlProperties::TabHeight'
//
void CEGUI__TabControlProperties__TabHeight__Destroy(void*);
void CEGUI__TabControlProperties__TabHeight_set(void*, void*, void*);
void* CEGUI__TabControlProperties__TabHeight_get(void*, void*);

//
// Begin class 'CEGUI::TabControlProperties::TabTextPadding'
//
void CEGUI__TabControlProperties__TabTextPadding__Destroy(void*);
void CEGUI__TabControlProperties__TabTextPadding_set(void*, void*, void*);
void* CEGUI__TabControlProperties__TabTextPadding_get(void*, void*);

//
// Begin class 'CEGUI::GridLayoutContainerProperties::GridSize'
//
void CEGUI__GridLayoutContainerProperties__GridSize__Destroy(void*);
void CEGUI__GridLayoutContainerProperties__GridSize_set(void*, void*, void*);
void* CEGUI__GridLayoutContainerProperties__GridSize_get(void*, void*);

//
// Begin class 'CEGUI::GridLayoutContainerProperties::AutoPositioning'
//
void CEGUI__GridLayoutContainerProperties__AutoPositioning__Destroy(void*);
void CEGUI__GridLayoutContainerProperties__AutoPositioning_set(void*, void*, void*);
void* CEGUI__GridLayoutContainerProperties__AutoPositioning_get(void*, void*);

//
// Begin class 'CEGUI::CheckboxProperties::Selected'
//
void CEGUI__CheckboxProperties__Selected__Destroy(void*);
void CEGUI__CheckboxProperties__Selected_set(void*, void*, void*);
void* CEGUI__CheckboxProperties__Selected_get(void*, void*);
}
