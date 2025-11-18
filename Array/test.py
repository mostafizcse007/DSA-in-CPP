import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import matplotlib.patches as patches
from matplotlib.offsetbox import AnchoredText


def bfs_steps_enhanced(G, start):
    visited_order = []
    visited = set()
    queue = [start]
    steps = []
    distance = {start: 0}

    while queue:
        current = queue.pop(0)
        if current in visited:
            continue
        visited.add(current)
        visited_order.append(current)

        neighbors = [n for n in G.neighbors(current) if n not in visited]
        current_edges = [(current, n) for n in neighbors]

        # Update distances for neighbors
        for n in neighbors:
            if n not in distance:
                distance[n] = distance[current] + 1

        queue.extend(neighbors)
        steps.append(
            (
                set(visited),
                list(queue),
                current_edges,
                distance.copy(),
                visited_order.copy(),
            )
        )
    return steps


# Graph setup
G = nx.erdos_renyi_graph(n=10, p=0.3, seed=42)
start_node = list(G.nodes)[0]
pos = nx.spring_layout(G, seed=42)
steps = bfs_steps_enhanced(G, start_node)

fig, ax = plt.subplots(figsize=(10, 8))
plt.axis("off")

# Legend
legend_elements = [
    patches.Patch(facecolor="orange", edgecolor="black", label="Visited"),
    patches.Patch(facecolor="lightgreen", edgecolor="black", label="In Queue"),
    patches.Patch(facecolor="lightblue", edgecolor="black", label="Unvisited"),
    patches.Patch(facecolor="red", edgecolor="black", label="Processed Edge"),
]
ax.legend(handles=legend_elements, loc="upper right", fontsize=10)


def update_enhanced(frame):
    ax.clear()
    plt.axis("off")
    visited_nodes, current_queue, edges_processed, distances, visited_order = steps[
        frame
    ]

    # Node colors and sizes
    current_node = visited_order[-1] if len(visited_order) > 0 else None
    node_colors = [
        (
            "orange"
            if node in visited_nodes
            else "lightgreen" if node in current_queue else "lightblue"
        )
        for node in G.nodes()
    ]
    node_sizes = [1000 if node == current_node else 800 for node in G.nodes()]

    # Edge colors and widths
    edge_colors = []
    edge_widths = []
    for u, v in G.edges():
        if (u, v) in edges_processed or (v, u) in edges_processed:
            edge_colors.append("red")
            edge_widths.append(3.0)
        else:
            edge_colors.append("gray")
            edge_widths.append(1.0)

    # Draw graph
    nx.draw_networkx_nodes(G, pos, ax=ax, node_color=node_colors, node_size=node_sizes)
    nx.draw_networkx_edges(G, pos, ax=ax, edge_color=edge_colors, width=edge_widths)
    nx.draw_networkx_labels(G, pos, ax=ax, font_size=10)

    # Add distance labels
    for node in G.nodes():
        if node in distances:
            x, y = pos[node]
            ax.text(
                x,
                y + 0.06,
                s=str(distances[node]),
                ha="center",
                va="bottom",
                fontsize=9,
                color="darkred",
            )

    # Queue visualization
    ax.text(0.1, -0.05, "Queue:", transform=ax.transAxes, fontsize=10, ha="left")
    for i, node in enumerate(current_queue):
        circle = patches.Circle(
            (0.1 + i * 0.05, -0.1),
            radius=0.02,
            facecolor="lightgreen",
            edgecolor="black",
            transform=ax.transAxes,
        )
        ax.add_patch(circle)
        ax.text(
            0.1 + i * 0.05,
            -0.1,
            str(node),
            ha="center",
            va="center",
            fontsize=8,
            transform=ax.transAxes,
        )

    # Title and progress
    ax.set_title(f"BFS Step {frame+1}: Visiting Node {current_node}", fontsize=14)
    progress = patches.Rectangle(
        (0, 1.05),
        width=(frame + 1) / len(steps),
        height=0.03,
        transform=ax.transAxes,
        facecolor="green",
    )
    ax.add_patch(progress)

    # Add legend manually
    ax.legend(handles=legend_elements, loc="upper right", fontsize=10)


# Create animation
ani_enhanced = animation.FuncAnimation(
    fig, update_enhanced, frames=len(steps), interval=1500, repeat=False
)

# Save the animation as an MP4 file
ani_enhanced.save("bfs_animation.mp4", writer="ffmpeg", fps=1)

plt.tight_layout()
plt.show()
