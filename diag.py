from graphviz import Digraph

def generate_class_diagram(classes, associations, output_file):
    """Generate class diagram with specific layout using Graphviz."""
    dot = Digraph(comment='Class candy crush', graph_attr={'rankdir': 'BT'})  # Set rankdir to 'TB' for vertical layout
    

    
    for class_name, attributes, methods in classes:
        attributes_str = "\\l".join(attributes) + "\\l"
        methods_str = "\\l".join(methods) + "\\l"
        
        # Escape special characters and type declarations
        attributes_str = attributes_str.replace("<", "\<").replace(">", "\>")
        methods_str = methods_str.replace("<", "\<").replace(">", "\>")
        
        class_label = f"{{ {class_name} | {attributes_str} | {methods_str} }}"
        
        dot.node(class_name, label=class_label, shape='record')

    # Add associations
    for (class1, class2, link_type) in associations:
        if link_type == 'composition':
            dot.edge(class1, class2, arrowhead='diamond')
        elif link_type == 'aggregation':
            dot.edge(class1, class2, arrowhead='odiamond')
        elif link_type == 'association':
            dot.edge(class1, class2, arrowhead='normal')
        elif link_type == 'heritage':
            dot.edge(class1, class2, arrowhead='onormal')

    dot.render(output_file, view = True, format='pdf', engine='dot')

if __name__ == "__main__":
    classes = [
        ("app", ["State gamestate", "sf::RenderWindow * window", "GridDisplay gridDisplay", "EventController eventController", "DisplayMenu menuDisplay", "GameData gameData", "int n"],
         ["app(sf::RenderWindow * window , int n )", "~app()", "void start(State gs)", "void playmenu()", "bool playgame()", "void load(std::string filename)", "void save(std::string filename)", "void flushGameData()"]),
        ("DisplayMenu", ["sf::Font font"],
         ["DisplayMenu()", "~DisplayMenu()", "MenuOption displayMenu(sf::RenderWindow& window)", "void displayScoreAndGameOver(sf::RenderWindow& window, int score, bool gameOver)"]),
        ("GridDisplay", ["std::vector<sf::RectangleShape> rectangles", "std::vector<std::vector<int>> gInner", "int n", "sf::Font font", "sf::Text scoreText"],
         ["GridDisplay(int n )", "void processRectClicked(sf::Vector2f mousePos, std::pair<std::pair<int, int>, std::pair<int, int>>& clickedPairs)", "void displayGrid(sf::RenderWindow& window) const", "void updateRectGrid(std::vector<std::vector<int>> g)", "void updateScore(int score, int remainingmove)", "sf::Color intToSFMLColor(int colorCode)"]),
        ("EventController",["GridDisplay * gdisplay","std::pair<std::pair<int, int>, std::pair<int, int>> clickedPairs"],
         ["EventController(GridDisplay *g)","bool handleEvent(sf::RenderWindow& window)","std::pair<std::pair<int, int>, std::pair<int, int>>& getClickedPairs()","bool hasTwoClicked() const","void resetClicked()","bool noRectClicked() const"]),
        ("(Struct) GameData", ["std::vector<std::vector<int>> g", "int score","int movesremaining"],[""]),
        ("Grid", [""],["Grid()", "~Grid()", "bool isValid(vector<vector<int>> g, pair<int, int> c1, pair<int, int> c2)","vector<vector<int>> destructGrid(vector<vector<int>> g , int & score)", "vector<vector<int>> fallGrid(vector<vector<int>> g)", "vector<vector<int>> fillGrid(vector<vector<int>> g)","bool canBeDestruct(vector<vector<int>> g)","bool isSolvable(vector<vector<int>> g)"])]
    
    associations = [
        ("DisplayMenu", "app", "composition"),
        ("GridDisplay", "app", "composition"),
        ("EventController", "app", "composition"),
        ("(Struct) GameData", "app", "composition"),
        ( "GridDisplay","EventController", "aggregation"),
        ("app", "Grid", "heritage")
    ]

    output_file = "class_diagram_specific_positions"

    generate_class_diagram(classes, associations, output_file)
