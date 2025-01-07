const grid = document.getElementById("canvas");
const button = document.getElementById("start");
let drag = false;
let dir = [[-1,-1],[-1,0],[-1,1],[0,-1],[0,1],[1,-1],[1,0],[1,1],]
let mat = [];
let rows = 200;
let cols = 200;
for (let i = 0; i < rows; i++) {
    mat[i] = [];
    for (let j = 0; j < cols; j++) {
        mat[i][j] = 0;
    }
}
let matTemp = [];
for (let i = 0; i < rows; i++) {
    matTemp[i] = [];
    for (let j = 0; j < cols; j++) {
        matTemp[i][j] = 0;
    }
}

for(let i=0;i<rows;i++)
{   for(let j=0;j<cols;j++)
    {
        const cell=document.createElement("div");
        cell.classList.add('cell');
        cell.dataset.row=i;
        cell.dataset.col=j;
        grid.appendChild(cell);
    }
}

const cellArray = document.querySelectorAll(".cell");
function startSeq(){
    mat[38][92]=1;
    cellArray[(38*rows)+92].classList.toggle("alive");
    mat[37][92]=1;
    cellArray[(37*rows)+92].classList.toggle("alive");
    mat[39][92]=1;
    cellArray[(39*rows)+92].classList.toggle("alive");
    mat[38][91]=1;
    cellArray[(38*rows)+91].classList.toggle("alive");
    mat[39][93]=1;
    cellArray[(39*rows)+93].classList.toggle("alive");
}
startSeq();
{ //Event for click and drag
grid.addEventListener('mousedown', (event) => {
    if (event.target.classList.contains('cell')) {
        drag = true;
        toggleCell(event.target);
    }
});
grid.addEventListener('mouseover', (event) => {
    if (drag && event.target.classList.contains('cell')) {
        toggleCell(event.target);
    }
});
document.addEventListener('mouseup', () => {
    drag = false;
});
}

function toggleCell(cell) {
    // let cell = event.target;
    // cell.classList.toggle('alive');
    let matElement = mat[cell.dataset.row][cell.dataset.col];
    // console.log(matElement,cell.dataset.row,cell.dataset.col);
    if(matElement === 1)
    {
        mat[cell.dataset.row][cell.dataset.col]=0;
        cell.classList.toggle("alive");
    }
    else if(matElement ===0 )
    {
        mat[cell.dataset.row][cell.dataset.col]=1;
        cell.classList.toggle("alive");
        
    }
}

function changeCell(cell)
{
    cell.classList.toggle('alive');
}

function next(){
    // resetMat();
    //working on the real matrix
    for (let i = 0; i < rows; i++) 
    {
        for (let j = 0; j < cols; j++) {
            {
                let alive = 0;
                for(let k=0;k<8;k++)
                {
                    let newRow = i+dir[k][0];
                    let newCol = j+dir[k][1];
                    if(newRow > 0 && newRow < rows && newCol > 0 && newCol < cols)
                    {
                        if(mat[newRow][newCol]===1)
                        {
                            alive+=1;
                        }
                    }
                }
                if(mat[i][j]===1)
                {
                    if(alive<2)
                    {
                        matTemp[i][j]=0;
                    }
                    else if(alive ===3 || alive === 2)
                    {
                        matTemp[i][j]=1;
                    }
                    else if(alive >3)
                    {
                        matTemp[i][j]=0;
                    }
                }
                else if(mat[i][j]===0)
                {
                    if(alive===3)
                    {
                        matTemp[i][j]=1;
                    }
                }

            }
        }
    }
    //copying to real matrix and setting dom
    for(let i=0;i<rows;i++)
    {
        for(let j=0;j<cols;j++)
        {
            if(mat[i][j]!=matTemp[i][j])
            {
                mat[i][j]=matTemp[i][j];
                changeCell(cellArray[(i*rows)+j]);
            }
        }
    }
}

button.addEventListener("click",(event)=>
{   
    event.preventDefault();
    function nextGeneration() {
        next();  
        setTimeout(nextGeneration, 10);  
    }

    nextGeneration(); 
});

function benchmark() {
    const startTime = performance.now();  // Record start time
    next();  // Call the function
    const endTime = performance.now();  // Record end time

    const duration = endTime - startTime;  // Time taken in milliseconds
    console.log(`Function execution time: ${duration} ms`);
}

document.getElementById("test").addEventListener("click",(event)=>
    {   
        event.preventDefault();
        benchmark();
    });



