#Rules

- Each philosopher has lifespan. 
- When a philosopher thinks and waits for forks, his time decreases.
- If a philosopher runs out of time, he dies
- When a philosopher eats, he increases his lifetime by the time he eats. 


#Usage

``lab3.exe [SIMULATION_TIME] [LIFESPAN1,LIFESPAN2,...] [THINK_TIME1,THINK_TIME2,...] [EAT_TIME1,EAT_TIME2,...]``

#Test inputs:

##Test #1
``20000 5000,2000,3000,900,900``
- Result: Two philosophers will die, two probably will live forever, one will fight for his life

##Test #2
``20000 5000,2000,1100,1100,1100 500,500,1000,1000,1000``
- Result: Two philosophers will die, two probably will live forever, one will fight for his life

##Test #3
``20000 5000,2000,1100,1100,1100 500,500,1000,1000,1000 2000,2000,1000,1000,1000``
- Result: Three philosophers will die, two will live forever

##Test #3
``20000 5000,2000,1100,1100,1100 500,500,1000,1000,1000 2000,2000,1000,1000,1000``
- Result: Three philosophers will die, two will live forever