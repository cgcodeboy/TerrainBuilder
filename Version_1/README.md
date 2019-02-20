## `TerrainBuilder`
> This small software is used to produce terrain file.

### It will include follow parts:
&emsp;**1. Generator**
> The generator is used to generator the origin terrain data, maybe I will use perlin、vonoroi and other easy algorithms like constant、gradient、radial grad. The user can also draw the origin terrain data in a blank file.

&emsp;**2. Combiner**
> The Combiner is used to conbine several items which have the same output format, and then it will use the inner algorithm to produce a new output which has the same format as the input. Now I decide to design two kind of conbiner, including simple Combiner and constraint Combiner. The former just conbine two input together, but the latter will have a constraint parameter.

&emsp;**3. Filter**
> The filter is used to make some change to the input data. For example, terrace、clamp、add noise、blur and etc.

&emsp;**4. Math**
> It maybe a kind of filter, but I want this kind of item to be independent from the filter items. In this kind of item, the input data can add、subtract、multiply、divide and invert.

&emsp;**5. Nature**
> It maybe also a kind of filter like Math, but the inner algorithm may be more complex than the normal filters. This kind of item will include water、 thermal erosion and etc.

&emsp;**6. Output**
> The output is used to produce the latest terrain file, including texture file and height file. Maybe I will use other storage format to store the terrain.
