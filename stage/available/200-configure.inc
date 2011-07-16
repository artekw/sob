# Copyright 2009 - Claudio Mignanti <c.mignanti@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.

echo Symlink to dl and configuration ...
	ln -sfv /home/artek/dev/openwrt/sources $DL/dl
	cp -a $P/conf/files-$step/* $DL/
	
	echo CONFIG_HAVE_DOT_CONFIG=y > $DL/.config
    echo CONFIG_TARGET_"$ARCH"=y >> $DL/.config
	echo CONFIG_TARGET_"$ARCH"_Default=y >> $DL/.config
	
	for PK in $PKG; do
       	echo CONFIG_PACKAGE_"$PK"=y >> $DL/.config
	done
	for PKM in $PKGM; do
       	echo CONFIG_PACKAGE_"$PKM"=m >> $DL/.config
	done

