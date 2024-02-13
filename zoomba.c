#include <stdio.h>
#include <stdlib.h>


int solve(int dimensions, int **p, int zoomba_x, int zoomba_y, int target_x, int target_y) {
	int check;
	static int n = 2;
	p[zoomba_x][zoomba_y] = n++;
	if((zoomba_x == target_x) && (zoomba_y == target_y)) {
		return 1;
	}
	if(zoomba_x > target_x) {									//target is higher than zoomba
		check = (p[zoomba_x - 1][zoomba_y] == 0);
		if(check == 1) {
			if(solve(dimensions, p, zoomba_x - 1, zoomba_y, target_x, target_y) == 1) {
				return 1;
			} 
		}
		if(check == 0) {
			if(zoomba_y > target_y) {
				check = (p[zoomba_x][zoomba_y - 1] == 0);
				if(check == 1) {
					if(solve(dimensions, p, zoomba_x, zoomba_y - 1, target_x, target_y)){
						return 1;
					}
				}
				int can_move_down = (zoomba_x != dimensions - 1) && (p[zoomba_x + 1][zoomba_y] == 0);
				int can_move_right = (zoomba_y != dimensions - 1) && (p[zoomba_x][zoomba_y + 1] == 0);
				if((can_move_right == 0) && (can_move_down == 0)) {
					p[zoomba_x][zoomba_y] = 0;
					n--;
					return 0;
				}
				if(can_move_right) {
					if(solve(dimensions, p, zoomba_x, zoomba_y + 1, target_x, target_y) == 1) {
						return 1;
					}
				}
				if(can_move_down == 1) {
					if(solve(dimensions, p, zoomba_x + 1, zoomba_y, target_x, target_y) == 1) {
						return 1;
					}
				}
			}
			p[zoomba_x][zoomba_y] = 0;
			n--;
			return 0;
		}
	}
	if(zoomba_y > target_y) {									//target is left of zoomba
		check = (p[zoomba_x][zoomba_y - 1] == 0);
		if(check == 1) {
			if(solve(dimensions, p, zoomba_x, zoomba_y - 1, target_x, target_y) == 1) {
				return 1;
			} 
		}
		if(check == 0) {
			if(zoomba_x <= target_x) {
				check = ((zoomba_x != dimensions - 1) && (p[zoomba_x + 1][zoomba_y] == 0));
				if(check == 1) {
					if(solve(dimensions, p, zoomba_x + 1, zoomba_y, target_x, target_y)){
						return 1;
					}
				}
				int can_move_up = (zoomba_x != 0) && (p[zoomba_x - 1][zoomba_y] == 0);
				int can_move_right = (zoomba_y != dimensions - 1) && (p[zoomba_x][zoomba_y + 1] == 0);
				if((can_move_right == 0) && (can_move_up == 0)) {
					p[zoomba_x][zoomba_y] = 0;
					n--;
					return 0;
				}
				if(can_move_right) {
					if(dimensions, solve(dimensions, p, zoomba_x, zoomba_y + 1, target_x, target_y) == 1) {
						return 1;
					}
				}
				if(can_move_up == 1) {
					if(solve(dimensions, p, zoomba_x - 1, zoomba_y, target_x, target_y) == 1) {
						return 1;
					}
				}
			}
			p[zoomba_x][zoomba_y] = 0;
			n--;
			return 0;	
		}
	}
	if(zoomba_x <= target_x) {									//target is lower than zoomba
		check = ((zoomba_x != dimensions - 1) && (p[zoomba_x + 1][zoomba_y] == 0));
		if(check == 1) {
			if(solve(dimensions, p, zoomba_x + 1, zoomba_y, target_x, target_y) == 1) {
				return 1;
			} 
		}
		if(check == 0) {
			if(zoomba_y <= target_y) {
				check = ((zoomba_y != dimensions - 1) && (p[zoomba_x][zoomba_y + 1] == 0));
				if(check == 1) {
					if(solve(dimensions, p, zoomba_x, zoomba_y - 1, target_x, target_y)){
						return 1;
					}
				}
				int can_move_up = (zoomba_x != 0) && (p[zoomba_x - 1][zoomba_y] == 0);
				int can_move_left = (zoomba_y != 0) && (p[zoomba_x][zoomba_y - 1] == 0);
				if((can_move_left == 0) && (can_move_up == 0)) {
					p[zoomba_x][zoomba_y] = 0;
					n--;
					return 0;
				}
				if(can_move_left) {
					if(solve(dimensions, p, zoomba_x, zoomba_y - 1, target_x, target_y) == 1) {
						return 1;
					}
				}
				if(can_move_up == 1) {
					if(solve(dimensions, p, zoomba_x - 1, zoomba_y, target_x, target_y) == 1) {
						return 1;
					}
				}
			}
			p[zoomba_x][zoomba_y] = 0;
			n--;
			return 0;	
		}
	}
	if(zoomba_y <= target_y) {									//target is right of zoomba
		check = ((zoomba_y != dimensions - 1) && (p[zoomba_x][zoomba_y + 1] == 0));
		if(check == 1) {
			if(solve(dimensions, p, zoomba_x, zoomba_y + 1, target_x, target_y) == 1) {
				return 1;
			} 
		}
		if(check == 0) {
			if(zoomba_x > target_x) {
				check = (p[zoomba_x - 1][zoomba_y] == 0);
				if(check == 1) {
					if(solve(dimensions, p, zoomba_x + 1, zoomba_y, target_x, target_y)){
						return 1;
					}
				}
				int can_move_down = (zoomba_x != dimensions - 1) && (p[zoomba_x + 1][zoomba_y] == 0);
				int can_move_left = (zoomba_y != 0) && (p[zoomba_x][zoomba_y - 1] == 0);
				if((can_move_left == 0) && (can_move_down == 0)) {
					p[zoomba_x][zoomba_y] = 0;
					n--;
					return 0;
				}
				if(can_move_left) {
					if(solve(dimensions, p, zoomba_x, zoomba_y - 1, target_x, target_y) == 1) {
						return 1;
					}
				}
				if(can_move_down == 1) {
					if(solve(dimensions, p, zoomba_x + 1, zoomba_y, target_x, target_y) == 1) {
						return 1;
					}
				}
			}
			p[zoomba_x][zoomba_y] = 0;
			n--;
			return 0;	
		}
	}
}

