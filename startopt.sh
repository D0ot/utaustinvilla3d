#/bin/bash

# ./agentspark --host=localhost --port 3100 --team UTAustinVilla_Base 
# --paramsfile paramfiles/defaultParams.txt --mhost=localhost --unum 1 --type 0 --paramsfile paramfiles/defaultParams_t0.txt

cp build/agentspark ./agentspark

./agentspark --unum 2 \
--type 1 \
--paramsfile ./paramfiles/defaultParams.txt \
--paramsfile ./paramfiles/defaultParams_t1.txt \
--optimize walkOptAgent \
--port 3100 \
--mport 3200 \



# /home/doot/robocup3d/utaustinvilla3d/optimization/../agentspark 

#-unum 2 
#-type 
#-paramsfile /home/doot/robocup3d/utaustinvilla3d/optimization/../paramfiles/defaultParams.txt 
#-paramsfile /home/doot/robocup3d/utaustinvilla3d/optimization/../paramfiles/defaultParams_t.txt 
#-paramsfile /home/doot/robocup3d/utaustinvilla3d/optimization/ 
#-experimentout /home/doot/robocup3d/utaustinvilla3d/optimization/ 
#-optimize walkForwardAgent 
#-port 3100 --mport 3200