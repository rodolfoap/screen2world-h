execute(){
	./calculate_h test/points_matrix.yaml
echo	./transform homography_matrix.yaml 680 347
	./transform homography_matrix.yaml 680 347
	echo 'Expected:  [43.604852, 1.447372]'
	echo

echo	./transform homography_matrix.yaml 500 482
	./transform homography_matrix.yaml 500 482
	echo 'Expected:  [43.605129, 1.447795]'
	echo

	echo Testing original points:
	./transform homography_matrix.yaml   81 639
	./transform homography_matrix.yaml  377 437
	./transform homography_matrix.yaml  356 328
	./transform homography_matrix.yaml  636 146
	./transform homography_matrix.yaml  693 142
	./transform homography_matrix.yaml  892 185
	./transform homography_matrix.yaml  936 219
	./transform homography_matrix.yaml 1024 335
	./transform homography_matrix.yaml  748 573
	./transform homography_matrix.yaml   90 279
	./transform homography_matrix.yaml   67 265
}
build(){
	mkdir -p build;
	pushd build &> /dev/null;
	[ -f Makefile ] || cmake .. -Wdev;
	make -j$(nproc); STATUS=$?
	popd &> /dev/null;
}
case "$1" in
	"")
		[ -f calculate_h ] || [ -f transform ] || build
		execute
	;;
	b)
		build
	;;
	e)
		vi -p calculate_h.cpp transform.cpp CMakeLists.txt
		rm -f ${BINARY}
		build;
		execute;
	;;
esac
