macro ( mim_message_color NAME )
  mim_message ( COLOR ${NAME} "     ${NAME}" )
endmacro ()

function  ( text )
  cmake_parse_arguments ( PARSE_ARGV 0 "_TEXT" "BOLD" "COLOR" "" )

  set ( _TEXT_OPTIONS -E cmake_echo_color --no-newline )

  if ( _TEXT_COLOR )
    string ( TOLOWER "${_TEXT_COLOR}" _TEXT_COLOR_LOWER )
    if( _TEXT_COLOR_LOWER STREQUAL "warning" )
      set ( _TEXT_COLOR_LOWER "yellow" )
    endif ()
    if ( NOT ${_TEXT_COLOR_LOWER} MATCHES "^default|black|red|green|yellow|warning|blue|magenta|cyan|white" )
      mim_message ( "Only these colours are supported:" )
      mim_message_color ( DEFAULT )
      mim_message_color ( BLACK )
      mim_message_color ( RED )
      mim_message_color ( GREEN )
      mim_message_color ( YELLOW )
      mim_message_color ( WARNING )
      mim_message_color ( BLUE )
      mim_message_color ( MAGENTA )
      mim_message_color ( CYAN )
      mim_message_color ( WHITE )
      TEXT ( WARING "Color ${_TEXT_COLOR} is not support." )
    else ()
      list ( APPEND _TEXT_OPTIONS --${_TEXT_COLOR_LOWER} )
    endif ()
  endif ()

  if ( _TEXT_BOLD )
    list ( APPEND _TEXT_OPTIONS --bold )
  endif ()

  execute_process ( COMMAND ${CMAKE_COMMAND} -E env CLICOLOR_FORCE=1 ${CMAKE_COMMAND} ${_TEXT_OPTIONS} "-- " ${_TEXT_UNPARSED_ARGUMENTS}
          OUTPUT_VARIABLE _TEXT_RESULT
          ECHO_ERROR_VARIABLE
          )

  set ( TEXT_RESULT ${_TEXT_RESULT} PARENT_SCOPE )
endfunction ()
unset ( mim_message_color )

function ( mim_message )
  text ( ${ARGN} )
  message ( ${TEXT_RESULT} )
endfunction ()
