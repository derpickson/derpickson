/* gtk-hello.c generated by valac 0.36.12, the Vala compiler
 * generated from gtk-hello.vala, do not modify */

/*
* Copyright (c) 2011-2018 Nick Derrickson (https://github.com/derpickson)
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this program; if not, write to the
* Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
* Boston, MA 02110-1301 USA
*
* Authored by: Nick Derrickson <derpickson@protonmail.com>
*/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <pango/pango.h>
#include <gio/gio.h>
#include <glib/gi18n-lib.h>
#include <stdlib.h>
#include <string.h>


#define TYPE_MY_APP (my_app_get_type ())
#define MY_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MY_APP, MyApp))
#define MY_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MY_APP, MyAppClass))
#define IS_MY_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MY_APP))
#define IS_MY_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MY_APP))
#define MY_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MY_APP, MyAppClass))

typedef struct _MyApp MyApp;
typedef struct _MyAppClass MyAppClass;
typedef struct _MyAppPrivate MyAppPrivate;
typedef struct _Block1Data Block1Data;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _MyApp {
	GtkApplication parent_instance;
	MyAppPrivate * priv;
};

struct _MyAppClass {
	GtkApplicationClass parent_class;
};

struct _MyAppPrivate {
	PangoAlignment _align;
	gboolean _justify;
};

struct _Block1Data {
	int _ref_count_;
	MyApp* self;
	GtkButton* button_timestart;
	GtkButton* button_timestop;
};


static gpointer my_app_parent_class = NULL;

GType my_app_get_type (void) G_GNUC_CONST;
#define MY_APP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_MY_APP, MyAppPrivate))
enum  {
	MY_APP_0_PROPERTY,
	MY_APP_ALIGN_PROPERTY,
	MY_APP_JUSTIFY_PROPERTY
};
MyApp* my_app_new (void);
MyApp* my_app_construct (GType object_type);
static void my_app_real_activate (GApplication* base);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void __lambda4_ (Block1Data* _data1_);
static void ___lambda4__gtk_button_clicked (GtkButton* _sender, gpointer self);
static void __lambda5_ (Block1Data* _data1_);
static void ___lambda5__gtk_button_clicked (GtkButton* _sender, gpointer self);
gint my_app_main (gchar** args, int args_length1);
PangoAlignment my_app_get_align (MyApp* self);
void my_app_set_align (MyApp* self, PangoAlignment value);
gboolean my_app_get_justify (MyApp* self);
void my_app_set_justify (MyApp* self, gboolean value);
static void my_app_finalize (GObject * obj);
static void _vala_my_app_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_my_app_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


MyApp* my_app_construct (GType object_type) {
	MyApp * self = NULL;
#line 27 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self = (MyApp*) g_object_new (object_type, "application-id", "com.github.derpickson.derpickson", "flags", G_APPLICATION_FLAGS_NONE, NULL);
#line 26 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return self;
#line 105 "gtk-hello.c"
}


MyApp* my_app_new (void) {
#line 26 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return my_app_construct (TYPE_MY_APP);
#line 112 "gtk-hello.c"
}


static Block1Data* block1_data_ref (Block1Data* _data1_) {
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_atomic_int_inc (&_data1_->_ref_count_);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return _data1_;
#line 121 "gtk-hello.c"
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
#line 130 "gtk-hello.c"
		MyApp* self;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		self = _data1_->self;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		_g_object_unref0 (_data1_->button_timestop);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		_g_object_unref0 (_data1_->button_timestart);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		_g_object_unref0 (self);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		g_slice_free (Block1Data, _data1_);
#line 142 "gtk-hello.c"
	}
}


static void __lambda4_ (Block1Data* _data1_) {
	MyApp* self;
#line 51 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self = _data1_->self;
#line 53 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->button_timestart, FALSE);
#line 54 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->button_timestop, TRUE);
#line 155 "gtk-hello.c"
}


static void ___lambda4__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 51 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	__lambda4_ (self);
#line 162 "gtk-hello.c"
}


static void __lambda5_ (Block1Data* _data1_) {
	MyApp* self;
#line 56 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self = _data1_->self;
#line 57 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->button_timestart, TRUE);
#line 58 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->button_timestop, FALSE);
#line 174 "gtk-hello.c"
}


static void ___lambda5__gtk_button_clicked (GtkButton* _sender, gpointer self) {
#line 56 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	__lambda5_ (self);
#line 181 "gtk-hello.c"
}


