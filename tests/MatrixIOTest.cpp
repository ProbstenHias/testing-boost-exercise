#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"
using namespace Eigen;

BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(OpenData)
{
  const std::string fileName{"../data/m3.csv"};
  const int         expectedMatrixSize{3};
  MatrixXd          expectedMatrix{3, 3};
  expectedMatrix << 0.680375, 0.59688, -0.329554,
      -0.211234, 0.823295, 0.536459,
      0.566198, -0.604897, -0.444451;

  const Eigen::MatrixXd actualMatrix{matrixIO::openData(fileName, expectedMatrixSize)};
  BOOST_TEST(expectedMatrix == actualMatrix);
}

BOOST_AUTO_TEST_SUITE_END()
