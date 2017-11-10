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

expect "Type number: "
send "5\r"
expect "1\r"
expect "2\r"
expect "Fizz\r"
expect "4\r"
expect "Buzz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}

#Put your test case here
eval spawn [lrange $argv 0 end]

expect "Type number: "
send "15\r"
expect "1\r"
expect "2\r"
expect "Fizz\r"
expect "4\r"
expect "Buzz\r"
expect "Fizz\r"
expect "7\r"
expect "8\r"
expect "Fizz\r"
expect "Buzz\r"
expect "11\r"
expect "Fizz\r"
expect "13\r"
expect "14\r"
expect "FizzBuzz" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}



#expect "What is the id:" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
#send "0101\r"
#expect "name: Angel Perez, semestre: 6" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
