/* libQuotes.h generated by valac 0.24.0, the Vala compiler, do not modify */


#ifndef __LIBQUOTES_H__
#define __LIBQUOTES_H__

#include <glib.h>
#include <GtkSinticBolivia.h>
#include <SinticBolivia.h>
#include <gtk/gtk.h>
#include <gmodule.h>
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <gdk/gdk.h>

G_BEGIN_DECLS


#define EPOS_TYPE_SB_MODULEQUOTES (epos_sb_modulequotes_get_type ())
#define EPOS_SB_MODULEQUOTES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_SB_MODULEQUOTES, EPosSB_ModuleQuotes))
#define EPOS_SB_MODULEQUOTES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_SB_MODULEQUOTES, EPosSB_ModuleQuotesClass))
#define EPOS_IS_SB_MODULEQUOTES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_SB_MODULEQUOTES))
#define EPOS_IS_SB_MODULEQUOTES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_SB_MODULEQUOTES))
#define EPOS_SB_MODULEQUOTES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_SB_MODULEQUOTES, EPosSB_ModuleQuotesClass))

typedef struct _EPosSB_ModuleQuotes EPosSB_ModuleQuotes;
typedef struct _EPosSB_ModuleQuotesClass EPosSB_ModuleQuotesClass;
typedef struct _EPosSB_ModuleQuotesPrivate EPosSB_ModuleQuotesPrivate;

#define EPOS_TYPE_QUOTE (epos_quote_get_type ())
#define EPOS_QUOTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_QUOTE, EPosQuote))
#define EPOS_QUOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_QUOTE, EPosQuoteClass))
#define EPOS_IS_QUOTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_QUOTE))
#define EPOS_IS_QUOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_QUOTE))
#define EPOS_QUOTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_QUOTE, EPosQuoteClass))

typedef struct _EPosQuote EPosQuote;
typedef struct _EPosQuoteClass EPosQuoteClass;
typedef struct _EPosQuotePrivate EPosQuotePrivate;

#define EPOS_TYPE_WIDGET_NEW_QUOTE (epos_widget_new_quote_get_type ())
#define EPOS_WIDGET_NEW_QUOTE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_WIDGET_NEW_QUOTE, EPosWidgetNewQuote))
#define EPOS_WIDGET_NEW_QUOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_WIDGET_NEW_QUOTE, EPosWidgetNewQuoteClass))
#define EPOS_IS_WIDGET_NEW_QUOTE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_WIDGET_NEW_QUOTE))
#define EPOS_IS_WIDGET_NEW_QUOTE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_WIDGET_NEW_QUOTE))
#define EPOS_WIDGET_NEW_QUOTE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_WIDGET_NEW_QUOTE, EPosWidgetNewQuoteClass))

typedef struct _EPosWidgetNewQuote EPosWidgetNewQuote;
typedef struct _EPosWidgetNewQuoteClass EPosWidgetNewQuoteClass;
typedef struct _EPosWidgetNewQuotePrivate EPosWidgetNewQuotePrivate;

#define EPOS_WIDGET_NEW_QUOTE_TYPE_COLUMNS (epos_widget_new_quote_columns_get_type ())

#define EPOS_TYPE_WIDGET_QUOTES (epos_widget_quotes_get_type ())
#define EPOS_WIDGET_QUOTES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), EPOS_TYPE_WIDGET_QUOTES, EPosWidgetQuotes))
#define EPOS_WIDGET_QUOTES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), EPOS_TYPE_WIDGET_QUOTES, EPosWidgetQuotesClass))
#define EPOS_IS_WIDGET_QUOTES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EPOS_TYPE_WIDGET_QUOTES))
#define EPOS_IS_WIDGET_QUOTES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), EPOS_TYPE_WIDGET_QUOTES))
#define EPOS_WIDGET_QUOTES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), EPOS_TYPE_WIDGET_QUOTES, EPosWidgetQuotesClass))

typedef struct _EPosWidgetQuotes EPosWidgetQuotes;
typedef struct _EPosWidgetQuotesClass EPosWidgetQuotesClass;
typedef struct _EPosWidgetQuotesPrivate EPosWidgetQuotesPrivate;

#define EPOS_WIDGET_QUOTES_TYPE_COLUMNS (epos_widget_quotes_columns_get_type ())

struct _EPosSB_ModuleQuotes {
	SinticBoliviaGtkSBGtkModule parent_instance;
	EPosSB_ModuleQuotesPrivate * priv;
};

