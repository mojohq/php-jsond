/* Generated by re2c 0.14.3 */
/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Jakub Zelenka <bukka@php.net>                                |
  +----------------------------------------------------------------------+
*/

#include "php.h"
#include "php_jsond_scanner.h"
#include "php_jsond_scanner_defs.h"
#include "php_jsond_parser.h"
#include "jsond_parser.tab.h"

#define	YYCTYPE     php_json_ctype
#define	YYCURSOR    s->cursor
#define	YYLIMIT     s->limit
#define	YYMARKER    s->marker
#define	YYCTXMARKER s->ctxmarker

#define YYGETCONDITION()        s->state
#define YYSETCONDITION(yystate) s->state = yystate

#define	YYFILL(n)

#define PHP_JSON_CONDITION_SET(condition) YYSETCONDITION(yyc##condition)
#define PHP_JSON_CONDITION_GOTO(condition) goto yyc_##condition

#define PHP_JSON_SCANNER_COPY_ESC() php_json_scanner_copy_string(s, 0)
#define PHP_JSON_SCANNER_COPY_UTF() php_json_scanner_copy_string(s, 5)
#define PHP_JSON_SCANNER_COPY_UTF_SP() php_json_scanner_copy_string(s, 11)


static void php_json_scanner_copy_string(php_json_scanner *s, int esc_size)
{
	size_t len = s->cursor - s->str_start - esc_size - 1;
	if (len) {
		memcpy(s->pstr, s->str_start, len);
		s->pstr += len;
	}
}

static int php_json_hex_to_int(char code)
{
	if (code >= '0' && code <= '9') {
		return code - '0';
	} else if (code >= 'A' && code <= 'F') {
		return code - ('A' - 10);
	} else if (code >= 'a' && code <= 'f') {
		return code - ('a' - 10);
	} else {
		/* this should never happened (just to suppress compiler warning) */
		return -1;
	}
}

static int php_json_ucs2_to_int_ex(php_json_scanner *s, int size, int start)
{
	int i, code = 0;
	php_json_ctype *pc = s->cursor - start;
	for (i = 0; i < size; i++) {
		code |= php_json_hex_to_int(*(pc--)) << (i * 4);
	}
	return code;
}

static int php_json_ucs2_to_int(php_json_scanner *s, int size)
{
	return php_json_ucs2_to_int_ex(s, size, 1);
}

void php_json_scanner_init(php_json_scanner *s, char *str, phpc_str_size_t str_len, int options)
{
	s->cursor = (php_json_ctype *) str;
	s->limit = (php_json_ctype *) str + str_len;
	s->options = options;
	PHP_JSON_CONDITION_SET(JS);
}

