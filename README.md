# Senders-Receivers
1.First implement the reverse_implement_in_par.cpp; Use Zip_iterator & two for loops to implement parallel reverse 

    Following the two for loop ideas in there, put the idea into sender of reverse.



2. sync_wait_with_variant test check : get the right command line

        ctest -R tests.unit.modules.execution.algorithm_sync_wait_with_variant
        
    refer the cmakelist.txt file :
        add_hpx_unit_test("modules.execution" ${test} ${${test}_PARAMETERS}), so add modules.execution to the command line, works
        
 3. hpx build error(due to the upate of rostam) and fixed : https://gist.github.com/hcq9102/2fe1b819d29d79fc4c925633f1819c2d
    