static void my_app_real_activate (GApplication* base) {
	MyApp * self;
	Block1Data* _data1_;
	GtkApplicationWindow* main_window = NULL;
	GtkApplicationWindow* _tmp0_;
	GtkGrid* grid = NULL;
	GtkGrid* _tmp1_;
	GtkButton* _tmp2_;
	GtkButton* _tmp3_;
	GtkListStore* list_store = NULL;
	GtkListStore* _tmp4_;
	GtkTreeIter iter = {0};
	GtkTreeView* view = NULL;
	GtkTreeView* _tmp5_;
	GtkCellRendererText* cell = NULL;
	GtkCellRendererText* _tmp6_;
	GtkTreeIter _tmp7_ = {0};
	GtkTreeIter _tmp8_;
	GtkTreeIter _tmp9_ = {0};
	GtkTreeIter _tmp10_;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self = (MyApp*) base;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_ = g_slice_new0 (Block1Data);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_->_ref_count_ = 1;
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_->self = g_object_ref (self);
#line 34 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp0_ = (GtkApplicationWindow*) gtk_application_window_new ((GtkApplication*) self);
#line 34 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp0_);
#line 34 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	main_window = _tmp0_;
#line 35 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp1_ = (GtkGrid*) gtk_grid_new ();
#line 35 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp1_);
#line 35 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	grid = _tmp1_;
#line 36 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp2_ = (GtkButton*) gtk_button_new_with_label (_ ("Start Time"));
#line 36 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp2_);
#line 36 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_->button_timestart = _tmp2_;
#line 37 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp3_ = (GtkButton*) gtk_button_new_with_label (_ ("Stop Time"));
#line 37 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp3_);
#line 37 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_->button_timestop = _tmp3_;
#line 39 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp4_ = gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_STRING, -1);
#line 39 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	list_store = _tmp4_;
#line 41 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp5_ = (GtkTreeView*) gtk_tree_view_new_with_model ((GtkTreeModel*) list_store);
#line 41 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp5_);
#line 41 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	view = _tmp5_;
#line 42 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp6_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
#line 42 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_ref_sink (_tmp6_);
#line 42 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	cell = _tmp6_;
#line 43 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_tree_view_insert_column_with_attributes (view, -1, "First", (GtkCellRenderer*) cell, "text", 0, NULL);
#line 44 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_tree_view_insert_column_with_attributes (view, -1, "Second", (GtkCellRenderer*) cell, "text", 1, NULL);
#line 46 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_list_store_append (list_store, &_tmp7_);
#line 46 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	iter = _tmp7_;
#line 47 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp8_ = iter;
#line 47 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_list_store_set (list_store, &_tmp8_, 0, "What", 1, "What2", -1);
#line 48 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_list_store_append (list_store, &_tmp9_);
#line 48 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	iter = _tmp9_;
#line 49 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp10_ = iter;
#line 49 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_list_store_set (list_store, &_tmp10_, 0, "What", 1, "What2", -1);
#line 50 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_set_sensitive ((GtkWidget*) _data1_->button_timestop, FALSE);
#line 51 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_signal_connect_data (_data1_->button_timestart, "clicked", (GCallback) ___lambda4__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 56 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_signal_connect_data (_data1_->button_timestop, "clicked", (GCallback) ___lambda5__gtk_button_clicked, block1_data_ref (_data1_), (GClosureNotify) block1_data_unref, 0);
#line 62 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_grid_set_row_spacing (grid, 6);
#line 63 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_grid_set_column_spacing (grid, 6);
#line 64 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_set ((GtkWidget*) grid, "margin", 12, NULL);
#line 66 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_grid_attach (grid, (GtkWidget*) view, 0, 0, 4, 1);
#line 67 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_grid_attach (grid, (GtkWidget*) _data1_->button_timestart, 0, 1, 2, 1);
#line 68 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_grid_attach (grid, (GtkWidget*) _data1_->button_timestop, 2, 1, 2, 1);
#line 70 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_set ((GtkWindow*) main_window, "default-height", 300, NULL);
#line 71 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_set ((GtkWindow*) main_window, "default-width", 300, NULL);
#line 72 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_window_set_title ((GtkWindow*) main_window, _ ("Tracker"));
#line 73 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_container_add ((GtkContainer*) main_window, (GtkWidget*) grid);
#line 74 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	gtk_widget_show_all ((GtkWidget*) main_window);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (cell);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (view);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (list_store);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (grid);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (main_window);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	block1_data_unref (_data1_);
#line 33 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_data1_ = NULL;
#line 315 "gtk-hello.c"
}


gint my_app_main (gchar** args, int args_length1) {
	gint result = 0;
	MyApp* app = NULL;
	MyApp* _tmp0_;
	gchar** _tmp1_;
	gint _tmp1__length1;
	gint _tmp2_;
#line 115 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp0_ = my_app_new ();
#line 115 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	app = _tmp0_;
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp1_ = args;
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp1__length1 = args_length1;
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp2_ = g_application_run ((GApplication*) app, _tmp1__length1, _tmp1_);
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	result = _tmp2_;
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_g_object_unref0 (app);
#line 116 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return result;
#line 342 "gtk-hello.c"
}