int php_json_scan(php_json_scanner *s)
{
	ZVAL_NULL(&s->value);
	
std:
	s->token = s->cursor;


	{
		YYCTYPE yych;
		unsigned int yyaccept = 0;
		if (YYGETCONDITION() < 1) {
			goto yyc_JS;
		} else {
			if (YYGETCONDITION() < 2) {
				goto yyc_STR_P1;
			} else {
				goto yyc_STR_P2;
			}
		}
/* *********************************** */
yyc_JS:
		{
			static const unsigned char yybm[] = {
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0, 128,   0,   0,   0, 128,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				128,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				 64,  64,  64,  64,  64,  64,  64,  64, 
				 64,  64,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
				  0,   0,   0,   0,   0,   0,   0,   0, 
			};
			yych = *YYCURSOR;
			if (yych <= ']') {
				if (yych <= '"') {
					if (yych <= '\f') {
						if (yych <= 0x08) {
							if (yych >= 0x01) goto yy5;
						} else {
							if (yych <= '\t') goto yy7;
							if (yych <= '\n') goto yy9;
							goto yy5;
						}
					} else {
						if (yych <= 0x1F) {
							if (yych <= '\r') goto yy10;
							goto yy5;
						} else {
							if (yych <= ' ') goto yy11;
							if (yych <= '!') goto yy12;
							goto yy14;
						}
					}
				} else {
					if (yych <= '0') {
						if (yych <= ',') {
							if (yych <= '+') goto yy12;
							goto yy16;
						} else {
							if (yych <= '-') goto yy18;
							if (yych <= '/') goto yy12;
							goto yy19;
						}
					} else {
						if (yych <= 'Z') {
							if (yych <= '9') goto yy21;
							if (yych <= ':') goto yy22;
							goto yy12;
						} else {
							if (yych <= '[') goto yy24;
							if (yych <= '\\') goto yy12;
							goto yy26;
						}
					}
				}
			} else {
				if (yych <= '}') {
					if (yych <= 's') {
						if (yych <= 'f') {
							if (yych <= 'e') goto yy12;
							goto yy28;
						} else {
							if (yych == 'n') goto yy29;
							goto yy12;
						}
					} else {
						if (yych <= 'z') {
							if (yych <= 't') goto yy30;
							goto yy12;
						} else {
							if (yych <= '{') goto yy31;
							if (yych <= '|') goto yy12;
							goto yy33;
						}
					}
				} else {
					if (yych <= 0xEC) {
						if (yych <= 0xC1) {
							if (yych <= 0x7F) goto yy12;
							goto yy35;
						} else {
							if (yych <= 0xDF) goto yy37;
							if (yych <= 0xE0) goto yy38;
							goto yy39;
						}
					} else {
						if (yych <= 0xF0) {
							if (yych <= 0xED) goto yy40;
							if (yych <= 0xEF) goto yy41;
							goto yy42;
						} else {
							if (yych <= 0xF3) goto yy43;
							if (yych <= 0xF4) goto yy44;
							goto yy35;
						}
					}
				}
			}
			++YYCURSOR;
			{
		if (s->limit < s->cursor) {
			return PHP_JSON_T_EOI;
		} else {
			s->errcode = PHP_JSON_ERROR_CTRL_CHAR;
			return PHP_JSON_T_ERROR;
		}
	}
yy5:
			++YYCURSOR;
			{
		s->errcode = PHP_JSON_ERROR_CTRL_CHAR;
		return PHP_JSON_T_ERROR;
	}
yy7:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy82;
yy8:
			{ goto std; }
yy9:
			yych = *++YYCURSOR;
			goto yy8;
yy10:
			yych = *++YYCURSOR;
			if (yych == '\n') goto yy83;
			goto yy82;
yy11:
			yych = *++YYCURSOR;
			goto yy82;
yy12:
			++YYCURSOR;
yy13:
			{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		return PHP_JSON_T_ERROR;
	}
yy14:
			++YYCURSOR;
			{
		s->str_start = s->cursor;
		s->str_esc = 0;
		PHP_JSON_CONDITION_SET(STR_P1);
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy16:
			++YYCURSOR;
			{ return ','; }
yy18:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy13;
			if (yych <= '0') goto yy80;
			if (yych <= '9') goto yy70;
			goto yy13;
yy19:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy72;
			} else {
				if (yych <= 'E') goto yy73;
				if (yych == 'e') goto yy73;
			}
yy20:
			{
		zend_bool bigint = 0, negative = s->token[0] == '-';
		size_t digits = (size_t) (s->cursor - s->token - negative);
		if (digits >= PHP_JSON_INT_MAX_LENGTH) {
			if (digits == PHP_JSON_INT_MAX_LENGTH) {
				int cmp = strncmp((char *) (s->token + negative), PHP_JSON_INT_MAX_DIGITS, PHP_JSON_INT_MAX_LENGTH);
				if (!(cmp < 0 || (cmp == 0 && negative))) {
					bigint = 1;
				}
			} else {
				bigint = 1;
			}
		}
		if (!bigint) {
			ZVAL_LONG(&s->value, strtol((char *) s->token, NULL, 10));
			return PHP_JSON_T_INT;
		} else if (s->options & PHP_JSON_BIGINT_AS_STRING) {
			ZVAL_STRINGL(&s->value, (char *) s->token, s->cursor - s->token, 1);
			return PHP_JSON_T_STRING;
		} else {
			ZVAL_DOUBLE(&s->value, zend_strtod((char *) s->token, NULL));
			return PHP_JSON_T_DOUBLE;
		}
	}
yy21:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			goto yy71;
yy22:
			++YYCURSOR;
			{ return ':'; }
yy24:
			++YYCURSOR;
			{ return '['; }
yy26:
			++YYCURSOR;
			{ return ']'; }
yy28:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'a') goto yy65;
			goto yy13;
yy29:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'u') goto yy61;
			goto yy13;
yy30:
			yyaccept = 1;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych == 'r') goto yy57;
			goto yy13;
