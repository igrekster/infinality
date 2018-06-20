#ifndef _FTINF_H_
#define _FTINF_H_
/*
    Stem snapping rules
    (base freetype typedefs assumed already included)
 */
typedef struct
{
    FT_Int       stem_width;
    FT_Int       stem_spacing;
    FT_Int       stem_start;
    FT_Int       stem_scaling;
    FT_Int       stem_translating_only;
    FT_Int       stem_translating;
    float        brightness;
    float        contrast;
    FT_Bool      use_100;
    FT_Bool      synth_stems;
    FT_Bool      edge_detection;
    FT_Bool      bearing_correction;
    FT_Int       m;
} Stem_Data;

/*
  Infinality settings
 */
typedef struct ftinf_s {
    const char *name;
    int autohint_horizontal_stem_darken_strength;
    int autohint_snap_stem_height;
    int autohint_increase_glyph_heights;
    int autohint_vertical_stem_darken_strength;
    int bold_embolden_x_value;
    int bold_embolden_y_value;
    int brightness;
    int chromeos_style_sharpening_strength;
    int contrast;
    int filter_params[6];       /* 1st one used as existence flag */
    int fringe_filter_strength;
    float gamma_correction[2];
    int global_embolden_x_value;
    int global_embolden_y_value;
    int grayscale_filter_strength;
    int stem_alignment_strength;
    int stem_darkening_autofit;
    int stem_darkening_cff;
    int stem_fitting_strength;
    int stem_snapping_sliding_scale;
    int use_known_settings_on_selected_fonts;
    int use_various_tweaks;
    int windows_style_sharpening_strength;
} ftinf_t;

extern FT_Pos infinality_cur_width; /* defined in aflatin.c */

extern const ftinf_t *ftinf;    /* active settings */

extern void ftinf_fill_stem_values( Stem_Data *stem_values,
                                    const char *family, int ppem, int use_known );
extern void ftinf_get_bc( const char *family, int ppem,
                          float *brightness, float *contrast );

/* get values from environment (FIXME: maybe update with using user files) */
extern void ftinf_env();

#endif
