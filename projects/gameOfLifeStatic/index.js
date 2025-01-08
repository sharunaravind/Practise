const grid = document.getElementById("canvas");
const start = document.getElementById("start");
const clear = document.getElementById("clear");
let drag = false;
let dir = [
  [-1, -1],
  [-1, 0],
  [-1, 1],
  [0, -1],
  [0, 1],
  [1, -1],
  [1, 0],
  [1, 1],
];
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

for (let i = 0; i < rows; i++) {
  for (let j = 0; j < cols; j++) {
    const cell = document.createElement("div");
    cell.classList.add("cell");
    cell.dataset.row = i;
    cell.dataset.col = j;
    grid.appendChild(cell);
  }
}
const cellArray = document.querySelectorAll(".cell");
grid.scrollLeft = 320;
grid.scrollTop = 720;
const startRow = 100;
const startCol = 100;
function startSeq() {
  mat[startRow][startCol] = 1;
  cellArray[startRow * rows + startCol].classList.toggle("alive");
  mat[startRow + 1][startCol] = 1;
  cellArray[(startRow + 1) * rows + startCol].classList.toggle("alive");
  mat[startRow - 1][startCol] = 1;
  cellArray[(startRow - 1) * rows + startCol].classList.toggle("alive");
  mat[startRow][startCol - 1] = 1;
  cellArray[startRow * rows + (startCol - 1)].classList.toggle("alive");
  mat[startRow + 1][startCol + 1] = 1;
  cellArray[(startRow + 1) * rows + (startCol + 1)].classList.toggle("alive");
}
startSeq();
{
  //Event for click and drag

  grid.addEventListener("mousedown", (event) => {
    const cell = event.target.closest(".cell");
    if (cell) {
      drag = true;
      toggleCell(cell);
    }
  });
  grid.addEventListener("mouseover", (event) => {
    const cell = event.target.closest(".cell");
    if (drag && cell) {
      toggleCell(cell);
    }
  });
  document.addEventListener("mouseup", () => {
    drag = false;
  });
}

function toggleCell(cell) {
  let matElement = mat[cell.dataset.row][cell.dataset.col];
  if (matElement === 1) {
    mat[cell.dataset.row][cell.dataset.col] = 0;
    cell.classList.toggle("alive");
  } else if (matElement === 0) {
    mat[cell.dataset.row][cell.dataset.col] = 1;
    cell.classList.toggle("alive");
  }
}

function changeCell(cell, number) {
  cell.classList.toggle("alive");
}

function next() {
  //working on the real matrix
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      {
        let alive = 0;
        for (let k = 0; k < 8; k++) {
          let newRow = i + dir[k][0];
          let newCol = j + dir[k][1];
          if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
            if (mat[newRow][newCol] === 1) {
              alive += 1;
            }
          }
        }
        if (mat[i][j] === 1) {
          if (alive < 2) {
            matTemp[i][j] = 0;
          } else if (alive === 3 || alive === 2) {
            matTemp[i][j] = 1;
          } else if (alive > 3) {
            matTemp[i][j] = 0;
          }
        } else if (mat[i][j] === 0) {
          if (alive === 3) {
            matTemp[i][j] = 1;
          }
        }
      }
    }
  }
  //copying to real matrix and setting dom
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      if (mat[i][j] != matTemp[i][j]) {
        mat[i][j] = matTemp[i][j];
        changeCell(cellArray[i * rows + j], mat[i][j]);
      }
    }
  }
}

let running = false;

start.addEventListener("click", (event) => {
  event.preventDefault();
  if (running) {
    running = false;
    return;
  }
  running = true;
  function nextGeneration() {
    if (!running) return;
    next();
    setTimeout(nextGeneration, 20);
  }
  nextGeneration();
});

clear.addEventListener("click", (event) => {
  event.preventDefault();
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      matTemp[i][j] = 0;
      if (mat[i][j] === 1) {
        mat[i][j] = 0;
        cellArray[i * rows + j].classList.toggle("alive");
      }
    }
  }
});

function benchmark() {
  const startTime = performance.now();
  next();
  const endTime = performance.now();
  const duration = endTime - startTime;
  console.log(`Function execution time: ${duration} ms`);
}

document.getElementById("test").addEventListener("click", (event) => {
  event.preventDefault();
  benchmark();
});
