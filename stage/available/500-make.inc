# Copyright 2009 - Claudio Mignanti <c.mignanti@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.

echo Run make ...
	cd $DL
#	make clean
	make defconfig
#	make IGNORE_ERRORS=m BUILD_LOG=1
   make V=99 BUILD_LOG=1
