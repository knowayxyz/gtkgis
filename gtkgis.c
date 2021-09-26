#include <gtk/gtk.h>

typedef struct _geometry
{
    int geom_type;
    int nparts;
    int npoints;
    double *xcoords;
    double *ycoords;
    double *zcoords;
    double *mcoords;
    double minx;
    double miny;
    double minz;
    double minm;
    double maxx;
    double maxy;
    double maxz;
    double maxm;
} geometry;

typedef struct _feature
{
    geometry *geom;
} feature;

typedef struct _layer 
{
    char *layer_name;
    
} layer;

void 
map_renderer ()
{

}

static void
canvas_drawing( GtkDrawingArea *canvas,
                cairo_t *cr,
                int width,
                int height,
                gpointer data)
{
    int square_size = 40.0;
    cairo_set_source_rgb (cr, 1.0, 1.0, 1.0); /* whilte */
    cairo_paint (cr);
    cairo_set_line_width (cr, 2.0);
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0); /* black */
    cairo_rectangle (cr, width/2.0 - square_size/2, height/2.0 - square_size/2, square_size, square_size);
    cairo_stroke (cr);


}

static void 
app_activate( GtkApplication *app, 
              gpointer data)
{
    GtkWidget *mainwin;
    GtkWidget *canvas;

    mainwin = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainwin), "GTK GIS 0.9");
    
    canvas = gtk_drawing_area_new();
    gtk_widget_set_size_request(canvas, 800, 600);
    gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(canvas), canvas_drawing, NULL, NULL);
    gtk_window_set_child(GTK_WINDOW(mainwin), canvas);
    
    gtk_window_maximize(GTK_WINDOW(mainwin));
    gtk_widget_show(mainwin);
    
}

int main( int argc, 
          char **argv)
{
    int status = 0;
    GtkApplication *app;

    app = gtk_application_new("gtk.gis", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(app_activate), NULL);

    g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}