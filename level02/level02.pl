use strict;
use warnings;

sub to_big_endian_ascii {
    my ($hex) = @_;

    # strip "0x"
    $hex =~ s/^0x//i;

    # make bytes
    my $bytes = pack("H*", $hex);

    # interpret as little endian u64
    my $num_le = unpack("Q<", $bytes);

    # pack as big endian
    my $num_be = pack("Q>", $num_le);

    # return as ASCII string
    return $num_be;
}

my @values = split /\s+/, "0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d";

my $result = join("", map { to_big_endian_ascii($_) } @values);

print "Resulting string: $result\n";
