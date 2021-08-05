AC_INIT()



AC_CANONICAL_HOST

AC_PROG_INSTALL

case $host in
    w65-* )
    ;;
    *)
    AC_MSG_ERROR([Cannot configure qc for $host])
    ;;
esac

AC_ARG_VAR([AR])
AC_ARG_VAR([AS])

AC_PATH_TOOL([AR],[ar])

AC_PATH_TOOL([AS],[as])

AC_ARG_ENABLE([float],[
    Enables floating point support
],[
    case x$enableval in
        xyes | xno | xcop )
                float_support=$enableval
            ;;
        * )
            AC_MSG_ERROR([Invalid value])
            ;;
    esac

],[
    float_support=yes
])

AC_ARG_ENABLE([int128],[Enable support for 128-bit integers and fixed-point types],[
    int128_support=$enableval
],[
    int128_support=no
])

AC_SUBST([float_support])
AC_SUBST([int128_support])

AC_CONFIG_FILES([Makefile])


AC_OUTPUT
