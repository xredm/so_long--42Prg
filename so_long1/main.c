# include "./minilibx-linux/mlx.h"

int  main()
{
  void  *mlx_ptr;
  void  *win_ptr;

  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "MLX");
  mlx_loop(mlx_ptr);
}