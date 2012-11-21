#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init compiler wrapper"

cat > wrapper.c <<EOF
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (strstr(argv[0], "gcc") == NULL) {
		fprintf(stderr, "wrapper: wrong usage!\n");
		exit(EXIT_FAILURE);
	}

	argv[0] = "/usr/bin/gcc";
	return execvp(argv[0], argv);
}
EOF

cat > test.c <<EOF
int main() {}
EOF

gcc wrapper.c -o wrapper

ln -s wrapper gcc

$ROOT/bin/atos-explore -b "./gcc test.c" \
    -r "echo user 2" --optim-levels=-O2 --optim-variants=base

$ROOT/bin/atos-explore -b "./gcc test.c" --force -e ./a.out \
    -r "echo user 2" --optim-levels=-O2 --optim-variants=base

export PATH=".:$PATH"

$ROOT/bin/atos-explore -b "gcc test.c" \
    -r "echo user 2" --optim-levels=-O2 --optim-variants=base


