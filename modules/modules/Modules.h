/* Modules.h generated by valac 0.24.0, the Vala compiler, do not modify */


#ifndef __MODULES_H__
#define __MODULES_H__

#include <glib.h>
#include <GtkSinticBolivia.h>
#include <SinticBolivia.h>
#include <gtk/gtk.h>
#include <gmodule.h>

G_BEGIN_DECLS


#define EPOS_TYPE_SB_MODULEMODULES (epos_sb_modulemodules_get_type ())
#define EPOS_SB_MODULEMODULES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_SB_MODULEMODULES, EPosSB_ModuleModules))
#define EPOS_SB_MODULEMODULES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_SB_MODULEMODULES, EPosSB_ModuleModulesClass))
#define EPOS_IS_SB_MODULEMODULES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_SB_MODULEMODULES))
#define EPOS_IS_SB_MODULEMODULES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_SB_MODULEMODULES))
#define EPOS_SB_MODULEMODULES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_SB_MODULEMODULES, EPosSB_ModuleModulesClass))

typedef struct _EPosSB_ModuleModules EPosSB_ModuleModules;
typedef struct _EPosSB_ModuleModulesClass EPosSB_ModuleModulesClass;
typedef struct _EPosSB_ModuleModulesPrivate EPosSB_ModuleModulesPrivate;

#define EPOS_TYPE_WIDGET_MODULES (epos_widget_modules_get_type ())
#define EPOS_WIDGET_MODULES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_WIDGET_MODULES, EPosWidgetModules))
#define EPOS_WIDGET_MODULES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_WIDGET_MODULES, EPosWidgetModulesClass))
#define EPOS_IS_WIDGET_MODULES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_WIDGET_MODULES))
#define EPOS_IS_WIDGET_MODULES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_WIDGET_MODULES))
#define EPOS_WIDGET_MODULES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_WIDGET_MODULES, EPosWidgetModulesClass))

typedef struct _EPosWidgetModules EPosWidgetModules;
typedef struct _EPosWidgetModulesClass EPosWidgetModulesClass;
typedef struct _EPosWidgetModulesPrivate EPosWidgetModulesPrivate;

struct _EPosSB_ModuleModules {
	SinticBoliviaGtkSBGtkModule parent_instance;
	EPosSB_ModuleModulesPrivate * priv;
};

struct _EPosSB_ModuleModulesClass {
	SinticBoliviaGtkSBGtkModuleClass parent_class;
};

struct _EPosWidgetModules {
	GtkBox parent_instance;
	EPosWidgetModulesPrivate * priv;
	GtkBox* headerBox;
	GtkImage* headerImage;
	GtkLabel* headerLabel;
	GtkBox* buttonsBox;
	GtkButton* buttonEnable;
	GtkButton* buttonDisable;
	GtkScrolledWindow* scrolled;
	GtkTreeView* treeview;
	GtkBox* footerButtonsBox;
	GtkButton* buttonClose;
};

struct _EPosWidgetModulesClass {
	GtkBoxClass parent_class;
};


GType epos_sb_modulemodules_get_type (void) G_GNUC_CONST;
void epos_sb_modulemodules_AddHooks (EPosSB_ModuleModules* self);
void epos_sb_modulemodules_init_menu_management (SinticBoliviaSBModuleArgs* args);
EPosSB_ModuleModules* epos_sb_modulemodules_new (void);
EPosSB_ModuleModules* epos_sb_modulemodules_construct (GType object_type);
GType sb_get_module_libmodules_type (GModule* customers_module);
GType epos_widget_modules_get_type (void) G_GNUC_CONST;
EPosWidgetModules* epos_widget_modules_new (void);
EPosWidgetModules* epos_widget_modules_construct (GType object_type);
void epos_widget_modules_Build (EPosWidgetModules* self);
void epos_widget_modules_SetEvents (EPosWidgetModules* self);
void epos_widget_modules_RetrieveModules (EPosWidgetModules* self);
void epos_widget_modules_OnTreeViewCursorChanged (EPosWidgetModules* self);
void epos_widget_modules_OnButtonEnableClicked (EPosWidgetModules* self);
void epos_widget_modules_OnButtonDisableClicked (EPosWidgetModules* self);


G_END_DECLS

#endif
