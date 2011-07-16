# Copyright 2009 - Claudio Mignanti <c.mignanti@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.

echo Synch with server
	ATOMEK_FTP=/media/atom/ftp
	rm -rf $ATOMEK_FTP/openwrt/backfire/$ARCH/latest
	mkdir -p $ATOMEK_FTP/openwrt/backfire/$ARCH/$REV
	rsync -arv $REPO_DIR/* $ATOMEK_FTP/openwrt/backfire/$ARCH/$REV/
	mkdir -p $ATOMEK_FTP/openwrt/backfire/$ARCH/latest
	rsync -arv $REPO_DIR/* $ATOMEK_FTP/openwrt/backfire/$ARCH/latest/
	rsync -arv $DL/.config $ATOMEK_FTP/openwrt/backfire/$ARCH/$REV/config.$REV
echo Cleaning...
#	rm -rf $REPO_DIR
#	rm -rf $DL/files
#	rm -rf $DL/bin
