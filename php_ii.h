/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2004 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Contributed by ECL IP'S Software & Services                          |
   |                http://www.eclips-software.com                        |
   |                mailto:idev@eclips-software.com                       |
   |                Ingres Corporation, http://ingres.com                 |
   | Authors: David H�not <henot@php.net>                                 |
   |          Grant Croker <grantc@php.net>                               |
   +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef PHP_II_H
#define PHP_II_H

#if HAVE_II
#include<iiapi.h>
extern zend_module_entry ingres_module_entry;
#define phpext_ingres_ptr &ingres_module_entry

#ifdef PHP_WIN32
#define PHP_II_API __declspec(dllexport)
#else
#define PHP_II_API
#endif

PHP_MINIT_FUNCTION(ii);
PHP_MSHUTDOWN_FUNCTION(ii);
PHP_RINIT_FUNCTION(ii);
PHP_RSHUTDOWN_FUNCTION(ii);
PHP_MINFO_FUNCTION(ii);

PHP_FUNCTION(ingres_connect);
PHP_FUNCTION(ingres_pconnect);
PHP_FUNCTION(ingres_close);
PHP_FUNCTION(ingres_query);
PHP_FUNCTION(ingres_num_rows);
PHP_FUNCTION(ingres_num_fields);
PHP_FUNCTION(ingres_field_name);
PHP_FUNCTION(ingres_field_type);
PHP_FUNCTION(ingres_field_nullable);
PHP_FUNCTION(ingres_field_length);
PHP_FUNCTION(ingres_field_precision);
PHP_FUNCTION(ingres_field_scale);
PHP_FUNCTION(ingres_fetch_array);
PHP_FUNCTION(ingres_fetch_row);
PHP_FUNCTION(ingres_fetch_object);
PHP_FUNCTION(ingres_rollback);
PHP_FUNCTION(ingres_commit);
PHP_FUNCTION(ingres_autocommit);
PHP_FUNCTION(ingres_error);
PHP_FUNCTION(ingres_errno);
PHP_FUNCTION(ingres_errsqlstate);
PHP_FUNCTION(ingres_prepare);
PHP_FUNCTION(ingres_execute);
PHP_FUNCTION(ingres_cursor);
PHP_FUNCTION(ingres_set_environment);
PHP_FUNCTION(ingres_fetch_proc_return);

ZEND_BEGIN_MODULE_GLOBALS(ii)
	long allow_persistent;
	long max_persistent;
	long max_links;
	char *default_database;
	char *default_user;
	char *default_password;

	long num_persistent;
	long num_links;
	long default_link;

	char sqlstate[7];
	long errorCode;
	char *errorText;
	
	long report_db_warnings;  /* switch on/off the E_WARNINGS generated by
				     ii_success. Default is to have them on */

	long cursor_no;
	long cursor_mode;

	II_PTR *envHandle; /* environment handle */

	long blob_segment_length; /* size of memory to read when puting/fetching */
								/* a blob */
	long trace_connect; /* enable / disable tracing of php_ii_do_connect */
	long connect_timeout; /* in ms - default -1, no timeout,  if not set */
	long array_index_start; /* start value for x in  array[x], default 1*/

ZEND_END_MODULE_GLOBALS(ii)

#define II_ASSOC (1<<0)
#define II_NUM   (1<<1)
#define II_BOTH  (II_ASSOC|II_NUM)
#define II_VERSION "1.3.1-dev"

#define II_CURSOR_UPDATE 0    /* default */
#define II_CURSOR_READONLY 1

#ifdef ZTS
#define IIG(v) TSRMG(ii_globals_id, zend_ii_globals *, v)
#define II_THREAD_ID (unsigned long)tsrm_thread_id()
#else
#define IIG(v) (ii_globals.v)
#define II_THREAD_ID 0
#endif

#else

#define phpext_ingres_ptr NULL

#endif

#endif	/* PHP_II_H */

/*
 * Local variables:
 * tab-width: 4
 * shift-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: sw=4 ts=4 fdm=marker ff=unix
 * vim<600: sw=4 ts=4
 */
