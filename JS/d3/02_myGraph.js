var dataSet = [300, 100, 5, 60, 240]

// // 01
// d3.select("#myGraph")
//   .append("rect") // <rect x={X_Axis} y={Y_Axis} width={width} height={height}></rect>
//   .attr("x", 0)
//   .attr("y", 0)
//   .attr("width", dataSet[0])
//   .attr("height", 20)
// d3.select("#myGraph")
//   .append("rect") // <rect x={X_Axis} y={Y_Axis} width={width} height={height}></rect>
//   .attr("x", 0)
//   .attr("y", 25)
//   .attr("width", dataSet[1])
//   .attr("height", 20)
// d3.select("#myGraph")
//   .append("rect") // <rect x={X_Axis} y={Y_Axis} width={width} height={height}></rect>
//   .attr("x", 0)
//   .attr("y", 50)
//   .attr("width", dataSet[2])
//   .attr("height", 20)
// d3.select("#myGraph")
//   .append("rect") // <rect x={X_Axis} y={Y_Axis} width={width} height={height}></rect>
//   .attr("x", 0)
//   .attr("y", 75)
//   .attr("width", dataSet[3])
//   .attr("height", 20)
// d3.select("#myGraph")
//   .append("rect") // <rect x={X_Axis} y={Y_Axis} width={width} height={height}></rect>
//   .attr("x", 0)
//   .attr("y", 100)
//   .attr("width", dataSet[4])
//   .attr("height", 20)
// 02
d3.select("#myGraph")
  .selectAll("rect")
  .data(dataSet)
  .enter()
  .append("rect")
  .attr("x", 10)
  .attr("y", function (d, i) {
    return i * 25
  })
  .attr("height", "20px")
  .attr("width", "0px")
  // .on("click", function () { // it was not work append on last in this method chain.
  //   d3.select(this)
  //     .style("fill", "cyan")
  // })
  .on("mouseover", function () {
    d3.select(this)
      .style("fill", "cyan")
  })
  .on("mouseout", function () {
    d3.select(this)
      .style("fill", "red")
  })
  .transition()
  .delay(function (d, i) {
    return i * 0
  })
  .duration(1000)
  .attr("width", function (d, i) {
    return d + "px"
  })

var xScale = d3.scale.linear()
  .domain([0, 300])
  .range([0, 300])
d3.select("#myGraph")
  .append("g")
  .attr("class", "axis")
  .attr("transform", "translate(10, " + ((1 + dataSet.length) * 20 + 5) + ")")
  .call(d3.svg.axis()
    .scale(xScale)
    .orient("bottom")
  )

// change data of chart, when click updateButton
d3.select("#updateButton") // it work evenif myGraph
  .on("click", function () {
    for (var i = 0; i < dataSet.length; i++) {
      dataSet[i] = Math.floor(Math.random() * 300)
    }
    d3.select("#myGraph")
      .selectAll("rect")
      .data(dataSet)
      .transition()
      .duration(1000)
      .attr("width", function (d, i) {
        return d + "px"
      })
  })