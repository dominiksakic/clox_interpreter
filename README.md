# clox_interpreter

source: https://craftinginterpreters.com/scanning.html

## simple scanner compelte:
### Can do:
- REPL, Read file.
- Scan strings, numbers, keywords, and operators.
- Numbers are all handled as doubles currently.

### To improve
- error handling not implemented yet.
- not efficient handling of keywords(TRI/HASHMAPS)

### Notes:
1. What am I optimizing for?
   - Dependability
   - Extendability
   - Reduce risk.
2. What can change?
   - platform (insulate)
   - implementations

3. Modules are black boxes and communicate and collaborate using APIs/Protocols.

4. No calls directly to code that I dont control (wrap it)

5. Think through the API and nail it, the rest can be changed, the API should not.

6. What can I do? What can they tell me?
   - I am a washing machine, I am currently running, I am running in mode, with temperature and am loaded with x and have x seconds left running:
   - typedef struct{
   - char *name
   - bool running
   - Programs mode
   - uint temperature
   - float load_weight
   - uint seconds_left
   - } Capability
     
   - I can run in mode x with temperature
   - typedef struct {
   - bool run;
   - Programs mode;
   - uint temperature}
     


   