void output(int dimensions, int **p, int zoomba_x, int zoomba_y, int target_x, int target_y) {
	int n = 2;
	while((zoomba_x != target_x) || (zoomba_y != target_y)) {
		int check;
		if((zoomba_x) != 0) {
			check = (p[zoomba_x - 1][zoomba_y] != 0) && (p[zoomba_x - 1][zoomba_y] != 1) && (p[zoomba_x - 1][zoomba_y] == (n + 1));
			if(check = 1) {
				putchar('U');
				p[zoomba_x][zoomba_y] = 0;
				zoomba_x--;
			}
		}
		if((zoomba_x) != (dimensions - 1)) {
			check = (p[zoomba_x + 1][zoomba_y] != 0) && (p[zoomba_x + 1][zoomba_y] != 1) && (p[zoomba_x - 1][zoomba_y]  == (n + 1));
			if(check = 1) {
				putchar('D');
				p[zoomba_x][zoomba_y] = 0;
				zoomba_x++;
			}
		}
		if((zoomba_y) != 0) {
			check = (p[zoomba_x][zoomba_y - 1] != 0) && (p[zoomba_x][zoomba_y - 1] != 1) && (p[zoomba_x][zoomba_y - 1] == (n + 1));
			if(check = 1) {
				putchar('R');
				p[zoomba_x][zoomba_y] = 0;
				zoomba_y--;
			}
		}
		if((zoomba_y) != (dimensions - 1)) {
			check = (p[zoomba_x][zoomba_y + 1] != 0) && (p[zoomba_x][zoomba_y + 1] != 1) && (p[zoomba_x][zoomba_y + 1] == (n + 1));
			if(check = 1) {
				putchar('L');
				p[zoomba_x][zoomba_y] = 0;
				zoomba_y++;
			}
		}
		n++;
	}
}

int main() {
	char c;
	int dim = 0;
	while ((c = getchar()) != '\n') {
		if (c < 48 || c > 57)			// not a number
			return 1;

		dim *= 10;	
		dim = dim + c - 48;
	}
	
	int zoomba_x = 0, zoomba_y = 0, target_x = 0, target_y = 0;
	int count = 0, flag = 1;
	
	while ((c = getchar()) != '\n') {
		if ((c < '0' || c > '9') && (c != ' ' && c != '\t'))			// not a number and not a white character
			return 1;
		
		if (c == ' ' || c == '\t') {									// white characters
			if (flag)
				count++;
				
			flag = 0;
			continue;
		}
			
		flag = 1;
		
		if (count > 3) {
			printf("too many arguments\n");
			return  1;
		}
			
		if (!count) {
			zoomba_x *= 10;	
			zoomba_x = zoomba_x + c - 48;
		}
		
		if (count == 1) {
			zoomba_y *= 10;	
			zoomba_y = zoomba_y + c - 48;
		}
		
		if (count == 2) {
			target_x *= 10;	
			target_x = target_x + c - 48;
		}
		
		if (count == 3) {
			target_y *= 10;	
			target_y = target_y + c - 48;
		}
	}
	
	int i, j;
	int **room_map = malloc(sizeof(int*) * dim);
	for(i = 0; i < dim; i++) {
		room_map[i] = malloc(sizeof(int) * dim);
	}
	char input;

	for(i = 0; i < dim; i++) {
		j = 0;
		while((input = getchar()) != '\n') {
			room_map[i][j] = input - 48;

			if((room_map[i][j] != 0) && (room_map[i][j] != 1))
				return 1;

			if(j > (dim - 1))
				return 1;
				
			j++;
		}
	}

	int temp_x = zoomba_x;
	int temp_y = zoomba_y;
	
	solve(dim, room_map, zoomba_x, zoomba_y, target_x, target_y);
	output(dim, room_map, temp_x, temp_y, target_x, target_y);
}
