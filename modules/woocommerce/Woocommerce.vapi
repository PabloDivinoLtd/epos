/* Woocommerce.vapi generated by valac.exe 0.24.0, do not modify. */

namespace EPos {
	namespace Woocommerce {
		[CCode (cheader_filename = "Woocommerce.h")]
		public class SBWCSync : GLib.Object {
			protected EPos.Woocommerce.WC_Api_Client _api;
			public SBWCSync (string wp_url, string api_key, string api_secret);
			protected void FixCategoriesParent (int store_id);
			protected void FixProductsCategories (int store_id);
			public long SyncCategories (int store_id);
			public void SyncCustomers (int store_id);
			public long SyncProducts (int store_id);
			public long SyncStore ();
			public SinticBolivia.Database.SBDatabase Dbh { get; set; }
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class SB_ModuleWoocommerce : SinticBolivia.Gtk.SBGtkModule, SinticBolivia.ISBModule {
			public SB_ModuleWoocommerce ();
			protected void AddHooks ();
			protected bool SyncOrders ();
			protected void hook_before_register_sale (SinticBolivia.SBModuleArgs<Gee.HashMap> args);
			protected void hook_init_menu_management (SinticBolivia.SBModuleArgs<Gtk.Menu> args);
			protected void hook_modules_loaded (SinticBolivia.SBModuleArgs<string> args);
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WCHelper : GLib.Object {
			public WCHelper ();
			public static Gee.ArrayList<EPos.ESale> GetOrders (int store_id, string status = "", SinticBolivia.Database.SBDatabase? _dbh = null);
			public static Gee.ArrayList<EPos.ESale> GetOrdersPendingToSync (int store_id, SinticBolivia.Database.SBDatabase? _dbh = null);
			public static Gee.ArrayList<Gee.HashMap> GetProducts (int store_id);
			public static SinticBolivia.SBStore GetStore (int id);
			public static Gee.ArrayList<SinticBolivia.SBDbObject> GetStoreCustomers (int store_id, SinticBolivia.Database.SBDatabase? _dbh = null);
			public static Gee.ArrayList<SinticBolivia.SBStore> GetStores ();
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WC_Api_Client : GLib.Object {
			protected string _apiEndPoint;
			protected string _apiUrl;
			protected string _consumerKey;
			protected string _consumerSecret;
			protected string _endPoint;
			protected Soup.MessageHeaders _responseHeaders;
			protected string _signatureMethod;
			protected string _wordpressUrl;
			public bool debug;
			public WC_Api_Client (string wordpress_url, string api_key, string api_secret);
			public Json.Object Authenticate (string username, string pass);
			public Json.Object CreateCustomer (Gee.HashMap<string,string> data);
			public Gee.ArrayList<Gee.HashMap<string,GLib.Value?>> GetCategories (int limit = 100, int page = 1, out int total_cats, out int total_pages);
			public Gee.ArrayList<Gee.HashMap<string,GLib.Value?>> GetCustomers (int limit, int page, out int total_customers, out int total_pages);
			public Gee.ArrayList<Gee.HashMap<string,GLib.Value?>> GetProducts (int limit, int page, out int total_products, out int total_pages);
			public Json.Object GetStoreData ();
			public Gee.HashMap<string,GLib.Value?> PlaceOrder (Gee.HashMap<string,string>? args = null);
			public Json.Array SearchCustomerByName (string name);
			protected string _getSignature (string endpoint, string query_string, string method);
			protected string _makeApiCall (string endpoint, owned Gee.HashMap<string,string>? args = null, string method = "GET", bool send_raw = false);
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WidgetWoocommerceCategories : Gtk.Box {
			protected enum Columns {
				COUNT,
				ID,
				WOO_ID,
				NAME,
				DESCRIPTION,
				SLUG,
				PRODUCTS_COUNT,
				N_COLS
			}
			protected Gtk.Box box1;
			protected Gtk.Button buttonSync;
			protected Gtk.ComboBox comboboxParent;
			protected Gtk.ComboBox comboboxStore;
			protected Gtk.Entry entryName;
			protected Gtk.Entry entrySlug;
			protected Gtk.Image image1;
			protected int storeId;
			protected Gtk.TextView textviewDescription;
			protected Gtk.TreeView treeviewCategories;
			protected Gtk.Builder ui;
			public WidgetWoocommerceCategories ();
			protected void Build ();
			protected void OnButtonSyncClicked ();
			protected void OnComboBoxStoreChanged ();
			protected void RefreshCategories (int store_id);
			protected void SetEvents ();
			protected int SyncCategories ();
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WidgetWoocommerceCustomers : Gtk.Box {
			protected enum Columns {
				SELECT,
				COUNT,
				IMAGE,
				ID,
				WOO_ID,
				FIRST_NAME,
				LAST_NAME,
				EMAIL,
				N_COLS
			}
			protected Gtk.Box box1;
			protected Gtk.Button buttonDetails;
			protected Gtk.Button buttonSync;
			protected Gtk.ComboBox comboboxStore;
			protected Gtk.Image image1;
			protected int storeId;
			protected Gtk.TreeView treeviewCustomers;
			protected Gtk.Builder ui;
			public WidgetWoocommerceCustomers ();
			protected void Build ();
			protected void OnButtonSyncClicked ();
			protected void OnCamboBoxStoreChanged ();
			protected void Refresh (int store_id);
			protected void SetEvents ();
			protected int SyncCustomers ();
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WidgetWoocommerceProducts : Gtk.Box {
			protected enum Columns {
				SELECT,
				COUNT,
				IMAGE,
				ID,
				WOO_ID,
				TITLE,
				SKU,
				QUANTITY,
				PRICE,
				CATEGORIES,
				N_COLS
			}
			protected Gtk.Box box1;
			protected Gtk.Button buttonDetails;
			protected Gtk.Button buttonSync;
			protected Gtk.ComboBox comboboxCategories;
			protected Gtk.ComboBox comboboxSearchBy;
			protected Gtk.ComboBox comboboxStore;
			protected Gtk.Entry entrySearch;
			protected Gtk.Image image1;
			protected bool lockCategoriesEvent;
			protected int storeId;
			protected Gtk.TreeView treeviewProducts;
			protected Gtk.Builder ui;
			public WidgetWoocommerceProducts ();
			protected void Build ();
			protected void OnButtonSyncClicked ();
			protected void OnComboBoxStoreChanged ();
			protected void RefreshProducts (int store_id, int cat_id = 0);
			protected void SetEvents ();
			protected void SetStoreCategories (int store_id);
			protected int SyncProducts ();
		}
		[CCode (cheader_filename = "Woocommerce.h")]
		public class WidgetWoocommerceStores : Gtk.Box {
			protected Gtk.Box box1;
			protected Gtk.Button buttonCancel;
			protected Gtk.Button buttonDelete;
			protected Gtk.Button buttonEdit;
			protected Gtk.Button buttonNew;
			protected Gtk.Button buttonSave;
			protected Gtk.Entry entryKey;
			protected Gtk.Entry entryName;
			protected Gtk.Entry entrySecret;
			protected Gtk.Entry entryUrl;
			protected Gtk.Image image1;
			protected int storeId;
			protected Gtk.TreeView treeviewStores;
			protected Gtk.Builder ui;
			public WidgetWoocommerceStores ();
			protected void Build ();
			protected void OnButtonEditClicked ();
			protected void OnButtonNewClicked ();
			protected void OnButtonSaveClicked ();
			protected void RefreshStores ();
			protected void Reset ();
			protected void SetEvents ();
		}
	}
}
namespace HMAC {
}
[CCode (cheader_filename = "Woocommerce.h")]
public static GLib.Type sb_get_module_libwoocommerce_type (GLib.Module mod);