yy31:
			++YYCURSOR;
			{ return '{'; }
yy33:
			++YYCURSOR;
			{ return '}'; }
yy35:
			++YYCURSOR;
yy36:
			{
		s->errcode = PHP_JSON_ERROR_UTF8;
		return PHP_JSON_T_ERROR;
	}
yy37:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy36;
			if (yych <= 0xBF) goto yy48;
			goto yy36;
yy38:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x9F) goto yy36;
			if (yych <= 0xBF) goto yy56;
			goto yy36;
yy39:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy36;
			if (yych <= 0xBF) goto yy55;
			goto yy36;
yy40:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy36;
			if (yych <= 0x9F) goto yy54;
			goto yy36;
yy41:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy36;
			if (yych <= 0xBF) goto yy53;
			goto yy36;
yy42:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x8F) goto yy36;
			if (yych <= 0xBF) goto yy51;
			goto yy36;
yy43:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy36;
			if (yych <= 0xBF) goto yy49;
			goto yy36;
yy44:
			yyaccept = 2;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 0x7F) goto yy36;
			if (yych >= 0x90) goto yy36;
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy47;
yy46:
			YYCURSOR = YYMARKER;
			if (yyaccept <= 1) {
				if (yyaccept == 0) {
					goto yy20;
				} else {
					goto yy13;
				}
			} else {
				if (yyaccept == 2) {
					goto yy36;
				} else {
					goto yy77;
				}
			}
yy47:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych >= 0xC0) goto yy46;
yy48:
			yych = *++YYCURSOR;
			goto yy13;
yy49:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych >= 0xC0) goto yy46;
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy51:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych >= 0xC0) goto yy46;
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy53:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy54:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy55:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy56:
			yych = *++YYCURSOR;
			if (yych <= 0x7F) goto yy46;
			if (yych <= 0xBF) goto yy48;
			goto yy46;
yy57:
			yych = *++YYCURSOR;
			if (yych != 'u') goto yy46;
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy46;
			++YYCURSOR;
			{
		ZVAL_TRUE(&s->value);
		return PHP_JSON_T_TRUE;
	}
yy61:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy46;
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy46;
			++YYCURSOR;
			{
		ZVAL_NULL(&s->value);
		return PHP_JSON_T_NUL;
	}
yy65:
			yych = *++YYCURSOR;
			if (yych != 'l') goto yy46;
			yych = *++YYCURSOR;
			if (yych != 's') goto yy46;
			yych = *++YYCURSOR;
			if (yych != 'e') goto yy46;
			++YYCURSOR;
			{
		ZVAL_FALSE(&s->value);
		return PHP_JSON_T_FALSE;
	}
yy70:
			yyaccept = 0;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
yy71:
			if (yybm[0+yych] & 64) {
				goto yy70;
			}
			if (yych <= 'D') {
				if (yych != '.') goto yy20;
			} else {
				if (yych <= 'E') goto yy73;
				if (yych == 'e') goto yy73;
				goto yy20;
			}
