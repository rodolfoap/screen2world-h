execute(){
	./calculate_h test/placewilson.yaml
echo	./transform homography_matrix.yaml 690 345
	./transform homography_matrix.yaml 690 345
	echo
echo	./transform homography_matrix.yaml 463 463
	./transform homography_matrix.yaml 463 463
	echo
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
