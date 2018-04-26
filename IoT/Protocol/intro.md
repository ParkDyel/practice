## Protocol

### [문자열](https://www.w3schools.com/js/js_json_xml.asp)
 - "self describing" (human readable).
 - hierarchical (values within values).
 - can be parsed and used by lots of programming languages.
 - can be fetched with an XMLHttpRequest.
    - XML 
    ```
    <employees>
        <employee>
        <firstName>John</firstName> <lastName>Doe</lastName>
        </employee>
        <employee>
            <firstName>Anna</firstName> <lastName>Smith</lastName>
        </employee>
        <employee>
            <firstName>Peter</firstName> <lastName>Jones</lastName>
        </employee>
    </employees>
    ```

    - JSON 
    ```
    {"employees":[
      { "firstName":"John", "lastName":"Doe" },
      { "firstName":"Anna", "lastName":"Smith" },
      { "firstName":"Peter", "lastName":"Jones" }
    ]}
    ```
### [binary](https://stackoverflow.com/questions/14028293/google-protocol-buffers-vs-json-vs-xml/14029040#14029040)
  - very dense data (small output)
  - hard to robustly decode without knowing the schema (data format is internally ambiguous, and needs schema to clarify)
  - very fast processing
  - not intended for human eyes (dense binary)
    - Google Protocol Buffer
    ```
    // before encoding(proto2)
    message Device {
      required int32 temperature = 1;
      required int32 ampereConsumption = 2;
      required int32 battery = 3;
      required int64 option = 4;
      required bool power = 5;
    }
    // after encoding
    b'\n\r\x04~~~ x01(or x00)'
    ```