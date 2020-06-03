# Camera-To-World

Simplest application, takes the _homography matrix_ and a screen point, so to generate its corresponding world point.

Better if used with the results of https://github.com/rodolfoap/points-picker.

This application is useful in case of finding the world coordinates of a point (for example, latitude, longitude, using the WGS84 _datum_) that corresponds to some screen coordinates. That is, having the screen coordinates from a camera image showing where is a person, it is possible to find his world coordinates. The `transform.cpp` example produces a transform for one point, but being the input a `vector<>`, multiple points can be transformed at a time.

* To find better screen-to-world correspondences (which point in the space in the camera image corresponds to a point in the screen), an _extrinsics matrix_ is required. See the full calculation here: https://github.com/rodolfoap/screen2world-k. In such example, the _extrinsics matrix_ is calculated using a set of world-to-screen point correspondences.
* To find screen-to-world correspondences, another approach is proposed: See the full calculation here: https://github.com/rodolfoap/screen2world-d. In such example, the _extrinsics matrix_ is calculated by using a set of person detection boxes to calculate the distances to the camera. Knowing the camera bearing, world-to-screen points correspondences are automatically found, and the _extrinsics matrix_ is calculated in some steps.
* Both previous applications require an _intrinsics matrix_ (also called _calibration matrix_, _camera matrix_ or _K matrix_) which can be calculated using https://github.com/rodolfoap/cameracalibration.

## Build

```
mkdir -p build && pushd $_;
cmake ..
make
popd
```

## Usage

### Generate the points matrix

* Use https://github.com/rodolfoap/points-picker to generate the points matrix
* Or check the `test/placewilson.yaml` format and create an equivalent file, containing correspondences between image points and camera points

### Generate the homography matrix (**H**), taking a set of screen to world correspondences.

```
./calculate_h test/placewilson.yaml

Image Points:
[87, 647;
 382, 444;
 369, 327;
 645, 144;
 703, 141;
 897, 180;
 948, 219;
 1032, 338;
 757, 579;
 100, 276;
 76, 263]

World Points:
[43.60545, 1.448632, 0;
 43.605026, 1.448012, 0;
 43.60479, 1.448023, 0;
 43.604374, 1.447412, 0;
 43.604362, 1.4472769, 0;
 43.604469, 1.446902, 0;
 43.604534, 1.446805, 0;
 43.604824, 1.446698, 0;
 43.60532, 1.447323, 0;
 43.604691, 1.4485461, 0;
 43.60466, 1.448594, 0]

H:
[-0.001116998977051527, 0.007456385647792688, 43.60405206651423;
 -3.917464387597672e-05, 0.0002477793052491741, 1.448710925125969;
 -2.561627763780111e-05, 0.0001709471833457758, 1]
```

### Input **x** and **y** screen coordinates, to obtain world coordinates:

```
./transform homography_matrix.yaml 690 345
[690, 345]>[43.604828, 1.4473851]

./transform homography_matrix.yaml 463 463
[463, 463]>[43.60508, 1.4478703]

```

## Example generated YAML file

```
%YAML:1.0
---
homography_matrix: !!opencv-matrix
   rows: 3
   cols: 3
   dt: d
   data: [ -1.1169989770515270e-03, 7.4563856477926878e-03,
       4.3604052066514228e+01, -3.9174643875976721e-05,
       2.4777930524917414e-04, 1.4487109251259689e+00,
       -2.5616277637801113e-05, 1.7094718334577578e-04, 1. ]
```
