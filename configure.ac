AC_INIT([snes-dev])

AC_CONFIG_MACRO_DIRS([m4/])

AC_CANONICAL_HOST

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

AC_ARG_ENABLE([float-support],[
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

AC_ARG_ENABLE([int128],[Enable support for 128-bit integers and fixed-point types])

AC_SUBST(float_support)

AC_CONFIG_FILES([Makefile])


AC_OUTPUT