yy72:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy46;
			if (yych <= '9') goto yy78;
			goto yy46;
yy73:
			yych = *++YYCURSOR;
			if (yych <= ',') {
				if (yych != '+') goto yy46;
			} else {
				if (yych <= '-') goto yy74;
				if (yych <= '/') goto yy46;
				if (yych <= '9') goto yy75;
				goto yy46;
			}
yy74:
			yych = *++YYCURSOR;
			if (yych <= '/') goto yy46;
			if (yych >= ':') goto yy46;
yy75:
			++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= '/') goto yy77;
			if (yych <= '9') goto yy75;
yy77:
			{
		ZVAL_DOUBLE(&s->value, zend_strtod((char *) s->token, NULL));
		return PHP_JSON_T_DOUBLE;
	}
yy78:
			yyaccept = 3;
			YYMARKER = ++YYCURSOR;
			yych = *YYCURSOR;
			if (yych <= 'D') {
				if (yych <= '/') goto yy77;
				if (yych <= '9') goto yy78;
				goto yy77;
			} else {
				if (yych <= 'E') goto yy73;
				if (yych == 'e') goto yy73;
				goto yy77;
			}
yy80:
			yyaccept = 0;
			yych = *(YYMARKER = ++YYCURSOR);
			if (yych <= 'D') {
				if (yych == '.') goto yy72;
				goto yy20;
			} else {
				if (yych <= 'E') goto yy73;
				if (yych == 'e') goto yy73;
				goto yy20;
			}
yy81:
			++YYCURSOR;
			yych = *YYCURSOR;
yy82:
			if (yybm[0+yych] & 128) {
				goto yy81;
			}
			goto yy8;
yy83:
			++YYCURSOR;
			yych = *YYCURSOR;
			goto yy8;
		}
/* *********************************** */
yyc_STR_P1:
		yych = *YYCURSOR;
		if (yych <= 0xDF) {
			if (yych <= '[') {
				if (yych <= 0x1F) goto yy86;
				if (yych == '"') goto yy90;
				goto yy88;
			} else {
				if (yych <= '\\') goto yy92;
				if (yych <= 0x7F) goto yy88;
				if (yych <= 0xC1) goto yy94;
				goto yy96;
			}
		} else {
			if (yych <= 0xEF) {
				if (yych <= 0xE0) goto yy97;
				if (yych <= 0xEC) goto yy98;
				if (yych <= 0xED) goto yy99;
				goto yy100;
			} else {
				if (yych <= 0xF0) goto yy101;
				if (yych <= 0xF3) goto yy102;
				if (yych <= 0xF4) goto yy103;
				goto yy94;
			}
		}
yy86:
		++YYCURSOR;
		{
		s->errcode = PHP_JSON_ERROR_CTRL_CHAR;
		return PHP_JSON_T_ERROR;
	}
yy88:
		++YYCURSOR;
yy89:
		{ PHP_JSON_CONDITION_GOTO(STR_P1); }
yy90:
		++YYCURSOR;
		{
		char *str;
		size_t len = s->cursor - s->str_start - s->str_esc - 1;
		if (len == 0) {
			PHP_JSON_CONDITION_SET(JS);
			ZVAL_EMPTY_STRING(&s->value);
			return PHP_JSON_T_ESTRING;
		}
		str = emalloc(len + 1);
		str[len] = 0;
		ZVAL_STRINGL(&s->value, str, len, 0);
		if (s->str_esc) {
			s->pstr = (php_json_ctype *) Z_STRVAL(s->value);
			s->cursor = s->str_start;
			PHP_JSON_CONDITION_SET(STR_P2);
			PHP_JSON_CONDITION_GOTO(STR_P2);
		} else {
			memcpy(Z_STRVAL(s->value), s->str_start, len);
			PHP_JSON_CONDITION_SET(JS);
			return PHP_JSON_T_STRING;
		}
	}
