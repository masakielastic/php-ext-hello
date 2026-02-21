#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"

/* ★ 追加：hello_world() の arginfo */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_hello_world, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hello_world)
{
    RETURN_STRING("Hello World");
}

static const zend_function_entry hello_functions[] = {
    /* ★ 変更：NULL ではなく arginfo を渡す */
    PHP_FE(hello_world, arginfo_hello_world)
    PHP_FE_END
};

zend_module_entry hello_module_entry = {
    STANDARD_MODULE_HEADER,
    "hello",
    hello_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    "0.1.0",
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLO
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(hello)
#endif
