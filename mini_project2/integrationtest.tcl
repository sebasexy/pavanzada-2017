#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}


#Put your test case here
eval spawn [lrange $argv 0 end]

expect "Give me the first int: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "0\r"
expect "Give me the second int: "
send "1\r"
expect "The sum of 0 and 1 is: 1"

#Put your test case here
eval spawn [lrange $argv 0 end]

expect "Give me the first int: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
send "1\r"
expect "Give me the second int: "
send "0\r"
expect "The sum of 1 and 0 is: 1"

#expect "Give me the first int: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#send "666\r"
#expect "Give me the second int: "
#send "1000\r"
#expect "The sum of 666 and 1000 is: 1666"

#expect "Give me the first int: " {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#send "654321\r"
#expect "Give me the second int: "
#send "123456\r"
#expect "The sum of 654321 and 123456 is: 777777"

#expect "W" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#send "0101\r"
#expect "name: Angel Perez, semestre: 6" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
