# Senders-Receivers
1.First implement the reverse_implement_in_par.cpp; Use Zip_iterator & two for loops to implement parallel reverse 

    Following the two for loop ideas in there, put the idea into sender of reverse.



// sync_wait_with_variant test check : get the right command line

        ctest -R tests.unit.modules.execution.algorithm_sync_wait_with_variant
    refer the cmakelist.txt file :
        add_hpx_unit_test("modules.execution" ${test} ${${test}_PARAMETERS}), so add modules.execution to the command line, works
    