struct _EPosSB_ModuleQuotesClass {
	SinticBoliviaGtkSBGtkModuleClass parent_class;
};

struct _EPosQuote {
	SinticBoliviaSBDbObject parent_instance;
	EPosQuotePrivate * priv;
	GeeArrayList* Items;
};

struct _EPosQuoteClass {
	SinticBoliviaSBDbObjectClass parent_class;
};

struct _EPosWidgetNewQuote {
	GtkBox parent_instance;
	EPosWidgetNewQuotePrivate * priv;
	GtkBuilder* ui;
	GtkBox* boxNewQuote;
	GtkImage* image1;
	GtkLabel* labelTitle;
	GtkComboBox* comboboxStores;
	SinticBoliviaGtkSBDatePicker* datepickerOrderDate;
	SinticBoliviaGtkSBDatePicker* datepickerExpirationDate;
	GtkEntry* entrySearchCustomer;
	GtkButton* buttonLookupCustomers;
	GtkButton* buttonNewCustomer;
	GtkEntry* entryDetails;
	GtkEntry* entrySearchProduct;
	GtkSpinButton* spinbuttonProductQty;
	GtkComboBox* comboboxSearchType;
	GtkButton* buttonAddProduct;
	GtkTreeView* treeviewProducts;
	GtkButtonBox* buttonbox1;
	GtkButton* buttonCancel;
	GtkButton* buttonSave;
	GtkLabel* labelSubTotal;
	GtkLabel* labelTotalTax;
	GtkLabel* labelTotal;
	gint total_items;
	EPosQuote* quote;
	gint customerId;
};

struct _EPosWidgetNewQuoteClass {
	GtkBoxClass parent_class;
};

typedef enum  {
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_COUNT,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_PRODUCT_CODE,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_PRODUCT_NAME,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_QTY,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_PRICE,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_SUB_TOTAL,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_DISCOUNT,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_TAX,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_TOTAL,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_IMAGE,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_PRODUCT_ID,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_TAX_RATE,
	EPOS_WIDGET_NEW_QUOTE_COLUMNS_N_COLS
} EPosWidgetNewQuoteColumns;

struct _EPosWidgetQuotes {
	GtkBox parent_instance;
	EPosWidgetQuotesPrivate * priv;
	GtkBuilder* ui;
	GtkBox* boxQuotes;
	GtkImage* image1;
	GtkLabel* labelTitle;
	GtkButton* buttonNew;
	GtkButton* buttonEdit;
	GtkButton* buttonDelete;
	GtkButton* buttonPrint;
	GtkButton* buttonPreview;
	GtkComboBox* comboboxStores;
	GtkComboBox* comboboxStatus;
	GtkTreeView* treeviewQuotes;
};

struct _EPosWidgetQuotesClass {
	GtkBoxClass parent_class;
};

typedef enum  {
	EPOS_WIDGET_QUOTES_COLUMNS_COUNT,
	EPOS_WIDGET_QUOTES_COLUMNS_QUOTE_ID,
	EPOS_WIDGET_QUOTES_COLUMNS_CODE,
	EPOS_WIDGET_QUOTES_COLUMNS_ITEMS,
	EPOS_WIDGET_QUOTES_COLUMNS_TOTAL,
	EPOS_WIDGET_QUOTES_COLUMNS_STATUS,
	EPOS_WIDGET_QUOTES_COLUMNS_CREATION_DATE,
	EPOS_WIDGET_QUOTES_COLUMNS_EXPIRATION_DATE,
	EPOS_WIDGET_QUOTES_COLUMNS_N_COLS
} EPosWidgetQuotesColumns;


