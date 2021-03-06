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

public class MyApp : Gtk.Application {

    public Pango.Alignment align {get;set;}
    public bool justify {get;set;}
    //public SelectionMode mode { set; get; }
    public MyApp () {
        Object (
            application_id: ("com.github.derpickson.derpickson"),
            flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
        var main_window = new Gtk.ApplicationWindow (this);
        var scrolled_window = new Gtk.ScrolledWindow (null, null);
        var grid = new Gtk.Grid ();
        var button_timestart = new Gtk.Button.with_label (_("Start Time"));
        var button_timestop = new Gtk.Button.with_label (_("Stop Time"));
        var button_addtask = new Gtk.Button.with_label (_("Add New Task"));
        var button_addsubtask = new Gtk.Button.with_label (_("Add New Subtask"));
        var button_delete = new Gtk.Button.with_label (_("Delete"));
        
        //Gtk.MessageDialog msg = new Gtk.MessageDialog (this, Gtk.DialogFlags.MODAL, Gtk.MessageType.WARNING, Gtk.ButtonsType.OK_CANCEL, "My message!");
        //msg.show ();
        Gtk.ListStore list_store = new Gtk.ListStore(3, typeof (string), typeof (string), typeof(string));
        Gtk.TreeIter iter;
        Gtk.TreeView view = new Gtk.TreeView.with_model (list_store);
        view.expand = true;
        //view.set_resizeable = true;
        //view.columns_autosize = true;
        Gtk.CellRendererText cell = new Gtk.CellRendererText ();
        view.insert_column_with_attributes (-1, "Main Task", cell, "text", 0);
        view.insert_column_with_attributes (-1, "Sub-task", cell, "text", 1);
        view.insert_column_with_attributes (-1, "Time", cell, "text", 2);
        view.get_column (0).min_width = 75;
        view.get_column (1).min_width = 100;
        //var selection = new Gtk.TreeSelection();
        //selection.get_selected(out view, out iter);

        list_store.append (out iter);
        list_store.set (iter, 0, "Create Tracker App", 1, "", 2, "");
        list_store.append (out iter);
        list_store.set (iter, 0, "", 1, "Code GUI", 2, "1m 50s");
        //list_store.set (iter, 0, "Create Tracker App", 1, "Code", 2, "a");
        button_timestop.sensitive = false;
        button_timestart.clicked.connect (() => {
            //button_timestart.label = (_("Time Started"));
            button_timestart.sensitive = false;
            button_timestop.sensitive = true;
        });
        button_timestop.clicked.connect (() => {
            button_timestart.sensitive = true;
            button_timestop.sensitive = false;
        });
        button_addtask.clicked.connect (() => {
            //Gtk.Entry entry = new Gtk.Entry ();
            //main_window.add (entry);
            //entry.set_text (_("Input Task Name"));
            list_store.append (out iter);
            list_store.set (iter, 0, "Task1");
        });
        button_addsubtask.clicked.connect (() => {
            var name = "name";
            
            //view.get_selection().changed.connect (name);
            list_store.append (out iter);
            list_store.set (iter, 1, name);
        });
        //grid.orientation = Gtk.Orientation.VERTICAL;
        grid.row_spacing = 6;
        grid.column_spacing = 6;
        grid.margin = 12;
        //scrolled_window.set_border_width (10);
        scrolled_window.set_min_content_height (150);
        scrolled_window.set_kinetic_scrolling (true);

        grid.attach (scrolled_window, 0, 1, 10, 10);
        scrolled_window.add (view);
        //grid.attach (view, 0, 1, 10, 1);
        grid.attach (button_timestart, 0, 0, 2, 1);
        grid.attach (button_timestop, 2, 0, 2, 1);
        grid.attach (button_addtask, 4, 0, 2, 1);
        grid.attach (button_addsubtask, 6, 0, 2, 1);
        grid.attach (button_delete, 8, 0, 2, 1);
        
        main_window.default_height = 300;
        main_window.default_width = 600;
        main_window.title = (_("Tracker"));
        //grid.add (scrolled_window);
        main_window.add (grid);
        //scrolled_window.add (grid);
        //main_window.add (scrolled_window);
        main_window.show_all ();

        //var time
        //public void set_alignment (1, 0);
        //title_label.set_markup(wrapInTags(post.title));
        //title_label.set_line_wrap(true);
        //title_label.wrap_mode = Pango.WrapMode.WORD_CHAR;
        //title_label.set_justify = Pango.Layout.set_justify(CENTER);
        //title_label.set_justify(Gtk.Justification.RIGHT);
        //title_label.set_xalign(0);
        //grid.attach (title_label, 0, 0, 1, 1);
        /*var button = new Gtk.Button.with_label (_("Click Me!"));
        var label = new Gtk.Label (null);
        var rotate_button = new Gtk.Button.with_label (_("Rotate"));
        var rotate_label = new Gtk.Label (_("Horizontal"));
        grid.attach (button, 0, 0, 1, 1);
        grid.attach_next_to (label, button, Gtk.PositionType.RIGHT, 1, 1);
        grid.attach (rotate_button, 0, 1, 1, 1);
        grid.attach_next_to (rotate_label, rotate_button, Gtk.PositionType.RIGHT, 1, 1);
        //grid.add (button);
        //grid.add (label);
        //grid.add (new Gtk.Label (_("Label 1")));
        //grid.add (new Gtk.Label (_("Label 2")));
        button.clicked.connect (() => {
            //label.label = (_("Hello World! Testing length"));
            var notification = new Notification (_("Tracker"));
            var icon = new GLib.ThemedIcon ("dialog-warning");
            notification.set_icon (icon);
            notification.set_body (_("Times up, fool!"));
            this.send_notification ("Tracker", notification);
            button.sensitive = true;
        });
        rotate_label.angle = 0;
        rotate_button.clicked.connect(() => {
            rotate_label.angle += 45;
            rotate_label.label = (_("Vertical"));
            rotate_button.sensitive = true;
        });*/
    }

    /*private void on_selection (Gtk.TreeSelection selection) {
        Gtk.TreeModel model;
        Gtk.TreeIter iter;
        if(selection.get_selected (out model, out iter)
    }*/

    public static int main (string[] args) {
        var app = new MyApp ();
        return app.run (args);
    }
}
