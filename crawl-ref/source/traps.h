/*
 *  File:       traps.h
 *  Summary:    Traps related functions.
 *  Written by: Linley Henzell
 *
 *  Modified for Crawl Reference by $Author$ on $Date$
 *
 *  Change History (most recent first):
 *
 *               <1>     9/11/07        MPC             Split from misc.h
 */

#ifndef TRAPS_H
#define TRAPS_H

#include "enum.h"
#include "travel.h"

struct dist;
struct bolt;
class  monsters;

bool trap_item(object_class_type base_type, char sub_type,
               char beam_x, char beam_y);

// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr
 * *********************************************************************** */
void disarm_trap(struct dist &disa);
void remove_net_from( monsters *mon );
void free_self_from_net(void);

// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: acr - misc
 * *********************************************************************** */
void handle_traps(trap_type trt, int i, bool trap_known);
int get_trapping_net(int x, int y, bool trapped = true);
void mark_net_trapping(int x, int y);
void monster_caught_in_net(monsters *mon, bolt &pbolt);
void player_caught_in_net(void);
void clear_trapping_net(void);

// last updated 12may2000 {dlb}
/* ***********************************************************************
 * called from: misc - mstuff2
 * *********************************************************************** */
void itrap(struct bolt &pbolt, int trapped);

// last updated 3jun2000 {dlb}
/* ***********************************************************************
 * called from: acr - misc - mstuff2 - spells3
 * *********************************************************************** */
int trap_at_xy(int which_x, int which_y);


// last updated 3jun2000 {dlb}
/* ***********************************************************************
 * called from: acr - misc - mstuff2 - spells2 - spells3
 * *********************************************************************** */
dungeon_feature_type trap_category(trap_type type);

int trap_at_xy(int x, int y);
trap_type trap_type_at_xy(int x, int y);

bool is_valid_shaft_level(const level_id &place = level_id::current());

int       num_traps_for_place(int level_number = -1,
                              const level_id &place = level_id::current());
trap_type random_trap_for_place(int level_number = -1,
                                const level_id &place = level_id::current());

int traps_zero_number(int level_number = -1);

int       traps_pan_number(int level_number = -1);
trap_type traps_pan_type(int level_number = -1);

int       traps_abyss_number(int level_number = -1);
trap_type traps_abyss_type(int level_number = -1);

int       traps_lab_number(int level_number = -1);
trap_type traps_lab_type(int level_number = -1);

#endif
