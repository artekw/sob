# Copyright 2009 - Claudio Mignanti <c.mignanti@gmail.com>
# Copyright 2010 - Artur Wronowski <arteqw@gmail.com>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.

echo Copy files to local repository..
	cd $DL
	REV=`./scripts/getver.sh`
	cd $P
	REPO_DIR=repo/$step/$REV
	mkdir -p $REPO_DIR
	for ff in $F_FILES
	do
	   files=$(ls $DL/bin/$ARCH/*$ff* 2>/dev/null | sed 's/^.*\///g')
	   for f in $files
	   do
	       rsync -av $DL/bin/$ARCH/$f $REPO_DIR
	   done
	done

	if [ $step != "backfire_ar71xx_nousb" ]; then
		rsync -av $DL/bin/$ARCH/packages $REPO_DIR
	fi
	// mdsumy
	cp $DL/bin/$ARCH/md5sums $REPO_DIR