GType epos_sb_modulequotes_get_type (void) G_GNUC_CONST;
void epos_sb_modulequotes_AddHooks (EPosSB_ModuleQuotes* self);
void epos_sb_modulequotes_hook_menu_item_point_of_sale (EPosSB_ModuleQuotes* self, SinticBoliviaSBModuleArgs* args);
EPosSB_ModuleQuotes* epos_sb_modulequotes_new (void);
EPosSB_ModuleQuotes* epos_sb_modulequotes_construct (GType object_type);
GType sb_get_module_libquotes_type (GModule* quotes_module);
GType epos_quote_get_type (void) G_GNUC_CONST;
EPosQuote* epos_quote_new (void);
EPosQuote* epos_quote_construct (GType object_type);
EPosQuote* epos_quote_new_from_id (gint quote_id);
EPosQuote* epos_quote_construct_from_id (GType object_type, gint quote_id);
void epos_quote_GetDbData (EPosQuote* self, gint quote_id);
void epos_quote_GetDbItems (EPosQuote* self);
gint epos_quote_get_Id (EPosQuote* self);
const gchar* epos_quote_get_Code (EPosQuote* self);
gint epos_quote_get_StoreId (EPosQuote* self);
gint epos_quote_get_UserId (EPosQuote* self);
gint epos_quote_get_CustomerId (EPosQuote* self);
const gchar* epos_quote_get_Details (EPosQuote* self);
gdouble epos_quote_get_SubTotal (EPosQuote* self);
gdouble epos_quote_get_TaxTotal (EPosQuote* self);
gdouble epos_quote_get_Total (EPosQuote* self);
const gchar* epos_quote_get_Status (EPosQuote* self);
GType epos_widget_new_quote_get_type (void) G_GNUC_CONST;
GType epos_widget_new_quote_columns_get_type (void) G_GNUC_CONST;
EPosWidgetNewQuote* epos_widget_new_quote_new (void);
EPosWidgetNewQuote* epos_widget_new_quote_construct (GType object_type);
void epos_widget_new_quote_Build (EPosWidgetNewQuote* self);
void epos_widget_new_quote_SetEvents (EPosWidgetNewQuote* self);
void epos_widget_new_quote_FillForm (EPosWidgetNewQuote* self);
void epos_widget_new_quote_OnButtonLookupCustomersClicked (EPosWidgetNewQuote* self);
gboolean epos_widget_new_quote_OnEntrySearchProductKeyReleaseEvent (EPosWidgetNewQuote* self, GdkEventKey* event);
gboolean epos_widget_new_quote_OnCompletionMatchSelected (EPosWidgetNewQuote* self, GtkTreeModel* model, GtkTreeIter* iter);
gboolean epos_widget_new_quote_isProductInOrder (EPosWidgetNewQuote* self, gint product_id, GtkTreeIter* o_iter);
void epos_widget_new_quote_OnButtonAddProductClicked (EPosWidgetNewQuote* self);
void epos_widget_new_quote_calculateRowTotal (EPosWidgetNewQuote* self, GtkTreeIter* iter);
void epos_widget_new_quote_calculateTotals (EPosWidgetNewQuote* self);
gboolean epos_widget_new_quote_OnTreeViewProductsButtonReleaseEvent (EPosWidgetNewQuote* self, GdkEventButton* args);
void epos_widget_new_quote_OnButtonSaveClicked (EPosWidgetNewQuote* self);
void epos_widget_new_quote_OnButtonCancelClicked (EPosWidgetNewQuote* self);
void epos_widget_new_quote_SetOrder (EPosWidgetNewQuote* self, EPosQuote* order);
void epos_widget_new_quote_OnButtonSendSaleClicked (EPosWidgetNewQuote* self);
void epos_widget_new_quote_set_Title (EPosWidgetNewQuote* self, const gchar* value);
GType epos_widget_quotes_get_type (void) G_GNUC_CONST;
GType epos_widget_quotes_columns_get_type (void) G_GNUC_CONST;
EPosWidgetQuotes* epos_widget_quotes_new (void);
EPosWidgetQuotes* epos_widget_quotes_construct (GType object_type);
void epos_widget_quotes_Build (EPosWidgetQuotes* self);
void epos_widget_quotes_FillForm (EPosWidgetQuotes* self);
void epos_widget_quotes_SetEvents (EPosWidgetQuotes* self);
void epos_widget_quotes_OnComboBoxStoresChanged (EPosWidgetQuotes* self);
void epos_widget_quotes_OnComboBoxStatusChanged (EPosWidgetQuotes* self);
void epos_widget_quotes_OnButtonNewClicked (EPosWidgetQuotes* self);
void epos_widget_quotes_OnButtonEditClicked (EPosWidgetQuotes* self);
void epos_widget_quotes_OnButtonDeleteClicked (EPosWidgetQuotes* self);
void epos_widget_quotes_OnButtonPreviewClicked (EPosWidgetQuotes* self);
void epos_widget_quotes_RefreshQuotes (EPosWidgetQuotes* self);
void epos_widget_quotes_GetQuotes (EPosWidgetQuotes* self, gint store_id, const gchar* status, gint page, gint limit);


G_END_DECLS

#endif
