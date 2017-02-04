/*
 * SurgeScript
 * A lightweight programming language for computer games and interactive apps
 * Copyright (C) 2017  Alexandre Martins <alemartf(at)gmail(dot)com>
 *
 * runtime/stdlib/stdlib.h
 * SurgeScript Standard Library
 */

#ifndef _SURGESCRIPT_RUNTIME_STDLIB_STDLIB_H
#define _SURGESCRIPT_RUNTIME_STDLIB_STDLIB_H

/* forward declarations */
struct surgescript_vm_t;

/* Register common methods to all objects */
void surgescript_stdlib_register_object(struct surgescript_vm_t* vm);

#endif