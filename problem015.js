function main () {
    var gridSize = process.argv[2];
    var grid =  new Grid (gridSize);

    while (true) {

    }

    /* Approach? Could either go through it linearly forward or recursively backward
     * I think the best way is to have a number of paths from each point, that way you
     * Can go backwards
     */
}

// Upper left is (0,0)
function Grid (gridSize) {
    var verticesMap = [];
    
    for (var i = 0; i <= gridSize; i++) {
        verticesMap[i] = [];
        for (var j = 0; j <= gridSize; j++) {
            verticesMap[i][j] = {x:i, y:j, found:false, resolved:false};
        }
    }

    verticesMap[gridSize][gridSize].found = true;
    verticesMap[gridSize][gridSize].resolved = true;
    verticesMap[gridSize][gridSize].paths = 1;

    this.map = verticesMap;
    this.gridSize = gridSize;
    this.points = [verticesMap[gridSize][gridSize]];
    this.next = [];
}

Grid.prototype.getNextPoints = function () {
    var that = this;
    this.points.forEach(function (point) {
        if (point.x - 1 >= 0 && !that.map[point.x - 1][point.y].found) {
            that.next.push(that.map[point.x - 1][point.y]);
            that.map[point.x - 1][point.y].found = true;
        }
        if (point.y - 1 >= 0 && !that.map[point.x][point.y - 1].found) {
            that.next.push(that.map[point.x][point.y - 1]);
            that.map[point.x][point.y - 1].found = true;
        }
    });
};

Grid.prototype.attemptResolve = function () {
    var that = this;
    this.next.forEach(function (point) {
        var rightVert, downVert, includeRight=false, includeDown=false;
        if (point.x + 1 < that.gridSize) {
            includeRight = true;
        } 
        if (includeRight && that.map[point.x + 1][point.y].resolved) {
            rightVert = that.map[point.x + 1][point.y].paths;
        } 
        if (point.y + 1 < that.gridSize && that.map[point.x][point.y + 1].resolved) {
            downVert = that.map[point.x][point.y + 1].paths;
        }
    });
}


function forceParseFloat (n) {
    n = parseFloat(n);
    if (isNaN(n)) {
        return 0;
    } else {
        return n;
    }
}
