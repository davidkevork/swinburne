using System;

namespace SwinAdventure.src
{
    public interface IHaveInventory
    {
        GameObject Locate (string id);

        string Name
        {
            get;
        }
    }
}