yy92:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 'e') {
			if (yych <= '/') {
				if (yych == '"') goto yy116;
				if (yych >= '/') goto yy116;
			} else {
				if (yych <= '\\') {
					if (yych >= '\\') goto yy116;
				} else {
					if (yych == 'b') goto yy116;
				}
			}
		} else {
			if (yych <= 'q') {
				if (yych <= 'f') goto yy116;
				if (yych == 'n') goto yy116;
			} else {
				if (yych <= 's') {
					if (yych <= 'r') goto yy116;
				} else {
					if (yych <= 't') goto yy116;
					if (yych <= 'u') goto yy118;
				}
			}
		}
yy93:
		{
		s->errcode = PHP_JSON_ERROR_SYNTAX;
		return PHP_JSON_T_ERROR;
	}
yy94:
		++YYCURSOR;
yy95:
		{
		s->errcode = PHP_JSON_ERROR_UTF8;
		return PHP_JSON_T_ERROR;
	}
yy96:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy95;
		if (yych <= 0xBF) goto yy107;
		goto yy95;
yy97:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x9F) goto yy95;
		if (yych <= 0xBF) goto yy115;
		goto yy95;
yy98:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy95;
		if (yych <= 0xBF) goto yy114;
		goto yy95;
yy99:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy95;
		if (yych <= 0x9F) goto yy113;
		goto yy95;
yy100:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy95;
		if (yych <= 0xBF) goto yy112;
		goto yy95;
yy101:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x8F) goto yy95;
		if (yych <= 0xBF) goto yy110;
		goto yy95;
yy102:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy95;
		if (yych <= 0xBF) goto yy108;
		goto yy95;
yy103:
		yyaccept = 1;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych <= 0x7F) goto yy95;
		if (yych >= 0x90) goto yy95;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy106;
yy105:
		YYCURSOR = YYMARKER;
		if (yyaccept <= 1) {
			if (yyaccept == 0) {
				goto yy93;
			} else {
				goto yy95;
			}
		} else {
			goto yy127;
		}
yy106:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych >= 0xC0) goto yy105;
yy107:
		yych = *++YYCURSOR;
		goto yy89;
yy108:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych >= 0xC0) goto yy105;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy110:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych >= 0xC0) goto yy105;
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy112:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy113:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy114:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy115:
		yych = *++YYCURSOR;
		if (yych <= 0x7F) goto yy105;
		if (yych <= 0xBF) goto yy107;
		goto yy105;
yy116:
		++YYCURSOR;
		{
		s->str_esc++;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy118:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy105;
				if (yych >= '1') goto yy120;
			} else {
				if (yych <= '@') goto yy105;
				if (yych <= 'C') goto yy120;
				goto yy121;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy120;
				if (yych <= '`') goto yy105;
				goto yy120;
			} else {
				if (yych <= 'd') goto yy121;
				if (yych <= 'f') goto yy120;
				goto yy105;
			}
		}
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy105;
			if (yych <= '0') goto yy140;
			if (yych <= '7') goto yy141;
			goto yy122;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy105;
				goto yy122;
			} else {
				if (yych <= '`') goto yy105;
				if (yych <= 'f') goto yy122;
				goto yy105;
			}
		}
yy120:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych <= '9') goto yy122;
			goto yy105;
		} else {
			if (yych <= 'F') goto yy122;
			if (yych <= '`') goto yy105;
			if (yych <= 'f') goto yy122;
			goto yy105;
		}
yy121:
		yych = *++YYCURSOR;
		if (yych <= 'B') {
			if (yych <= '7') {
				if (yych <= '/') goto yy105;
			} else {
				if (yych <= '9') goto yy123;
				if (yych <= '@') goto yy105;
				goto yy123;
			}
		} else {
			if (yych <= '`') {
				if (yych <= 'F') goto yy124;
				goto yy105;
			} else {
				if (yych <= 'b') goto yy123;
				if (yych <= 'f') goto yy124;
				goto yy105;
			}
		}
