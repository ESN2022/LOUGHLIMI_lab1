
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity lab1_inst is

    port
        (clk_clk : in std_logic;
        reset_reset_n : in std_logic;
        pio_0_external_connection_export : in std_logic_vector(7 downto 0);
        pio_1_external_connection_export : out std_logic_vector(7 downto 0));
        
end lab1_inst;


architecture ARCH of lab1_inst is        
        
    component lab1 is
        port (
            clk_clk                          : in  std_logic                    := 'X';             -- clk
            pio_0_external_connection_export : in std_logic_vector(7 downto 0);                    -- export
            pio_1_external_connection_export : out  std_logic_vector(7 downto 0) := (others => 'X'); -- export
            reset_reset_n                    : in  std_logic                    := 'X'              -- reset_n
        );
    end component lab1;

    begin
    
    U : lab1 port map(clk_clk, pio_0_external_connection_export, pio_1_external_connection_export, reset_reset_n);
    
end ARCH;
