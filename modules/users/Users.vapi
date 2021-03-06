/* Users.vapi generated by valac 0.24.0, do not modify. */

namespace EPos {
	[CCode (cheader_filename = "Users.h")]
	public class SBUsersHelper {
		public SBUsersHelper ();
		public static GLib.List<SinticBolivia.SBRole> GetRoles ();
	}
	[CCode (cheader_filename = "Users.h")]
	public class SB_ModuleUsers : SinticBolivia.Gtk.SBGtkModule, SinticBolivia.ISBModule {
		public SB_ModuleUsers ();
		public static void init_menu_management (SinticBolivia.SBModuleArgs<Gtk.Menu> args);
		public static void local_authentication (SinticBolivia.SBModuleArgs<Gee.HashMap> args);
		public static void login_dialog (SinticBolivia.SBModuleArgs<Gee.HashMap> args);
	}
	[CCode (cheader_filename = "Users.h")]
	public class WindowLogin : Gtk.Window {
		protected Gtk.Box box1;
		protected Gtk.Box boxFooter;
		protected Gtk.Button buttonCancel;
		protected Gtk.Button buttonSignIn;
		protected int currentImg;
		protected Gtk.Entry entryPassword;
		protected Gtk.Entry entryUsername;
		protected Gtk.EventBox eventbox1;
		protected Gtk.Fixed fixed1;
		protected uint timeoutId;
		protected Gtk.Builder ui;
		public WindowLogin ();
		public void Build ();
		protected void OnButtonLoginClicked ();
		protected void SetEvents ();
	}
}
[CCode (cheader_filename = "Users.h")]
public static GLib.Type sb_get_module_libusers_type (GLib.Module users_module);