yy122:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych <= '9') goto yy137;
			goto yy105;
		} else {
			if (yych <= 'F') goto yy137;
			if (yych <= '`') goto yy105;
			if (yych <= 'f') goto yy137;
			goto yy105;
		}
yy123:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych <= '9') goto yy128;
			goto yy105;
		} else {
			if (yych <= 'F') goto yy128;
			if (yych <= '`') goto yy105;
			if (yych <= 'f') goto yy128;
			goto yy105;
		}
yy124:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy125;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy125:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy126;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy126:
		++YYCURSOR;
yy127:
		{
		s->errcode = PHP_JSON_ERROR_UTF16;
		return PHP_JSON_T_ERROR;
	}
yy128:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy129;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy129:
		yyaccept = 2;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych != '\\') goto yy127;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy105;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy132;
		if (yych != 'd') goto yy105;
yy132:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy105;
		if (yych <= 'F') goto yy133;
		if (yych <= 'b') goto yy105;
		if (yych >= 'g') goto yy105;
yy133:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy134;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy134:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy135;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy135:
		++YYCURSOR;
		{
		s->str_esc += 8;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy137:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy138;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy138:
		++YYCURSOR;
		{
		s->str_esc += 3;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy140:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych <= '7') goto yy145;
			if (yych <= '9') goto yy142;
			goto yy105;
		} else {
			if (yych <= 'F') goto yy142;
			if (yych <= '`') goto yy105;
			if (yych <= 'f') goto yy142;
			goto yy105;
		}
yy141:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy142;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy142:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy143;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy143:
		++YYCURSOR;
		{
		s->str_esc += 4;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
yy145:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy105;
			if (yych >= ':') goto yy105;
		} else {
			if (yych <= 'F') goto yy146;
			if (yych <= '`') goto yy105;
			if (yych >= 'g') goto yy105;
		}
yy146:
		++YYCURSOR;
		{
		s->str_esc += 5;
		PHP_JSON_CONDITION_GOTO(STR_P1);
	}
/* *********************************** */
yyc_STR_P2:
		yych = *YYCURSOR;
		if (yych == '"') goto yy152;
		if (yych == '\\') goto yy154;
		++YYCURSOR;
		{ PHP_JSON_CONDITION_GOTO(STR_P2); }
yy152:
		++YYCURSOR;
		YYSETCONDITION(yycJS);
		{
		PHP_JSON_SCANNER_COPY_ESC();
		return PHP_JSON_T_STRING;
	}
yy154:
		yyaccept = 0;
		yych = *(YYMARKER = ++YYCURSOR);
		if (yych == 'u') goto yy156;
yy155:
		{
		char esc;
		PHP_JSON_SCANNER_COPY_ESC();
		switch (*s->cursor) {
			case 'b':
				esc = '\b';
				break;
			case 'f':
				esc = '\f';
				break;
			case 'n':
				esc = '\n';
				break;
			case 'r':
				esc = '\r';
				break;
			case 't':
				esc = '\t';
				break;
			case '\\':
			case '/':
			case '"':
				esc = *s->cursor;
				break;
			default:
				s->errcode = PHP_JSON_ERROR_SYNTAX;
				return PHP_JSON_T_ERROR;
		}
		*(s->pstr++) = esc;
		++YYCURSOR;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy156:
		yych = *++YYCURSOR;
		if (yych <= 'D') {
			if (yych <= '9') {
				if (yych <= '/') goto yy157;
				if (yych <= '0') goto yy158;
				goto yy159;
			} else {
				if (yych <= '@') goto yy157;
				if (yych <= 'C') goto yy159;
				goto yy160;
			}
		} else {
			if (yych <= 'c') {
				if (yych <= 'F') goto yy159;
				if (yych >= 'a') goto yy159;
			} else {
				if (yych <= 'd') goto yy160;
				if (yych <= 'f') goto yy159;
			}
		}
yy157:
		YYCURSOR = YYMARKER;
		goto yy155;
yy158:
		yych = *++YYCURSOR;
		if (yych <= '9') {
			if (yych <= '/') goto yy157;
			if (yych <= '0') goto yy175;
			if (yych <= '7') goto yy176;
			goto yy162;
		} else {
			if (yych <= 'F') {
				if (yych <= '@') goto yy157;
				goto yy162;
			} else {
				if (yych <= '`') goto yy157;
				if (yych <= 'f') goto yy162;
				goto yy157;
			}
		}
yy159:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych <= '9') goto yy162;
			goto yy157;
		} else {
			if (yych <= 'F') goto yy162;
			if (yych <= '`') goto yy157;
			if (yych <= 'f') goto yy162;
			goto yy157;
		}