int main (int argc, char ** argv) {
#if !GLIB_CHECK_VERSION (2,35,0)
	g_type_init ();
#endif
#line 114 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return my_app_main (argv, argc);
#line 352 "gtk-hello.c"
}


PangoAlignment my_app_get_align (MyApp* self) {
	PangoAlignment result;
	PangoAlignment _tmp0_;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp0_ = self->priv->_align;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	result = _tmp0_;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return result;
#line 367 "gtk-hello.c"
}


void my_app_set_align (MyApp* self, PangoAlignment value) {
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_return_if_fail (self != NULL);
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	if (my_app_get_align (self) != value) {
#line 376 "gtk-hello.c"
		PangoAlignment _tmp0_;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		_tmp0_ = value;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		self->priv->_align = _tmp0_;
#line 24 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		g_object_notify ((GObject *) self, "align");
#line 384 "gtk-hello.c"
	}
}


gboolean my_app_get_justify (MyApp* self) {
	gboolean result;
	gboolean _tmp0_;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_return_val_if_fail (self != NULL, FALSE);
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	_tmp0_ = self->priv->_justify;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	result = _tmp0_;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	return result;
#line 400 "gtk-hello.c"
}


void my_app_set_justify (MyApp* self, gboolean value) {
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_return_if_fail (self != NULL);
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	if (my_app_get_justify (self) != value) {
#line 409 "gtk-hello.c"
		gboolean _tmp0_;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		_tmp0_ = value;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		self->priv->_justify = _tmp0_;
#line 25 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		g_object_notify ((GObject *) self, "justify");
#line 417 "gtk-hello.c"
	}
}


static void my_app_class_init (MyAppClass * klass) {
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	my_app_parent_class = g_type_class_peek_parent (klass);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_type_class_add_private (klass, sizeof (MyAppPrivate));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication *)) my_app_real_activate;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	G_OBJECT_CLASS (klass)->get_property = _vala_my_app_get_property;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	G_OBJECT_CLASS (klass)->set_property = _vala_my_app_set_property;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	G_OBJECT_CLASS (klass)->finalize = my_app_finalize;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), MY_APP_ALIGN_PROPERTY, g_param_spec_enum ("align", "align", "align", pango_alignment_get_type (), 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	g_object_class_install_property (G_OBJECT_CLASS (klass), MY_APP_JUSTIFY_PROPERTY, g_param_spec_boolean ("justify", "justify", "justify", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
#line 439 "gtk-hello.c"
}


static void my_app_instance_init (MyApp * self) {
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self->priv = MY_APP_GET_PRIVATE (self);
#line 446 "gtk-hello.c"
}


static void my_app_finalize (GObject * obj) {
	MyApp * self;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MY_APP, MyApp);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	G_OBJECT_CLASS (my_app_parent_class)->finalize (obj);
#line 456 "gtk-hello.c"
}


GType my_app_get_type (void) {
	static volatile gsize my_app_type_id__volatile = 0;
	if (g_once_init_enter (&my_app_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (MyAppClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) my_app_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (MyApp), 0, (GInstanceInitFunc) my_app_instance_init, NULL };
		GType my_app_type_id;
		my_app_type_id = g_type_register_static (gtk_application_get_type (), "MyApp", &g_define_type_info, 0);
		g_once_init_leave (&my_app_type_id__volatile, my_app_type_id);
	}
	return my_app_type_id__volatile;
}


static void _vala_my_app_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	MyApp * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_MY_APP, MyApp);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	switch (property_id) {
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		case MY_APP_ALIGN_PROPERTY:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		g_value_set_enum (value, my_app_get_align (self));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		case MY_APP_JUSTIFY_PROPERTY:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		g_value_set_boolean (value, my_app_get_justify (self));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 489 "gtk-hello.c"
		default:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 495 "gtk-hello.c"
	}
}


static void _vala_my_app_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	MyApp * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, TYPE_MY_APP, MyApp);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
	switch (property_id) {
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		case MY_APP_ALIGN_PROPERTY:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		my_app_set_align (self, g_value_get_enum (value));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		case MY_APP_JUSTIFY_PROPERTY:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		my_app_set_justify (self, g_value_get_boolean (value));
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 517 "gtk-hello.c"
		default:
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
#line 22 "/home/nick/Projects/derpickson/src/gtk-hello.vala"
		break;
#line 523 "gtk-hello.c"
	}
}



