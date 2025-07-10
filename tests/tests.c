/** @file test.c
 ******************************************************************************
 * @brief The purpose of this file is to test testing and to call the
 * tests of some minor functions.
 *
 * @par
 * Kasey Clarke June 6 2025
 */


 #include "tests.h"
 #include "templates/template.h"
 #include "test_percent.h"
 #include "test_points.h"
 
 #include <assert.h>
 #include <stdio.h>
 

 // private function prototype
 static inline void test_connection (); 
 
 
 // public function body
 /*!
  * @brief This function runs some smaller tests that don't need input.
  *
  * @param void
  *
  * @return void
  */
 void
 test_internals ()
 {
    test_connection();
    test_percent();
    test_points();
    test_dealer();

    printf("Passed %s.\n", __func__);
 }
 

 // private function body
 /*!
  * @brief This function test to see if the files are connected properly
  *
  * @param void
  *
  * @return void
  */
 static inline void
 test_connection ()
 {
     // Can we run the function in the template file?
     assert(7 == max8(5, 7));
 }

 /*** end of file ***/