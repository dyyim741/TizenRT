/****************************************************************************
 *
 * Copyright 2019 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

#ifndef _LWNL_EVT_QUEUE_H__
#define _LWNL_EVT_QUEUE_H__

#include <tinyara/lwnl/lwnl80211.h>
#include <tinyara/fs/fs.h>

#define LWNL_NPOLLWAITERS 5

struct lwnl_event;
struct lwnl_queue;

int lwnl_add_event(lwnl80211_cb_status type, void *buffer);

void lwnl_queue_initialize(void);
int lwnl_add_listener(struct file *filep);
int lwnl_remove_listener(struct file *filep);

#endif // _LWNL_EVT_QUEUE_H__
