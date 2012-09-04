
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_CHANNEL_H_INCLUDED_
#define _NGX_CHANNEL_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_event.h>


typedef struct {
     ngx_uint_t  command;
     ngx_pid_t   pid;
     ngx_int_t   slot;
     ngx_fd_t    fd;
     size_t      len;
} ngx_channel_t;


#define NGX_CMD_CORE_MODULE           1000
#define NGX_CMD_HTTP_MODULE           4000
#define NGX_CMD_USER_DEFINED          40000


ngx_int_t ngx_write_channel(ngx_socket_t s, ngx_channel_t *ch, size_t size,
    ngx_log_t *log);
ngx_int_t ngx_read_channel(ngx_socket_t s, ngx_channel_t *ch, size_t size,
    ngx_log_t *log);
ngx_int_t ngx_read_channel_ex(ngx_socket_t s, u_char *buf, size_t size,
    ngx_log_t *log);
ngx_int_t ngx_add_channel_event(ngx_cycle_t *cycle, ngx_fd_t fd,
    ngx_int_t event, ngx_event_handler_pt handler);
void ngx_close_channel(ngx_fd_t *fd, ngx_log_t *log);


typedef void (*ngx_channel_handler_pt)(ngx_channel_t *ch, u_char *buf,
    ngx_log_t *log);


extern ngx_channel_handler_pt ngx_channel_top_handler;


#endif /* _NGX_CHANNEL_H_INCLUDED_ */
