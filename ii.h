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
   |                mailto://idev@eclips-software.com                     |
   |                Computer Associates, http://ingres.ca.com             |
   | Authors: David H�not <henot@php.net>                                 |
   |          Grant Croker <grantc@php.net>                               |
   +----------------------------------------------------------------------+
 */

/* $Id$ */

#ifndef II_H
#define II_H

#if HAVE_II
#include "php_ii.h"
#include "iiapi.h"

typedef struct _II_LINK {
	int autocommit;
	II_PTR connHandle;
	II_PTR tranHandle;
	II_PTR stmtHandle;
	II_LONG fieldCount;
	IIAPI_DESCRIPTOR *descriptor;
	II_CHAR *errorText;
	II_CHAR sqlstate[6];
	II_LONG errorCode;
	int paramCount;
	char *cursor_id;
	short int cursor_mode;
	char *procname;
} II_LINK;

typedef struct _II_RESULT {
	II_PTR 			stmtHandle;
	II_PTR 			connHandle;
	II_PTR 			tranHandle;
	II_LONG 		fieldCount;
	IIAPI_DESCRIPTOR 	*descriptor;
	int 			paramCount;
	char			*cursor_id;
} II_RESULT;

#define II_FAIL 0
#define II_OK 1
#define II_NO_DATA 2

#define II_FIELD_INFO_NAME 1
#define II_FIELD_INFO_TYPE 2
#define II_FIELD_INFO_NULLABLE 3
#define II_FIELD_INFO_LENGTH 4
#define II_FIELD_INFO_PRECISION 5
#define II_FIELD_INFO_SCALE 6

static int ii_sync(IIAPI_GENPARM *genParm);
static int ii_success(IIAPI_GENPARM *genParm, II_LINK *ii_link TSRMLS_DC);

static int _close_statement(II_LINK *ii_link TSRMLS_DC);
static int _rollback_transaction(II_LINK *ii_link TSRMLS_DC);
static void _close_ii_link(II_LINK *link TSRMLS_DC);
static void _close_ii_plink(zend_rsrc_list_entry *link TSRMLS_DC);
static int php_ii_get_default_link(INTERNAL_FUNCTION_PARAMETERS);
static void php_ii_set_default_link(int id TSRMLS_DC);
static void php_ii_do_connect(INTERNAL_FUNCTION_PARAMETERS, int persistent);
static char *php_ii_field_name(II_LINK *ii_link, int index TSRMLS_DC);
static void php_ii_field_info(INTERNAL_FUNCTION_PARAMETERS, int info_type);
static void php_ii_fetch(INTERNAL_FUNCTION_PARAMETERS, II_LINK *ii_link, int result_type);
static void php_ii_error(INTERNAL_FUNCTION_PARAMETERS, int mode);
static long php_ii_queryparse(char *statement TSRMLS_DC);
static void php_ii_gen_cursor_id(II_LINK *ii_link TSRMLS_DC);
static void php_ii_check_procedure(char *statement, II_LINK *ii_link TSRMLS_DC);

#endif  /* HAVE_II */
#endif	/* II_H */


/*
 * Local variables:
 * tab-width: 4
 * shift-width: 4
 * c-basic-offset: 4
 * End:
 */
