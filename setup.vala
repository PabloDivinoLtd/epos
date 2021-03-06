using GLib;
using Gee;
using Gtk;
using SinticBolivia;
using SinticBolivia.Gtk;
using SinticBolivia.Database;

namespace Woocommerce
{
	public class Setup : Object
	{
		protected 	Builder		ui;
		public		Window		window;
		protected	Notebook	notebook;
		protected	RadioButton	radiobuttonServer;
		protected	RadioButton	radiobuttonTerminal;
		protected	RadioButton	radiobuttonMysql;
		protected	RadioButton	radiobuttonSqlite3;
		protected	Entry		entryServer;
		protected	Entry		entryPort;
		protected	Entry		entryDatabase;
		protected	Entry		entryUsername;
		protected	Entry		entryPassword;
		protected	Entry		entryAdminUsername;
		protected	Entry		entryAdminPassword;
		protected	Button		buttonTestConnection;
		protected	CheckButton	checkbuttonLaunch;
		protected	Button		buttonCancel;
		protected	Button		buttonPrev;
		protected	Button		buttonNext;
		protected	Button		buttonFinish;
		protected	GLib.Resource	resource;
		public Setup()
		{
			this.resource = GtkHelper.LoadResource("share/resources/ec-pos.gresource");
			this.ui = GtkHelper.GetGladeUIFromResource(this.resource, "/net/sinticbolivia/ec-pos/ui/setup.glade");
			this.window					= (Window)this.ui.get_object("window1");
			this.window.show();
			this.notebook				= (Notebook)this.ui.get_object("notebook1");
			this.notebook.show();

			this.radiobuttonServer		= (RadioButton)this.ui.get_object("radiobuttonServer");
			this.radiobuttonTerminal	= (RadioButton)this.ui.get_object("radiobuttonTerminal");
			this.radiobuttonMysql		= (RadioButton)this.ui.get_object("radiobuttonMysql");
			this.radiobuttonSqlite3		= (RadioButton)this.ui.get_object("radiobuttonSqlite3");

			this.entryServer			= (Entry)this.ui.get_object("entryServer");
			this.entryPort				= (Entry)this.ui.get_object("entryPort");
			this.entryDatabase			= (Entry)this.ui.get_object("entryDatabase");
			this.entryUsername			= (Entry)this.ui.get_object("entryUsername");
			this.entryPassword			= (Entry)this.ui.get_object("entryPassword");
			this.entryAdminUsername		= (Entry)this.ui.get_object("entryAdminUsername");
			this.entryAdminPassword		= (Entry)this.ui.get_object("entryAdminPassword");
			this.checkbuttonLaunch		= (CheckButton)this.ui.get_object("checkbuttonLaunch");
			this.buttonTestConnection	= (Button)this.ui.get_object("buttonTestConnection");
			this.buttonCancel			= (Button)this.ui.get_object("buttonCancel");
			this.buttonPrev				= (Button)this.ui.get_object("buttonPrev");
			this.buttonNext				= (Button)this.ui.get_object("buttonNext");
			this.buttonFinish			= (Button)this.ui.get_object("buttonFinish");

			this.window.title 			= SBText.__("Ecommerce Point of Sale - Setup");
			//this.notebook.show_tabs = false;
			this.notebook.page = 0;
			this.buttonPrev.visible 	= false;
			this.buttonFinish.visible 	= false;


			this.entryServer.text 				= "localhost";
			this.entryAdminUsername.text 		= "admin";
			this.entryAdminUsername.editable 	= false;
			this.SetEvents();

		}
		protected void SetEvents()
		{
			//stderr.printf("setting events\n");
			this.buttonTestConnection.clicked.connect(this.OnButtonTestConnectionClicked);
			this.buttonCancel.clicked.connect(this.OnButtonCancelClicked);
			this.buttonPrev.clicked.connect(this.OnButtonPrevClicked);
			this.buttonNext.clicked.connect(this.OnButtonNextClicked);
			this.buttonFinish.clicked.connect(this.OnButtonFinishClicked);

		}
		public void show()
		{
			this.window.show();
		}
		protected void OnButtonCancelClicked()
		{
			this.window.destroy();
		}
		protected void OnButtonTestConnectionClicked()
		{
			//stdout.printf("testing connection\n");
			string server = this.entryServer.text.strip();
			int	port		= int.parse(this.entryPort.text.strip());
			string db	  = this.entryDatabase.text.strip();
			string user		= this.entryUsername.text.strip();
			string pass		= this.entryPassword.text.strip();

			SBDatabase dbh = null;

			if( this.radiobuttonMysql.active )
			{
				dbh = new SBMySQL(server, null, user, pass, port);
			}
			else if( this.radiobuttonSqlite3.active )
			{
				dbh = new SBSQLite(server);
			}
			if( dbh.Open() )
			{
				var msg = new MessageDialog(this.window, DialogFlags.MODAL, MessageType.INFO, ButtonsType.CLOSE,
					SBText.__("Connection succesfull.")
				);
				msg.run();
				msg.destroy();
				dbh.Close();
			}
			else
			{
				var msg = new MessageDialog(this.window, DialogFlags.MODAL, MessageType.ERROR, ButtonsType.CLOSE,
					SBText.__("Error trying to connect with database.")
				);
				msg.run();
				msg.destroy();
			}
		}
		protected void OnButtonPrevClicked()
		{
			int total_pages = this.notebook.get_n_pages() - 1;
			//int current_page = this.notebook.page;

			this.notebook.page = this.notebook.page - 1;
			if( this.notebook.page == 0 )
			{
				this.buttonPrev.visible = false;
				this.buttonFinish.visible = false;
				this.buttonNext.visible = true;
			}
			if( this.notebook.page < total_pages )
			{
				this.buttonNext.visible = true;
				this.buttonFinish.visible = false;
			}
		}
		protected void OnButtonNextClicked()
		{
			int total_pages = this.notebook.get_n_pages() - 1;
			/*
			if( this.notebook.page + 1 == total_pages )
			{
				this.buttonNext.visible = false;
				this.buttonFinish.visible = true;
			}
			*/
			this.notebook.page = this.notebook.page + 1;
			if( this.notebook.page > 0 && this.notebook.page <= total_pages )
			{
				this.buttonPrev.visible = true;
			}
			else
			{
				this.buttonPrev.visible = false;
			}

			if( this.notebook.page == total_pages )
			{
				this.buttonFinish.visible = true;
				this.buttonNext.visible = false;
			}
			else
			{
				this.buttonFinish.visible = false;
				this.buttonNext.visible = true;
			}
		}
		protected void OnButtonFinishClicked()
		{
			string server 		= this.entryServer.text.strip();
			int port			= int.parse(this.entryPort.text.strip());
			string db	  		= this.entryDatabase.text.strip();
			string user			= this.entryUsername.text.strip();
			string pass			= this.entryPassword.text.strip();
			string username		= this.entryAdminUsername.text.strip();
			string user_pass	= this.entryAdminPassword.text.strip();
			SBDatabase dbh = null;
			string res_path = "";
			string db_engine = "";
			if( this.radiobuttonMysql.active )
			{
				db_engine = "mysql";
				dbh = new SBMySQL(server, null, user, pass, port);
				res_path = "/net/sinticbolivia/ec-pos/sql/database.mysql.sql";
				//dbh.SelectDb(db);
			}
			else if( this.radiobuttonSqlite3.active )
			{
				if( !FileUtils.test("db", FileTest.IS_DIR) )
				{
					DirUtils.create("db", 0777);
				}
				db_engine = "sqlite3";
				server = "ec-pos.sqlite";
				dbh = new SBSQLite("db/%s".printf(server));
				res_path = "/net/sinticbolivia/ec-pos/sql/database.sqlite3.sql";
			}
			stdout.printf("Database engine selected: %s\n", db_engine);
			if( !dbh.Open() )
			{
				var msg = new MessageDialog(this.window, DialogFlags.MODAL, MessageType.ERROR, ButtonsType.CLOSE,
					SBText.__("Error trying to connect with database.")
				);
				msg.run();
				msg.destroy();
				return;
			}
			if( db_engine == "mysql" )
			{
				dbh.Execute("CREATE DATABASE %s;".printf(db));
				dbh.SelectDb(db);
			}

			
			try
			{
				stdout.printf("Opening resource path: %s\n", res_path);
				var istream 	= this.resource.open_stream(res_path, ResourceLookupFlags.NONE);
				var ds 			= new DataInputStream(istream);
				string sql 		= "";
				string? line 	= "";
				while( (line = ds.read_line()) != null )
				{
					sql += line;
				}
				//stdout.printf(sql);
				string[] queries = sql.split(";");

				foreach(string q in queries)
				{
					if( q.strip().length <= 0 ) continue;
					dbh.Execute(q);
				}

			}
			catch(GLib.Error e)
			{
				stdout.printf("ERROR LOADING RESOURCE: %s\n", e.message);
			}
			this.CreateRoles(dbh);
			//##create admin user
			string query = "SELECT user_id FROM users WHERE username = 'admin' and role_id = 1";
			if( dbh.GetRow(query) == null )
			{
				string cdate = new DateTime.now_local().format("%Y-%m-%d %H:%M:%S");
				string password = Checksum.compute_for_string(ChecksumType.MD5, user_pass);
				var data = new HashMap<string, Value?>();
				data.set("first_name", "Admin");
				data.set("last_name", "Admin");
				data.set("username", "admin");
				data.set("pwd", password);
				data.set("role_id", 1);
				data.set("store_id", 0);
				data.set("last_modification_date", cdate);
				data.set("creation_date", cdate);
				dbh.Insert("users", data);
			}

			dbh.Close();
			//##write config file
			var cfg = new SBConfig("config.xml", "point_of_sale");
			cfg.SetValue("database_engine", db_engine);
			cfg.SetValue("db_server", server);
			cfg.SetValue("db_port", port.to_string());
			cfg.SetValue("db_name", db);
			cfg.SetValue("db_user", user);
			cfg.SetValue("db_pass", pass);
			cfg.Save();
			if( this.checkbuttonLaunch.active )
			{
				if( SBOS.GetOS().IsLinux() )
					GLib.Process.spawn_command_line_async("./run-ec-pos.sh");
				else
					GLib.Process.spawn_command_line_async("ec-pos.exe");
			}
			this.window.destroy();
		}
		protected void CreateRoles(SBDatabase dbh)
		{
			string cdate = new DateTime.now_local().format("%Y-%m-%d %H:%M:%S");
			string[,] roles = {
				{SBText.__("Administrator"), ""},
				{SBText.__("Cashier"), ""}
			};
			for(int i = 0; i < roles.length[0]; i++)
			{
				string q0 = "SELECT role_id FROM user_roles WHERE role_name = '%s'".printf(roles[i, 0]);
				if( dbh.GetRow(q0) == null )
				{
					var data = new HashMap<string, Value?>();
					data.set("role_name", roles[i, 0]);
					data.set("last_modification_date", cdate);
					data.set("creation_date", cdate);
					dbh.Insert("user_roles", data);
				}
			}
		}
	}
	public static void main(string[] args)
	{
		Gtk.init(ref args);
		var setup = new Setup();
		setup.window.modal = true;
		setup.show();

		setup.window.destroy.connect( () =>
		{
			Gtk.main_quit();
		});
		Gtk.main();
	}
}
