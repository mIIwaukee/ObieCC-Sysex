--[[
    I was looking for a way to change a control from another place, and did this with parameterMap.set.
    That works beautifully, only… apart from the changed value of the ‘slave’ control, nothing else 
    was occuring: no MIDI messaging was happening, the attached function was not fired.
    
    And now I have discovered the benefits of
    parameterMap.send (deviceId, parameterType, parameterNumber)
    
    This one allows you to trigger a control, after you have set its value from somewhere else. 
    And that really opens up a set of possibilities

    For instance, I’m making a preset for a bi-timbral synth, which will allow me to control both timbres 
    together or separately, based on a pad position. In this example, the slave control has a parameter 
    number that is 108 above the master control. The master controls have been given the linkPar function 
    below.
    
    To cope with negative values (due to SysEx values generated with Two’s complement sign mode), 
    I add 128 for any negative value. Works nicely
    
    Be aware however, pad values obtained are always 0 or 1, you don’t get the assigned On /Off 
    values with the code below. The link variable = when 1 both controls are tied together, when 0 \
    they work independent
    
 --]]
    
    function linkPar(valueObject, value)
    if link == 0 then
        return
    end

    local message = valueObject:getMessage()
    local parameterNumber = message:getParameterNumber()

    if value < 0 then
        value = value + 128
    end

    parameterMap.set(deviceId, PT_SYSEX, parameterNumber + 108, value)
    parameterMap.send(deviceId, PT_SYSEX, parameterNumber + 108)
end