yy160:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych <= '7') goto yy162;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'B') goto yy161;
			if (yych <= '`') goto yy157;
			if (yych >= 'c') goto yy157;
		}
yy161:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych <= '9') goto yy166;
			goto yy157;
		} else {
			if (yych <= 'F') goto yy166;
			if (yych <= '`') goto yy157;
			if (yych <= 'f') goto yy166;
			goto yy157;
		}
yy162:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy163;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy163:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy164;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy164:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 4);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xe0 | (utf16 >> 12));
		*(s->pstr++) = (char) (0x80 | ((utf16 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy166:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy167;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy167:
		yych = *++YYCURSOR;
		if (yych != '\\') goto yy157;
		yych = *++YYCURSOR;
		if (yych != 'u') goto yy157;
		yych = *++YYCURSOR;
		if (yych == 'D') goto yy170;
		if (yych != 'd') goto yy157;
yy170:
		yych = *++YYCURSOR;
		if (yych <= 'B') goto yy157;
		if (yych <= 'F') goto yy171;
		if (yych <= 'b') goto yy157;
		if (yych >= 'g') goto yy157;
yy171:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy172;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy172:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy173;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy173:
		++YYCURSOR;
		{
		int utf32, utf16_hi, utf16_lo;
		utf16_hi = php_json_ucs2_to_int(s, 4);
		utf16_lo = php_json_ucs2_to_int_ex(s, 4, 7);
		utf32 = ((utf16_lo & 0x3FF) << 10) + (utf16_hi & 0x3FF) + 0x10000;
		PHP_JSON_SCANNER_COPY_UTF_SP();
		*(s->pstr++) = (char) (0xf0 | (utf32 >> 18));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 12) & 0x3f));
		*(s->pstr++) = (char) (0x80 | ((utf32 >> 6) & 0x3f));
		*(s->pstr++) = (char) (0x80 | (utf32 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy175:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych <= '7') goto yy180;
			if (yych <= '9') goto yy177;
			goto yy157;
		} else {
			if (yych <= 'F') goto yy177;
			if (yych <= '`') goto yy157;
			if (yych <= 'f') goto yy177;
			goto yy157;
		}
yy176:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy177;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy177:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy178;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy178:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 3);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) (0xc0 | (utf16 >> 6));
		*(s->pstr++) = (char) (0x80 | (utf16 & 0x3f));
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
yy180:
		yych = *++YYCURSOR;
		if (yych <= '@') {
			if (yych <= '/') goto yy157;
			if (yych >= ':') goto yy157;
		} else {
			if (yych <= 'F') goto yy181;
			if (yych <= '`') goto yy157;
			if (yych >= 'g') goto yy157;
		}
yy181:
		++YYCURSOR;
		{
		int utf16 = php_json_ucs2_to_int(s, 2);
		PHP_JSON_SCANNER_COPY_UTF();
		*(s->pstr++) = (char) utf16;
		s->str_start = s->cursor;
		PHP_JSON_CONDITION_GOTO(STR_P2);
	}
	}


}

